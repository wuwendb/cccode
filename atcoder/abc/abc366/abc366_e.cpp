// Problem: E - Manhattan Multifocal Ellipse
// Contest: AtCoder - AtCoder Beginner Contest 366
// URL: https://atcoder.jp/contests/abc366/tasks/abc366_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i)  
//#define ll long long  
#define int long long  
using namespace std;  
const int mx = 2e6+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
int x[mx],y[mx],prex[mx],prey[mx];
int cnt[mx];

void solve(){
	int mx,d;
	cin >>mx>>d;
	for(int i = 1;i <= mx;i ++)
		cin >>x[i]>>y[i];
	sort(x + 1,x + 1 + mx);
	sort(y + 1,y + 1 + mx);
	for(int i = 1;i <= mx;i ++){
		prex[i] = prex[i - 1] + x[i];
		prey[i] = prey[i - 1] + y[i];
	}
	for(int i = -2e6;i <= 2e6;i ++)
	{
		int pos = upper_bound(y + 1,y + 1 + mx,i) - y - 1;
		int dist = i * pos - prey[pos] + prey[mx] - prey[pos] - (mx - pos) * i;
		if(dist > d) continue;
		cnt[dist] ++; 
	}
	for(int i = 1;i <= d;i ++) cnt[i] += cnt[i - 1];
	int ans = 0;
	for(int i = -2e6;i <= 2e6;i ++)
	{
		int pos = upper_bound(x + 1,x + 1 + mx,i) - x - 1;
		int dist = i * pos - prex[pos] + prex[mx] - prex[pos] - (mx - pos) * i;
		if(dist > d) continue;
		ans += (cnt[d - dist]); 
	}
	cout<<ans;
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
