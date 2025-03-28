// Problem: F - Blocked Roads
// Contest: AtCoder - AtCoder Beginner Contest 218
// URL: https://atcoder.jp/contests/abc218/tasks/abc218_f
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


void solve() {  
    int n,m;cin>>n>>m;
    map<pii,int> p2i;
    map<int,pii> i2p;
    vector<set<int>> g(n);
    rep(i,0,m-1){
    	int u,v;cin>>u>>v;
    	u--,v--;
    	p2i[{u,v}] = i;
    	i2p[i] = {u,v};
    	g[u].insert(v);
    }
    vector<pii> dis(n,{mx,-1});
    auto bfs = [&](int start,int end)->set<int>{
    	fill(dis.begin(),dis.end(),pii{mx,-1});
    	priority_queue<pii,vector<pii>,greater<>> q;
    	dis[start] = {0,-1};
    	q.push({0,start});
    	set<int> res;
    	while(!q.empty()){
    		auto [d,x] = q.top();q.pop();
    		if(d>dis[x].first) continue;
    		if(x==end){
    			while(dis[x].second!=-1){
    				auto y = dis[x].second;
    				res.insert(p2i[{y,x}]);
    				x = y;
    			}
    			return res;
    		}
    		for(auto y:g[x]){
    			if(d+1<dis[y].first){
    				dis[y].first = d+1;
    				dis[y].second = x;
    				q.push({dis[y].first,y});
    			}
    		} 
    	}
    	res.insert(-1);
    	return res;
    };
    auto path = bfs(0,n-1);
    int ans = (dis[n-1].first==mx?-1:dis[n-1].first);
    rep(i,0,m-1){
    	if(path.contains(i)){
    		auto [u,v] = i2p[i];
    		g[u].erase(v);
    		auto res = bfs(0,n-1);
    		if(res.contains(-1)){
    			cout<<-1<<endl;
    		}else{
    			cout<<dis[n-1].first<<endl;
    		}
    		g[u].insert(v);
    	}else{
    		cout<<ans<<endl;
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
