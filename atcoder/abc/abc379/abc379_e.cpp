// Problem: E - Sum of All Substrings
// Contest: AtCoder - Toyota Programming Contest 2024#11（AtCoder Beginner Contest 379）
// URL: https://atcoder.jp/contests/abc379/tasks/abc379_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= int(b); ++i)  
#define rev(i, a, b) for (int i = int(a); i >= (b); --i) 
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
    string s;cin>>s;
    vector<i64> a(n);
    i64 sum = 0;
    rep(i,0,n-1){
    	sum += (i+1)*(s[i]-'0');
    	a[n-1-i]=sum;
    }
    rep(i,0,n-1){
    	if(a[i]>=10){
    		if(i+1>=a.size()){
    			a.resize(i+2);
    		}
    		a[i+1] += a[i]/10;
    		a[i] %= 10;
    	}
    }
    rev(i,a.size()-1,0){
    	cout<<a[i];
    }
    cout<<endl;
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
