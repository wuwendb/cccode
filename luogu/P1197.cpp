// Problem: P1197 [JSOI2008] 星球大战
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1197
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
int ans;
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
        ans++;
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
    int n,m;cin>>n>>m;
    ans = 0;
    dsu d(n);
    vector<vector<int>> g(n);
    rep(i,1,m){
    	int x,y;cin>>x>>y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    int k;cin>>k;
    vector<pair<int,int>> po;
    set<int> vis; 
    rep(i,1,k){
    	int x;cin>>x;
    	po.emplace_back(x,i);
    	vis.insert(x);
    }
    rep(i,0,n-1){
    	if(!vis.count(i)){
    		for(auto j:g[i]){
    			if(!vis.count(j)){
    				d.unite(i,j);
    			}
    			
    		}
    	}
    }
    vector<int> revans;
    int livesplanets = n-k-ans;
    revans.push_back(livesplanets);
    ranges::sort(po,[](auto p1,auto p2){
    	return p1.second>p2.second;
    });
    rep(i,0,k-1){
    	ans = 0;
    	livesplanets++;
    	auto [x,ind] = po[i];
	    vis.erase(x);
    	for(auto y:g[x]){
    		if(!vis.count(y)){
	    		d.unite(x,y);			
    		}
    	}
    	livesplanets -= ans;
    	revans.push_back(livesplanets);
    }
    rev(i,k,0){
    	cout<<revans[i]<<endl;
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
