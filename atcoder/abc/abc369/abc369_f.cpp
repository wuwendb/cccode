// Problem: F - Gather Coins
// Contest: AtCoder - AtCoder Beginner Contest 369
// URL: https://atcoder.jp/contests/abc369/tasks/abc369_f
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
    int H,W,N;cin>>H>>W>>N;
    vector<pair<int,int>> coins;
    rep(i,1,N){
    	int r,c;cin>>r>>c;
    	coins.pb({r,c});
    }
    ranges::sort(coins);
    vector<int> g;
    vector<int> g_index;
    vector<int> parent(N,-1);
    rep(i,0,N-1){
        auto it = ranges::upper_bound(g,coins[i].second);
        int pos = it-g.begin();
        if (it == g.end()) {
            g.push_back(coins[i].second); 
            g_index.pb(i);
        } else {
            *it =coins[i].second;
            g_index[pos] = i;
        }
    	if(pos>0){
    		parent[i] =g_index[pos-1];
    	}
    }
    vector<pair<int,int>> path{{H,W}};
    for(int i = g_index.back();i>=0;i=parent[i]){
    	path.pb(coins[i]);
    }
    path.pb({1,1});
    reverse(path.begin(),path.end());
    string s;
	rep(i,0,path.size()-2){
		int d = path[i+1].first - path[i].first;
		int r = path[i+1].second - path[i].second;
		while(d--) s.pb('D');
		while(r--) s.pb('R');
	}
	cout<<path.size()-2<<endl<<s<<endl;
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
