// Problem: E - Sightseeing Tour
// Contest: AtCoder - AtCoder Beginner Contest 369
// URL: https://atcoder.jp/contests/abc369/tasks/abc369_e
// Memory Limit: 1024 MB
// Time Limit: 4000 ms

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
const int mx = 410;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int f[mx][mx];
  
void solve() {  
    int n,m;cin>>n>>m;
    vector<vector<int>> edges;
    memset(f,0x3f,sizeof(f));
    for (int i = 0; i < n; i++) {
        f[i][i] = 0;
    }
    rep(i,1,m){
    	int x,y,w;cin>>x>>y>>w;x--,y--;
    	edges.pb({x,y,w});
    	f[x][y] = min(f[x][y],w);
    	f[y][x] = min(f[y][x],w);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    int q;cin>>q;
    rep(i,1,q){
    	int k;cin>>k;
    	vector<int> path(k);
    	rep(j,1,k){
    		cin>>path[j-1];
    		path[j-1]--;
    	}
    	int ans = LLONG_MAX;
    	do{
    		rep(j,0,(1<<k)-1){
    			int sum = 0,cur = 0;
    			rep(t,0,k-1){
    				sum+=edges[path[t]][2];
    				if((j>>t)&1){
    					sum+=f[cur][edges[path[t]][0]];
    					cur = edges[path[t]][1];
    				}else{
    					sum+=f[cur][edges[path[t]][1]];
    					cur = edges[path[t]][0];
    				}
    			}
    			sum += f[cur][n-1];
    			ans = min(ans,sum);
    		}
    	}while(next_permutation(path.begin(),path.end()));
    	cout<<ans<<endl;
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
