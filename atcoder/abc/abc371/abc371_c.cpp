// Problem: C - Make Isomorphic
// Contest: AtCoder - AtCoder Beginner Contest 371
// URL: https://atcoder.jp/contests/abc371/tasks/abc371_c
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
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int a[8][8];
  
void solve() {  
    int n,mg,mh;cin>>n>>mg;
    vector<vector<int>> g(n,vector<int>(n,0));
    vector<vector<int>> h(n,vector<int>(n,0));
    rep(i,1,mg){
    	int u,v;cin>>u>>v;u--,v--;
    	g[u][v]=1;
    	g[v][u]=1;
    }
    cin>>mh;
    rep(i,1,mh){
    	int u,v;cin>>u>>v;u--,v--;
    	h[u][v]=1;
    	h[v][u]=1;
    }
    rep(i,0,n-1){
    	rep(j,i+1,n-1){
    		cin>>a[i][j];
    	}
    }
    vector<int> f(n);
    iota(f.begin(),f.end(),0);
    int ans = LLONG_MAX;
    do{
    	int cost =0;
    	rep(i,0,n-1){
    		rep(j,i+1,n-1){
    			if(h[i][j]!=g[f[i]][f[j]]){
    				cost += a[i][j];
    			}
    		}
    	}
    	ans = min(ans,cost);
    }while(ranges::next_permutation(f).found);
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
