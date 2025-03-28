// Problem: E - Tree and Hamilton Path 2
// Contest: AtCoder - Denso Create Programming Contest 2024（AtCoder Beginner Contest 361）
// URL: https://atcoder.jp/contests/abc361/tasks/abc361_e
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
    int n;cin>>n;
    vector<vector<pair<int,i64>>> g(n);
    i64 sum = 0;
    rep(i,1,n-1){
    	int a,b;i64 c;cin>>a>>b>>c;a--;b--;
    	g[a].pb({b,c});
    	g[b].pb({a,c});
    	sum+=c;
    }
    auto dijstra = [&](int start){
    	vector<i64> dis(n, 1e18);
        dis[start] = 0;
        priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<>> pq;
        pq.emplace(0, start);
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
        return dis;
    };
    auto dis = dijstra(0);
    auto u = max_element(dis.begin(),dis.end())-dis.begin();
    dis = dijstra(u);
    auto len = ranges::max(dis);
    cout<<2*sum-len<<endl;
    
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
