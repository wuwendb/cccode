// Problem: D - Minimum Steiner Tree
// Contest: AtCoder - Hitachi Vantara Programming Contest 2024（AtCoder Beginner Contest 368）
// URL: https://atcoder.jp/contests/abc368/tasks/abc368_d
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

  
void solve() {  
    int n,k;cin>>n>>k;
    vector<vector<int>> g(n);
    vector<int> inde(n);
    rep(i,1,n-1){
    	int a,b;cin>>a>>b;
    	a--;b--;
    	g[a].pb(b);
    	g[b].pb(a);
    	inde[a]++;
    	inde[b]++;
    }
    unordered_set<int> st;
    rep(i,1,k) {
    	int x;
    	cin>>x;x--;
    	st.insert(x);
    }
    queue<int> q;
    int ans = n;
    rep(i,0,n-1){
    	if(inde[i]==1&&!st.contains(i)){
    		q.push(i);
    	}
    }
    while(!q.empty()){
    	auto t = q.front();q.pop();ans--;
    	for(auto x:g[t]){
    		inde[x]--;
    		if(inde[x]==1&&!st.contains(x)){
    			q.push(x);
    		}
    	}
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
