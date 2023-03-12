// z podanego zbioru liczb szukamy liczby podciągów, które mają
// wszystkie prefiksy nieujemne
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end()); // w ten sposób każdej liczbie przyporządkowuje indeks w masce 
    // bitowej, dzięki temu jej rozmiar to maksymalnie n
    
    // rozważamy wszystkie podzbiory i DP[x] oznacza maks dla ciagu x
    // jeżeli suma w danym ciągu < 0 to wiemy, że odp = 0, inaczej dodajemy
    // wszystkie ciągi bez jednej z liczb naszego ciągu 
    // np. DP[7 -2 1 3] = DP[{-2, 1, 7}] + DP[{-2, 3, 7}] + DP[{-2, 1, 3}] + DP[{1, 3, 7}]
    vector<int> DP((1 << n), 0);
    DP[0] = 1;
    for(int i = 1; i < (1 << n); i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j))
                sum += v[j]; 
        }
        if(sum >= 0) {
            for(int j = 0; j < n; j++) {
                if(i & (1 << j))
                    DP[i] += DP[i ^ (1 << j)];
            }
        }
    }
    cout << DP[(1 << n) - 1] << "\n";
    return 0;
}