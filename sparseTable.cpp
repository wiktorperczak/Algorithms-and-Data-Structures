#include<bits/stdc++.h>
using namespace std;

const int N=1000000, L=21;
int sparse[N][L];

//odpowiedz na zapytanie o max w przedzialach w O(1)
int query(int l, int r) {
	int length = r-l+1;
	int k = 31 - __builtin_clz(length);
	return max(sparse[l][k], sparse[r-(1<<k)+1][k]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	//getting input and preprocessing sparse table
	int n;
	cin >> n;
	vector<int>y(n);
	for(int i=0; i<n; i++) {
		int x;
		cin >> x >> y[i];
		sparse[i][0] = x;
	}	
	for(int i=1; i<L; i++) {
		for(int j=0; j+(1<<i)-1<n; j++)
			sparse[j][i] = max(sparse[j][i-1], sparse[j+(1<<(i-1))][i-1]);
	}
	
	//algorytm gasienicy
	int l=0, ans=1, len=1;
	for(int r=1; r<n; r++) {
		len++;
		while(l<n && query(l, r)>y[r]) {
			l++;
			len--;
		}
		ans = max(ans, len);
	}  
	cout<<ans;
	return 0;
}
