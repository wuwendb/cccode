// Problem: D - ABA
// Contest: AtCoder - Panasonic Programming Contest 2024（AtCoder Beginner Contest 375）
// URL: https://atcoder.jp/contests/abc375/tasks/abc375_d
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
	string s;
	cin>>s;
	vector<int> left(26,0),right(26,0);
	int n = s.length();
	rep(i,1,n-1){
		right[s[i]-'A']++;
	}
	left[s[0]-'A']++;
	int ans = 0;
	rep(i,1,n-2){
		right[s[i]-'A']--;
		rep(k,0,25){
			ans+=left[k]*right[k];
		}
		left[s[i]-'A']++;
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
