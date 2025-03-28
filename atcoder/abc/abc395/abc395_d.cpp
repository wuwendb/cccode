// Problem: D - Pigeon Swap
// Contest: AtCoder - AtCoder Beginner Contest 395
// URL: https://atcoder.jp/contests/abc395/tasks/abc395_d
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
    std::vector<int> f, nest, now;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        nest.resize(n);
        std::iota(nest.begin(), nest.end(), 0);
        now.resize(n);
        std::iota(now.begin(), now.end(), 0);
    }

    void merge(int x, int y) {
        f[y] = x;
    }
    
    void change(int x, int y){
    	swap(nest[now[x]],nest[now[y]]);
    	swap(now[x],now[y]);
    }
	

};

void solve() {
	int N,Q;cin>>N>>Q;  
	DSU dsu(2*N);
	rep(i,0,N-1){
		dsu.merge(i+N,i);
	}
    rep(i,0,Q-1){
    	int op,a;cin>>op>>a;a--;
    	if(op==1){
    		int b;cin>>b;b--;
    		dsu.merge(dsu.now[b+N],a);
    	}else if(op==2){
    		int b;cin>>b;b--;
    		dsu.change(a+N,b+N);
    	}else{
    		cout<<dsu.nest[dsu.f[a]]-N+1<<endl;
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
    return 0;  
}
