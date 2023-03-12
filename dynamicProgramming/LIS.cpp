// longest increasing subsequence O(log(n)*n)
// W tablicy dp[i] trzymam największy wynik dla ciągu długości i zawierający a[i].
// W t[a[i]] = dp[i] dla każdje wartości występującej w ciągu trzymam 
// najdłuższy podciąg kończący się na a[i]. Znalezienie dp[i] sprowadza się
// więc do znalezienia max na przedziale t[0] ... t[a[i]-1] + 1.
// Max na przedziale trzymam w fenwick tree.
// Jeżeli wartości ciągu przekraczają n to należy je przeskalować.

#include <bits/stdc++.h>
using namespace std;

constexpr int C = (1 << 4);
int tree[C] = {0};
vector<int> a, dp, t;

void update(int x, int val) {
    while(x < C) {
        tree[x] = max(tree[x], val);
        x += (x & (-x));
    }
}

int maxOnPrefix(int x) {
    int res = 0;
    while(x != 0) {
        res = max(res, tree[x]);
        x -= (x & (-x));
    }
    return res;
}

int main() {
    int n, ans = 0;
    cin >> n;
    a.resize(n);
    dp.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        int best = maxOnPrefix(a[i]-1);
        dp[i] = best + 1;
        ans = max(ans, dp[i]);
        update(a[i], dp[i]);
    }
    cout << ans << "\n";
    return 0;
}