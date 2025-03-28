// Problem: C - AtCoder Magics
// Contest: AtCoder - Panasonic Programming Contest 2024（AtCoder Beginner Contest 354）
// URL: https://atcoder.jp/contests/abc354/tasks/abc354_c
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
    int n;cin>>n;
    vector<array<int,3>> a(n);
    rep(i,0,n-1){
    	int x,y;cin>>x>>y;
    	a[i] = {x,y,i};
    }
    ranges::sort(a,greater<>());
    stack<pii> stk;
    vector<int> ans;
    rep(i,0,n-1){
    	if(stk.empty()||!(stk.top().first>a[i][0]&&stk.top().second<a[i][1])){
    		stk.push({a[i][0],a[i][1]});
    		ans.pb(a[i][2]+1);
    	}
    }
    ranges::sort(ans);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
    	cout<<ans[i]<<" \n"[i==ans.size()-1];
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
