// Hashe pozwalają w czasie O(1) porównywać słowa. Tworzy się je w ten sposób:
// każdą kolejną literkę słowa mnoży się przez kolejną potęgęwybranej liczby pierwszej
// większej od liczby wykorzystywanych znaków ( dla alfabetu to mże być np. 29).
// Używa się modulo, bo liczby szybko przekorczyłyby limit.
// Aby porównywać podsłowa słowa s w czasie O(n) (tyle zabiera precomputing)
// tworzy się tablice zawierająca hashe prefiksów słowa, a żeby sprawdzić czy podsłowa są równe
// wykorzystuje się wzór: podsłowo - (a, b), podsłowo - (c, d)
// (a, b) = powerP[c] * prefix[b] - prefix[a-1] (odpowiednio trzeba mod wstawić)
// (c, d) = powerP[a] ( prefix[d] - prefix[c-1]) (odpowiednio trzbea mod wstawić)
// Jeżeli te dwie liczby są równe to słowa są równe
// Żeby osiągnąć większą skuteczność hashy można zastosować podwójne hashowanie,
// czyli użyć dwóch różnych P

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll P = 29, M = 1e9 + 7;
vector<ll> pPower;

void computePower(ll n) {
    pPower[0] = 1;
    for(ll i = 1; i < n; i++)
        pPower[i] = (pPower[i-1] * P) % M;
}

int main() {
    string s;
    cin >> s;
    ll len = s.size();
    vector<ll> prefixHash(len+1, 0);
    pPower.resize(len);
    computePower(len);
    
    for(ll i = 1; i <= len; i++)
        prefixHash[i] = (prefixHash[i-1] + (s[i-1] - 'a' + 1) * pPower[i-1]) % M;
    int a = 0, b = 3, c = 5, d = 8;
    cout << "Przedział (a, b): " << (pPower[c] * ((M + prefixHash[b+1] - prefixHash[a]) % M)) % M << "\n";
    cout << "Przedzial (c, d): " << (pPower[a] * ((M + prefixHash[d+1] - prefixHash[c]) % M)) % M << "\n";
    return 0;
}