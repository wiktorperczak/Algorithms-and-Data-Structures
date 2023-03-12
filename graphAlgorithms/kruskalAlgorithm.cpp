//Algorytm służący do znajdowania minimalnego drzewa rozpinającego.
//Sortuje on krawędzie rosnąco, a następnie sprawdza je po kolei, 
//czy ich wierzchołki nie mają takiego samego rodzica, 
//jeśli nie to dodaje krawędź do drzewa i zwiększa koszt.

#include <bits/stdc++.h>
using namespace std;

vector<int> parent, size;

int Find(int v) {
    if(parent[v] == v)
        return v;
    return parent[v] = Find(parent[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    if(size[a] > size[b])
        swap(a, b);
    parent[a] = parent[b];
    size[b] += size[a];
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& e) {
        return weight < e.weight;
    }
};

int main() {

    int n, cost = 0;
    parent.resize(n);
    size.resize(n);
    
    vector<Edge> edges, results;
    sort(edges.begin(), edges.end());

    for(Edge e : edges) {
        if(Find(e.u) != Find(e.v)) {
            cost += e.weight;
            Union(e.u, e.v);
            results.push_back(e);
        }
    }

    return 0;
}