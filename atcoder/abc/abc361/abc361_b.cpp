// Problem: B - Intersection of Cuboids
// Contest: AtCoder - Denso Create Programming Contest 2024（AtCoder Beginner Contest 361）
// URL: https://atcoder.jp/contests/abc361/tasks/abc361_b
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
   int a,b,c,
		d,e,f,
		g,h,i,
		j,k,l;
   cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
   auto check = [&](int l,int r,int L,int R){
		return !(r<=L||R<=l);
   };
   if(check(a,d,g,j)&&check(b,e,h,k)&&check(c,f,i,l)){
   	cout<<"Yes"<<endl;
   }else{
	cout<<"No"<<endl;
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
    return 0;  
}
