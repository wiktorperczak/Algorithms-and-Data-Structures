#include<bits/stdc++.h>
using namespace std;
 
struct dsu {
	vector<int>parent, size;
 
	dsu(int n=0) {
		parent.resize(n+1);
		size.resize(n+1,1);
 
		for(int i=1; i<=n; i++)
			parent[i] = i;
	}
 
	int Find(int x) {
		if(x != parent[x])
			return Find(parent[x]);
		return parent[x];
	}
 
	void Union(int a, int b) {
		a = Find(a); b = Find(b);
		if(a==b) return;
		if(size[a] > size[b])
			swap(a, b);
		parent[a] = parent[b];
		size[b] += size[a];
	}
};

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
 
	int n;
	cin >> n;
 
	dsu d(n);
    
    int x = 1;
    int y = 2;
	int z = 3;
    d.Union(x, y);
    cout << "X: " << d.Find(x) << ", Y: " << d.Find(y) << ", Z: " << d.Find(z);
	
	return 0;
}