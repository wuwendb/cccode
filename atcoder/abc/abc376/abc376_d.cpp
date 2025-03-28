// Problem: D - Cycle
// Contest: AtCoder - AtCoder Beginner Contest 376
// URL: https://atcoder.jp/contests/abc376/tasks/abc376_d
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
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int N = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
vector<int> g[N];

  
void solve() {  
    int n,m;cin>>n>>m;
    rep(i,1,m){
    	int a,b;cin>>a>>b;a--;b--;
    	if(b==0){
    		b=n;
    	}
    	g[a].pb(b);
    }
    int ans = INT_MAX;
    vector<int> dis(n+1, INT_MAX);
        dis[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            if (x == n) { // 计算出从起点到终点的最短路长度
                cout<<d<<endl;return;
            }
            if (d > dis[x]) { // x 之前出堆过，无需更新邻居的最短路
                continue;
            }
            for (auto &y : g[x]) {
                if (d + 1 < dis[y]) {
                    dis[y] = d + 1; // 更新最短路长度
                    pq.push({dis[y], y});
                }
            }
        }
    cout<<-1<<endl;
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
