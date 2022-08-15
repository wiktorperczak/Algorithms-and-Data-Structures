#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int tab[N] = {6, 1, 5, 10, 12, 14, 7, 18, 3, 1};
vector<int>D(N+1, 0);

void update(int x, int w) {
    if(x>N) return;
    D[x] = D[x] + w;
    update(x+(x&(-x)), w);
}

int SUM(int x) {
    if(x==0) return 0;
    return D[x]+SUM(x-(x&(-x)));
}

int main() {
    for(int i=0; i<N; i++) {
        update(i+1, tab[i]);
    }
    int q;
    cin>>q;
    for(int j=0; j<q; j++) {
        bool a;
        cin >> a;
        int x;
        if(a) {
            int l, r;
            cin >> l >> r;
            cout << SUM(r)-SUM(l) <<"\n";
        } else {
            int x, w;
            cin >> x >> w;
            update(x, w);
        }
    }
    for(int i=0; i<=N; i++)
        cout<<D[i]<<" ";
    return 0;
}