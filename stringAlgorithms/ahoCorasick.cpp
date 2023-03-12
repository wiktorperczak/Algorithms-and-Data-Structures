#include <bits/stdc++.h>
using namespace std;

struct Node {
    int suf, next[2];
    bool state;
    
    Node() {
        next[0] = -1;
        next[1] = -1;
        suf = 0;
        state = false;
    }
};

void addString(string const& pat, vector<Node>& T) {
    int v = 1;
    for(auto c : pat) {
        int t = c - '0';
        if(T[v].next[t] == -1) {
            T[v].next[t] = T.size();
            T.emplace_back();
        }
        v = T[v].next[t];
    }
    T[v].state = true;
}

void bfs(vector<Node>& T) {
    queue<int> q;
    q.push(1);
    
    while(!q.empty()) {
        int u = q.front();  
        q.pop();
        cout << "U: " << u << "\n";
        int f = T[u].suf;

        for(int i = 0; i < 2; i++) {
            int& v = T[u].next[i];
            if(v >= 0) {
                q.push(v);
                T[v].suf = T[f].next[i];
                if(T[T[f].next[i]].state) {
                    T[v].state = true;
                    cout << v << " TAK\n";
                }
            } 
            else
                v = T[f].next[i];
        }
    }
}

int main() {
    /* ios::sync_with_stdio(0);
    cin.tie(0); */

    int n;
    string s;
    cin >> n >> s;
    vector<string> pat(n);
    for(int i = 0; i < n; i++)
        cin >> pat[i];
    
    vector<Node> T(2);
    T[0].next[0] = 1; T[0].next[1] = 1;
    for(auto t : pat)
        addString(t, T);
    /* for(auto t : T) {
        cout << t.next[0] << " " << t.next[1] << "\n";
    }
    cout << "\n" << "\n"; */
    
    bfs(T);
    for(auto t : T) {
        cout << t.next[0] << " " << t.next[1] << " " << t.suf << " " << t.state << "\n";
    }

    return 0;
}