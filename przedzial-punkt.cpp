#include<bits/stdc++.h>
using namespace std;

const int N = 8;
int tab[N] = {1, 5, 2, 3, 1, 7, 8, 3};
vector<pair<int, int>>tree(2*N);

void insert(int i, int l, int r, int a, int b, int value, int time) {
    if(l>=a && r<=b) {
        tree[i] = make_pair(value, time);
        return;
    }
    int mid = (l+r)/2;
    if(a<=mid) insert(i*2, l, mid, a, b, value, time);
    if(b>mid) insert(i*2+1, mid+1, r, a, b, value, time);
    return;
}

int query(int x) {
    int ans=0, i=x;
    while(x>=1){
        if(tree[x].second>ans) {
            i = x;
            ans = tree[x].second;
        }
        x/=2;
    }
    return tree[i].first;   
}

int main() {
    //preprocessing drzewa
    for(int i=0; i<N; i++) 
        tree[i+N] = make_pair(tab[i],0);
    for(int i=0; i<(int)tree.size(); i++) 
        cout<<tree[i].first << " "<<tree[i].second<<"\n";
    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        bool a;
        cin >> a;
        if(a) {
            int x, y, v;
            cin >> x >> y >> v;
            insert(1, 1, N, x, y, v, i+1);
        } else {
            int a;
            cin >> a;
            cout<<query(a+N-1)<<"\n";
        }
    }
    return 0;
}