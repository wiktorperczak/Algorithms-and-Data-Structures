#include <bits/stdc++.h>
using namespace std;

vector<int> P;

void prefixSuffix(string s, int n) {
    for(int i = 1; i <= n; i++){
        int j = P[i-1];
        while(j > 0 && s[i] != s[j])
            j = P[j-1];
        P[i] = j;
        if(s[i] == s[j])
            P[i]++;
    }
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    P.resize(n, 0);
    prefixSuffix(s, n);
    for(auto i : P)
        cout << i << " ";
    cout << "\n";
    return 0;
}