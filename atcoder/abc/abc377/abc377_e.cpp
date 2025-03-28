// Problem: E - Permute K times 2
// Contest: AtCoder - TOYOTA SYSTEMS Programming Contest 2024（AtCoder Beginner Contest 377)
// URL: https://atcoder.jp/contests/abc377/tasks/abc377_e
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
int power(int a, i64 b, int p) {
    int res = 1;
    for (; b; b /= 2, a = 1LL * a * a % p) {
        if (b & 1) {
            res = 1LL * res * a % p;
        }
    }
    return res;
}
  
void solve() {  
	int n;i64 k;cin>>n>>k;
	vector<int> p(n);
	rep(i,0,n-1){
		cin>>p[i];
		p[i]--;
	}
	vector<bool> vis(n,false);
	rep(i,0,n-1){
		if(vis[i]) continue;
		vector<int> cycle;
		int tmp = i;
		while(!vis[tmp]){
			cycle.pb(tmp);
			vis[tmp]=true;
			tmp = p[tmp];
		}
		auto offset = power(2,k,cycle.size());
		rep(j,0,cycle.size()-1){
			p[cycle[j]] = cycle[(j+offset)%cycle.size()];
		}
	}
    rep(i,0,n-1) cout<<p[i]+1<<" \n"[i==n-1];
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
