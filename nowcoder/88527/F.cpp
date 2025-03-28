// Problem: 小美想跑步
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88527/F
// Memory Limit: 524288 MB
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
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
vector<pii> g[mx],g1[mx];
int dis[mx],dis1[mx];
void dijstra(){
	memset(dis,0x3f,sizeof(dis));
    dis[1] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, 1);
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
}  
void dijstra1(){
	memset(dis1,0x3f,sizeof(dis1));
    dis1[1] = 0;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        auto [d, x] = pq.top();
        pq.pop();
        if (d > dis1[x]) {
            continue;
        }
        for (auto &[y, w] : g1[x]) {
            if (d + w < dis1[y]) {
                dis1[y] = d + w; 
                pq.push({dis1[y], y});
            }
        }
    }
}  
void solve() {  
    int n,m;cin>>n>>m;
    rep(i,1,m){
    	int x,y,z;cin>>x>>y>>z;
    	g[x].eb(y,z);
    	g1[y].eb(x,z);
    }
    dijstra();
    dijstra1();
	int ans = 0;
    rep(i,2,n){
    	ans+=dis[i]+dis1[i];
    }
    cout<<ans<<endl;
    
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
