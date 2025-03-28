// Problem: B - Vertical Writing
// Contest: AtCoder - AtCoder Beginner Contest 366
// URL: https://atcoder.jp/contests/abc366/tasks/abc366_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i)  
//#define ll long long  
#define int long long  
using namespace std;  
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

int m = 100;
void solve() {  
    int n;cin>>n;
    vector<vector<char>> vv(m);
    int mxsize = 0;
    rep(cnt,1,n){
    	string s;cin>>s;
    	mxsize = max(mxsize,(int)s.length());
    	rep(i,0,m-1){
    		if(i<s.size()){
				vv[i].push_back(s[i]);
    		}else if(!vv[i].empty()){
    			vv[i].push_back('*');
    		}else{
    			break;
    		}
    	}
    }
	rep(i,0,mxsize-1){
		rev(j,vv[i].size()-1,0){
			cout<<vv[i][j];
		}
		cout<<endl;
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
