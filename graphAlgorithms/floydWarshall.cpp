#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> path(n+1, vector<int> (n+1, INT_MAX));

void floydWarshall() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++)
                path[j][k] = min(path[j][k], path[j][i] + path[i][k]);
        }
    }
}

int main() {
    for(int i = 1; i <= n; i++) {
        for(auto j : graph[i])
            path[i][j.first] = j.second;
    }
}