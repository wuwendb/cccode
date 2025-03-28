// Problem: T517879 【MX-X6-T1】Subtask Dependency
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T517879?contestId=200834
// Memory Limit: 512 MB
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
    int n;cin>>n;
    unordered_map<int,vector<int>> mp;
    rep(i,1,n){
    	int d;cin>>d;
    	vector<int> v;
    	rep(j,1,d){
    		int a;cin>>a;
    		v.pb(a);
    	}
    	mp[i] = v;
    }
    int m;cin>>m;
    vector<int> p(n+1);
    rep(i,1,m){
    	rep(j,1,n){
    		cin>>p[j];
    	}
    	int ans = 0;
    	rep(j,1,n){
    		if(p[j]){
	    		bool f = true;
    			for(auto v:mp[j]){
    				if(!p[v]){
    					f = false;
    				}
    			}
    			if(f) ans++;
    			else p[j]=0;
    		}
    	}
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
