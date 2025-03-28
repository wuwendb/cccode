// Problem: P4185 [USACO18JAN] MooTube G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4185
// Memory Limit: 125 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
struct edge{
	int p,q,r;
	bool operator<(const edge &a) const{
		return a.r<r;
	}
};
struct query{
	int k,v,i;
	bool operator<(const query &a) const{
		return a.k<k;
	}
};
class dsu {  
    vector<int> pa, size;  
public:  
    explicit dsu(int n) : pa(n), size(n, 1) {  
        iota(pa.begin(), pa.end(), 0);  
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
    }  
    int find(int x) {  
        return pa[x] == x ? x : pa[x] = find(pa[x]);  
    }  
    bool sameSet(int x, int y) {  
        return find(x) == find(y);  
    }  
    int setSize(int x) {  
        return size[find(x)];  
    }  
};
void solve() {  
    int n,q;cin>>n>>q;
    vector<edge> g;
    dsu d(n+1);
    rep(i,1,n-1){
    	int p,q,r;cin>>p>>q>>r;
    	g.emplace_back(p,q,r);
    }
    sort(all(g));
    vector<query> qs;
    rep(i,1,q){
    	int k,v;cin>>k>>v;
    	qs.emplace_back(k,v,i-1);
    }
    sort(all(qs));
    vector<int> ans(q);
    int j =0;
    rep(i,0,q-1){
    	int k = qs[i].k,v = qs[i].v;
    	for(;j<n-1;j++){
    		if(g[j].r>=k){
    			d.unite(g[j].p,g[j].q);
    		}else{
    			break;
    		}
    	}
    	ans[qs[i].i] = d.setSize(v)-1;
    }
    rep(i,0,q-1){
    	cout<<ans[i]<<endl;
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
