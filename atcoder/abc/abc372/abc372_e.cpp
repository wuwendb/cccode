// Problem: E - K-th Largest Connected Components
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Autumn (AtCoder Beginner Contest 372)
// URL: https://atcoder.jp/contests/abc372/tasks/abc372_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
class dsu {
public:
    vector<int> pa, size;
    vector<vector<int>> st;
    explicit dsu(int n) : pa(n), size(n, 1),st(n) {
        iota(pa.begin(), pa.end(), 0);
    	for(int i=0;i<n;i++) st[i].pb(i);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) {
            swap(x, y);
        }
        pa[y] = x;
        size[x] += size[y];
        st[x].insert(st[x].end(),st[y].begin(),st[y].end());
        ranges::sort(st[x],greater<>());
        if(st[x].size()>10) st[x].resize(10);
    }
    int find(int x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }
};
  
void solve() {  
    int n,q;cin>>n>>q;
    dsu dsu(n);
    rep(i,1,q){
    	int op;cin>>op;
    	if(op==1){
    		int u,v;cin>>u>>v;u--;v--;
    		dsu.unite(u,v);
    	}else{
    		int v,k;cin>>v>>k;v--;
    		auto st = dsu.st[dsu.find(v)];
    		if(st.size()<k) cout<<-1<<endl;
			else cout<<st[k-1]+1<<endl;
    	}
    }
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    // cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
