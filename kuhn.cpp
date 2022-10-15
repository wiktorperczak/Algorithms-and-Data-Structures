#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> match;
vector<bool> vis;

bool augment(int v) {    // znajduje ścieżkę rozszerzającą i zwraca, czy została znaleziona
    if (vis[v]) return false;
    vis[v] = true;
    for (auto u : graph[v]) {
        if (match[u] == -1 || augment(match[u])) { //jeżeli u nie ma matcha to tworzymy match u-v,
            match[u] = v;            // a jeśli już ma to sprawdzamy czy match[u] może znaleźć sobie nowego matcha
            match[v] = u;            // Jeżeli może to łączymy go z nim, a u z v.
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    while (true) {   // turbo matching
        vis.assign(n+1, false);
        bool any = false;
        for (int i = 1; i <= n; i++)   // wierzchołki {1..n}
            if (match[i] == -1 && augment(i)) any = true;
        if (!any) break;
    }
}