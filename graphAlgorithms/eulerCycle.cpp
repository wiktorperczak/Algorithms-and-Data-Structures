#include<bits/stdc++.h>
using namespace std;

const int n = 7;
int odw[n+1][n+1] = {0};
vector<vector<int>>g(n+1);
vector<int>stos;

void dfs(int x) {
    for(int i=0; i<(int)g[x].size(); i++) {
        cout<<"RAZ: "<<g[x][i]<<" "<<odw[x][g[x][i]]<<"\n";
        if(!odw[x][g[x][i]]) {
            odw[x][g[x][i]] = 1;
            odw[g[x][i]][x] = 1;
            dfs(g[x][i]);
            cout<<"DWA: "<<odw[x][g[x][i]]<<" "<<g[x][i]<<"\n";
            stos.push_back(g[x][i]);
        }
    }
}

int main() {
    for(int i=1; i<=n; i++) {
        int ile;
        cin>>ile;
        for(int j=0; j<ile; j++) {
            int a;
            cin>>a;
            g[i].push_back(a);
        }
    }
    dfs(1);
    cout<<"1 ";
    for(int i=(int)stos.size()-1; i>=0; i--)
        cout<<stos[i]<<" ";
    return 0;
}