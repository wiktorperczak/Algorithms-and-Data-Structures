#include<bits/stdc++.h>
using namespace std;

const int N = 8;
int tab[N] = {1, 5, 2, 3, 1, 7, 8, 3};
vector<int>tree(2*N);

void build(int i, int l, int r) {
    if(l>r) return;
    if(l==r) {
        tree[i] = tab[l];
        return ;
    }
    build(2*i, l, (l+r)/2);
    build(2*i+1, (l+r)/2+1, r);

    tree[i] = max(tree[i*2], tree[i*2+1]);
}

void insert(int i, int l, int r, int x, int value) {
    if(l==r) {
        tree[i] = value;
        return;
    }
    int mid = (l+r)/2;
    if(x<=mid) insert(i*2, l, mid, x, value);
    else insert(i*2+1, mid+1, r, x, value);

    tree[i] = max(tree[2*i], tree[2*i+1]);
}

int query(int i, int l, int r, int a, int b) {
    if(l>=a && r<=b)
        return tree[i];
    int mid = (l+r)/2, ans=0;
    if(a<=mid) ans = max(ans, query(i*2, l, mid, a, b));
    if(b>mid) ans = max(ans, query(i*2+1, mid+1, r, a, b));

    return ans;
}

int main() {
    build(1, 0, N-1);
    for(int i=0; i<(int)tree.size(); i++)
        cout<<tree[i] << " ";
    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        bool a;
        cin >> a;
        if(a) {
            int x, v;
            cin >> x >> v;
            insert(1, 1, N, x, v);
        } else {
            int a, b;
            cin >> a >> b;
            cout<<query(1, 1, N, a, b);
        }
    }
    return 0;
}