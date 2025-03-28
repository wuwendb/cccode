// Problem: F - Range Connect MST
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2024#2 (AtCoder Beginner Contest 364)
// URL: https://atcoder.jp/contests/abc364/tasks/abc364_f
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

struct dsu {  
    vector<int> pa, size;  
    explicit dsu(int n) : pa(n), size(n, 1) {  
        iota(pa.begin(), pa.end(), 0);  
    }  
    int find(int x) {
        while (x != pa[x]) {
            x = pa[x] = pa[pa[x]];
        }
        return x;
    }
    bool merge(int x, int y) {  
        x = find(x);  
        y = find(y);  
        if (x == y) return false;  
        pa[y] = x;  
        size[x] += size[y];  
        return true;
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
    vector<array<int,3>> g;
    rep(i,1,q){
    	int l,r,c;cin>>l>>r>>c;l--;
    	g.pb({l,r,c});
    }
    ranges::sort(g,[](auto& a,auto& b){
    	return a[2]<b[2];
    });
    i64 ans = 0;
    dsu dsu(n);
    for(auto& [l,r,c]:g){
    	ans += c;
    	for(int x=dsu.find(l);x<r-1;x=dsu.find(x)){
    		dsu.merge(x+1,x);
    		ans+=c;
    	}
    }
    if(dsu.setSize(0)==n){
    	cout<<ans<<endl;
    } else{
    	cout<<-1<<endl;
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
