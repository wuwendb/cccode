// Problem: E - I Hate Sigma Problems
// Contest: AtCoder - AtCoder Beginner Contest 371
// URL: https://atcoder.jp/contests/abc371/tasks/abc371_e
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

using i64 = long long;
  
void solve() {  
	int	n;cin>>n;
	vector<int> a(n);
	rep(i,0,n-1) cin>>a[i];
	vector<int> last(mx,-1);
	i64 ans = 0;
	for(i64 i=0,sum=0;i<n;i++){
		sum += i-last[a[i]];
		ans += sum;
		last[a[i]] = i; 
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
