// Problem: B - Vertical Reading
// Contest: AtCoder - AtCoder Beginner Contest 360
// URL: https://atcoder.jp/contests/abc360/tasks/abc360_b
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
    string s,t;cin>>s>>t;
    rep(i,1,s.size()-1){
    	int j = 0;
    	vector<string> v;
    	while(j+i<s.size()){
    		v.pb(s.substr(j,i));
    		j+=i;
    	}
    	v.pb(s.substr(j));
    	rep(k,0,i-1){
    		string tmp = "";
    		for(auto ss:v){
    			if(ss.size()>k){
    				tmp.pb(ss[k]);
    			}
    		}
    		if(tmp==t){
	    		cout<<"Yes"<<endl;
	    		return;
	    	}
    	}
    }
    cout<<"No"<<endl;
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
