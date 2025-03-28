// Problem: D - Shortest Path 3
// Contest: AtCoder - Toyota Programming Contest 2024#7（AtCoder Beginner Contest 362）
// URL: https://atcoder.jp/contests/abc362/tasks/abc362_d
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

  
void solve() {  
    int N,M;cin>>N>>M;
    vector<i64> a(N);
    rep(i,0,N-1) cin>>a[i];
    vector<vector<pair<int,i64>>> g(N);
    rep(i,1,M){
    	int u,v;i64 b;cin>>u>>v>>b;u--,v--;
    	g[u].pb({v,b+a[v]});
    	g[v].pb({u,b+a[u]});
    }
    vector<i64> dis(N,1e18);
    dis[0] = a[0];
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
    pq.emplace(a[0], 0);
    while (!pq.empty()) {
        auto [d, x] = pq.top();
        pq.pop();
        if (d > dis[x]) { 
            continue;
        }
        for (auto &[y, w] : g[x]) {
            if (d + w < dis[y]) {
                dis[y] = d + w;
                pq.push({dis[y], y});
            }
        }
    }
    rep(i,1,N-1){
    	cout<<dis[i]<<" \n"[i==N-1];
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
