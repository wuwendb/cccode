// Problem: E - Clique Connect
// Contest: AtCoder - AtCoder Beginner Contest 352
// URL: https://atcoder.jp/contests/abc352/tasks/abc352_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= int(b); ++i)  
#define rev(i, a, b) for (int i = int(a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using namespace std;  

const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
struct DSU {
    std::vector<int> f, siz;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
	//y->x
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};
  
void solve() {  
    int n,m;cin>>n>>m;
    DSU dsu(n);
    vector<vector<int>> a;
    vector<int> cost(m);
    vector<int> ind(m);
    iota(ind.begin(),ind.end(),0);
    rep(i,1,m){
    	int k;cin>>k>>cost[i-1];
    	vector<int> tmp;
    	rep(i,0,k-1){
    		int x;cin>>x;x--;
    		tmp.pb(x);
    	}
    	a.pb(tmp);
    }
    ranges::sort(ind,[&](auto i,auto j){
    	return cost[i]<cost[j];
    });
    i64 ans = 0;
    rep(i,0,m-1){
    	auto v = a[ind[i]];
    	auto x = v[0];
    	for(auto y:v){
    		if(dsu.merge(x,y)){
    			ans+=cost[ind[i]];
    		}
    	}
    }
    if(dsu.size(0)==n) cout<<ans<<endl;
    else cout<<-1<<endl;
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
    return 0;  
}
