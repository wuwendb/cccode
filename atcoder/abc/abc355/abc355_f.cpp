// Problem: F - MST Query
// Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2024（AtCoder Beginner Contest 355)
// URL: https://atcoder.jp/contests/abc355/tasks/abc355_f
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
	int n,q;cin>>n>>q;
	vector dsu(10,DSU(n));
    vector<int> cnt(10,n);
    rep(i,1,n-1){
    	int a,b,c;cin>>a>>b>>c;a--,b--,c--;
    	rep(j,c,9){
    		cnt[j] -= dsu[j].merge(a,b);
    	}
    }
    rep(i,1,q){
    	int u,v,w;cin>>u>>v>>w;u--,v--,w--;
    	rep(j,w,9){
    		cnt[j] -= dsu[j].merge(u,v);
    	}
    	int cur = n;
	    int ans = 0;	
    	rep(j,0,9){
    		ans += (j+1)*(cur-cnt[j]);
    		cur = cnt[j];  
    	}
	    cout<<ans<<endl;
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
    return 0;  
}
