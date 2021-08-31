#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<int,int>>q;
    q.insert({0, s});
    while(!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    vector<int>d, p;
    int n, edges;
    cin >> n >> edges;
    adj.resize(n);

    for(int i=0; i<edges; i++) {
        int vertex1, vertex2, weight;
        cin >> vertex1 >> vertex2 >> weight;
        adj[vertex1-1].push_back(make_pair(vertex2-1, weight));
        adj[vertex2-1].push_back(make_pair(vertex1-1, weight));
    }
    
    dijkstra(0, d, p);

    for(int i=0; i<n; i++) {
        vector<int>path = restore_path(0, i, p);
        cout << d[i] << "\n";

        for(int j=0; j<(int)path.size(); j++)
            cout << path[j] << " ";
        cout << "\n";
    }
    return 0;
}