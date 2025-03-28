// Problem: D - AtCoder Wallpaper
// Contest: AtCoder - Panasonic Programming Contest 2024（AtCoder Beginner Contest 354）
// URL: https://atcoder.jp/contests/abc354/tasks/abc354_d
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
	vector<array<int,4>> area{{2,1,0,1},{1,2,1,0}};
	int a,b,c,d;cin>>a>>b>>c>>d;
	int cnt1 = (d-b)/2+((d-b)%2)*(b%2==0);
	int cnt2 = (d-b)/2+((d-b)%2)*(b%2!=0);
	vector<int> cnt(4,(c-a)/4);
	int start = (a+1000000000)%4;
	rep(i,start,start+(c-a)%4-1){
		cnt[i%4]++;
	}
	i64 ans = 0;
	rep(j,0,3){
		ans += 1LL*area[0][j]*cnt[j]*cnt1 + 1LL*area[1][j]*cnt[j]*cnt2;
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
    return 0;  
}
