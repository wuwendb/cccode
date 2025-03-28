// Problem: F - Double Sum
// Contest: AtCoder - AtCoder Beginner Contest 351
// URL: https://atcoder.jp/contests/abc351/tasks/abc351_f
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
template<typename T>
struct Fenwick {
  int n;
  vector<T> a;

  Fenwick(int n) : n(n), a(n) {}

  void add(int x, T v) {
    for (int i = x + 1; i <= n; i += i & -i) {
        a[i - 1] += v;
    }
  }

  void rangeAdd(int l, int r, T v) {
    add(l, v);
    add(r + 1, -v);
  }

  T sum(int x) {
    T s = 0;
    for (int i = x + 1; i > 0; i -= i & -i) {
        s += a[i - 1];
    }
    return s;
  }

  T rangeSum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};
  
void solve() {  
	int n;cin>>n;
	vector<int> a(n); 
    rep(i,0,n-1){
    	cin>>a[i];
    }
    auto b = a;
    ranges::sort(b);
    i64 ans =0;
    Fenwick<i64> f1(n),f2(n);
    rev(i,n-1,0){
    	auto it  = ranges::lower_bound(b,a[i])-b.begin();
    	i64 cnt = f1.rangeSum(it,n-1);
    	i64 sum = f2.rangeSum(it,n-1);
    	ans += sum-cnt*a[i];
    	f1.add(it,1);
    	f2.add(it,a[i]);
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
