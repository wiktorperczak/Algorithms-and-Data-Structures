#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int tab[N];

int binary(int x, int l, int r) {
    int mid = (l+r)/2;
        
    if(tab[mid]>x)
        return binary(x, l, mid-1);
    else if(tab[mid] < x)
        return binary(x, mid+1, r);
    else
        return mid;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<N; i++)
        cin >> tab[i];

    sort(tab, tab+N);

    int q;
    cin >> q;

    for(int i=0; i<q; i++) {
        int x;
        cin >> x;
        cout << binary(x, 0, N-1) << "\n";
    }
}