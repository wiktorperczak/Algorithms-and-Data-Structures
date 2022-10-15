// służy do znajdowania mody na przedziałach offline. Sortujemy przedziały zapytań po
// bloku pierwistkowym wartości lewej i po wartości prawej. Potem odpowiadamy na zapytanie 
// i przesuwamy odpowiednio lewy koniec i prawy koniec.

#include <bits/stdc++.h>
using namespace std;

int block;

struct Query {
    int l, r, id;
    bool operator<(Query other) {
        return make_pair(l/block, r) < make_pair(other.l/block, other.r);
    }
};

vector<int> tab;
vector<Query> queries;
map<int, int> mp;
set<pair<int, int>> st;

void add(int x) {
    set<pair<int, int>>::iterator it;
    it = st.find({tab[x], mp[tab[x]]});
    if(it != st.end())
        st.erase(*it);
    mp[tab[x]]++;
    st.insert({tab[x], mp[tab[x]]});
}

void remove(int x) {
    set<pair<int, int>>::iterator it;
    it = st.find({tab[x], mp[tab[x]]});
    if(it != st.end())
        st.erase(*it);
    mp[tab[x]] = max(0, mp[tab[x]]-1);
    if(mp[tab[x]] != 0)
        st.insert({tab[x], mp[tab[x]]});
}

vector<int> mo(int n) {
    vector<int> ans(queries.size());
    int L = 1, R = n;
    for(auto q : queries) {
        while(L < q.l) {
            remove(L);
            L++;
        }
        while(L > q.l) {
            L--;
            add(L);
        }
        while(R < q.r) {
            R++;
            add(R);
        }
        while(R > q.r) {
            remove(R);
            R--;
        }
        ans[q.id] = st.begin()->second; //powinienem się tu iterować od początku aż do
        //wartości mniejszej od początkowej (bo mod może być kilka)
    }
    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;
    block = sqrt(n);
    tab.resize(n+1);
    queries.resize(q);
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    for(int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
    }
    sort(queries.begin(), queries.end());
    for(int i = 1; i <= n; i++) {
        if(mp.find(tab[i]) != mp.end())
            mp[tab[i]]++;
        else mp.insert({tab[i], 1});
    }
    vector<int> ans = mo(n);
    for(auto i : ans)
        cout << i << "\n";
    return 0;
}