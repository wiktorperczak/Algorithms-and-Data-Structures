#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 0;
vector<vector<int>> g;
vector<int> sub, cnt;
vector<bool> used;

void calculateSize(int v, int par) {
    for(auto w : g[v]) {
        if(w != par) {
            calculateSize(w, v);
            sub[v] += sub[w];
        }
    }
}

void calculateDistances(int v, int par, int dis, bool flag) {
    if(flag) cnt[dis]++;
    else cnt[dis]--;
    for(auto w : g[v]) {
        if(!used[w] && w != par)
            calculateDistances(w, v, dis+1, flag);
    }
}

void solve(int v, int par, int dis) {
    if(dis > k) return;
    ans += cnt[k-dis];
    for(auto w : g[v]) {
        if(!used[w] && w != par)
            solve(w, v, dis+1);
    }
}

int findCentroid(int v) {
    while(true) {
        bool isCentroid = true;
        for(auto w : g[v]) {
            if(!used[w] && sub[w] > n/2) {
                sub[v] -= sub[w];
                sub[w] = n;
                v = w;
                isCentroid = false;
                break;
            }
        }
        if(isCentroid) return v;
    }
}

void decompose(int v, int par) {
    int centroid = findCentroid(v);
    if(par == -1) par = centroid;

    calculateDistances(centroid, par, 0, 1);
    ans += cnt[k];
    for(auto w : g[centroid]) {
        if(!used[w]) {
            calculateDistances(w, centroid, 1, 0);
            solve(w, centroid, 1);
            calculateDistances(w, centroid, 1, 1);
        }
    }
    calculateDistances(centroid, par, 0, 0);

    used[centroid] = true;
    for(auto w : g[centroid]) {
        if(!used[w])
            decompose(w, centroid);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    g.resize(n+1);
    sub.resize(n+1, 0);
    cnt.resize(n+1, 0);
    used.resize(n+1, false);
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    decompose(1, -1);
    ans /= 2;
    cout << ans << "\n";
    return 0;
}

// 1.Znajdź centroid
// 2.Policz dla wszystkich ścieżek, które go zawierają:
//      a. Policz dis każdego wierzchołka od centroidu (poza tymi, które już były wcześniej centroidami)
//      b. Dodaj dis długości k do odp
//      c. Dla każdego poddrzewa usuwaj wszystkie dis między wierzchołkami danego poddrzewa i zliczaj odp (solve())
//      d. Usuń dis danego centroidu
// 3.Wywołaj się rekurencyjnie dla każdego poddrzewa