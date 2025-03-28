// Problem: E - Cables and Servers
// Contest: AtCoder - Japan Registry Services (JPRS) Programming Contest 2025#1 (AtCoder Beginner Contest 392)
// URL: https://atcoder.jp/contests/abc392/tasks/abc392_e
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
    vector<array<int,2>> edges;
    set<int> st;
    DSU dsu(n);
    rep(i,0,m-1){
    	int u,v;cin>>u>>v;u--,v--;
    	if(!dsu.merge(u,v)){
    		edges.pb({i,v});
    	}
    }
    rep(i,0,n-1){
    	st.insert(dsu.find(i));
    }
    cout<<st.size()-1<<endl;
    for(auto e:edges){
    	if(st.size()==1) break;
    	auto i = e[0],u = e[1];
    	auto it = st.begin();
    	if((*it)==dsu.find(u)){
    		it++;
    	}
    	dsu.merge(u,*it);
		cout<<i+1<<" "<<u+1<<" "<<(*it)+1<<endl;
		st.erase(it);
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
