#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> Graph;

void dfs(Graph const &g, vector<int> &st, vector<bool> &vis, int i) {
    if(vis[i]) return;
    vis[i] = true;
    for(auto v : g[i])
        dfs(g, st, vis, v);
    st.push_back(i);
}

void rdfs(Graph const &rg, vector<int> &scc, vector<int> &sccNum, int c, int i) {
    if(scc[i] != -1) return;
    scc[i] = c;
    sccNum[c]++;
    for(auto v : rg[i])
        rdfs(rg, scc, sccNum, c, v);
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n+1), rg(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    vector<int> st;
    vector<bool> vis(n+1, 0);
    for(int i = 1; i <= n; i++)
        dfs(g, st, vis, i);

    int count = 0;
    vector<int> scc(n+1, -1);
    vector<int> sccNum;
    while(!st.empty()) {
        int i = st.back();
        st.pop_back();
        if(scc[i] == -1) {
            sccNum.push_back(0);
            rdfs(rg, scc, sccNum, count++, i);
        }
    }
}