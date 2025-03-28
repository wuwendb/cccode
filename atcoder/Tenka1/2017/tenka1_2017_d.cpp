// Problem: D - IntegerotS
// Contest: AtCoder - Tenka1 Programmer Contest
// URL: https://atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_d
// Memory Limit: 256 MB
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
    int n,k;cin>>n>>k;
    vector<int> a(n),b(n);
    bitset<30> B[n];
    rep(i,0,n-1){
		cin>>a[i]>>b[i];
		B[i] = a[i]; 
    }
    i64 ans = 0;
    auto check = [&](bitset<30> x){
    	i64 sum = 0;
    	rep(i,0,n-1){
    		if((x|B[i])==x){
    			sum += b[i];
    		}
    	}
    	ans = max(ans, sum);
    };
    bitset<30> K(k);
    check(K);
	rep(i,0,29){
		if((k>>i)&1){
			K = k|((1LL<<(i+1))-1);
			K.reset(i);
			check(K);
		}
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
