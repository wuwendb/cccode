// Problem: 小美想游泳
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88527/K
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
vector<pii> g[mx];
int dis[mx];
int s,t;
void dijstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<pii,vector<pii>,greater<>> pq;
	pq.emplace(0,s);
	while(!pq.empty()){
		auto [d,x] = pq.top();pq.pop();
		for(auto [y,w]:g[x]){
			if(max(dis[x],w)<dis[y]){
				dis[y] = max(dis[x],w);
				pq.emplace(dis[y],y);
			}
		}
	}
}
void solve() {  
    int n,m;cin>>n>>m;
    rep(i,1,m){
    	int u,v,a;cin>>u>>v>>a;
    	g[u].eb(v,a);
    	g[v].eb(u,a);
    }
    cin>>s>>t;
    dijstra();
    cout<<dis[t]<<endl;
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
