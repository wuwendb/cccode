// Problem: E - Flip Edge
// Contest: AtCoder - AtCoder Beginner Contest 395
// URL: https://atcoder.jp/contests/abc395/tasks/abc395_e
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
    int N,M,X;cin>>N>>M>>X;
    vector<vector<array<int,2>>> adj(N*2);
    rep(i,0,M-1){
    	int u,v;cin>>u>>v;u--,v--;
    	adj[u].pb({v,1});
    	adj[v+N].pb({u+N,1});
    }
    rep(i,0,N-1){
    	adj[i].pb({i+N,X});
    	adj[i+N].pb({i,X});
    }
    auto shortestPath = [&](int start, int end)->i64 {
	    // dis[i] 表示从起点 start 出发，到节点 i 的最短路长度
	    vector<i64> dis(adj.size(), LLONG_MAX);
	    dis[start] = 0;
	    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
	    pq.emplace(0, start);
	    while (!pq.empty()) {
	        auto [d, x] = pq.top();
	        pq.pop();
	        if (x == end) { // 计算出从起点到终点的最短路长度
	            return d;
	        }
	        if (d > dis[x]) { // x 之前出堆过，无需更新邻居的最短路
	            continue;
	        }
	        for (auto &[y, w] : adj[x]) {
	            if (d + w < dis[y]) {
	                dis[y] = d + w; // 更新最短路长度
	                pq.push({dis[y], y});
	            }
	        }
	    }
	    return -1; // 无法到达终点
	};
    cout<<min(shortestPath(0,N-1), shortestPath(0,2*N-1))<<endl;
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
