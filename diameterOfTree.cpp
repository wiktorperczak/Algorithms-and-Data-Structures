#include<bits/stdc++.h>
using namespace std;
    
int n,m, len=0, node;
vector<vector<int>>g;
vector<bool>odw;

void dfs(int x, int l) {
    if(l > len) {
        len = l;
        node = x;
    }
    odw[x] = true;
    for(int i=0; i<(int)g[x].size(); i++) {
        if(odw[g[x][i]] == false)
            dfs(g[x][i], l+1);
    }
}

int main() {
    cin >> n >> m;
    g.resize(n+1);
    odw.resize(n+1, 0);
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    fill(odw.begin(), odw.end(), 0);
    dfs(node, 0);
    cout << len;
    return 0;
}