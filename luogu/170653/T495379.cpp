// Problem: T495379 Inversion Pair
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T495379?contestId=170653
// Memory Limit: 128 MB
// Time Limit: 1000 ms

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
const int mx = 3e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int a[mx];
  
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
    int n,q;cin>>n>>q;
    Fenwick<int> fw(n+1);
    rep(i,1,n){
    	cin>>a[i];
    	if(a[i]<a[i-1]) fw.add(i,1);
    } 
    
    rep(i,1,q){
    	int x,y;cin>>x>>y;
    	if(x>y) swap(x,y);
    	if(x==y) cout<<0<<endl;
    	else cout<<fw.rangeSum(x+1,y)<<endl;
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
