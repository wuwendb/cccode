// Problem: D - Cross Explosion
// Contest: AtCoder - Toyota Programming Contest 2024#9（AtCoder Beginner Contest 370）
// URL: https://atcoder.jp/contests/abc370/tasks/abc370_d
// Memory Limit: 1024 MB
// Time Limit: 4000 ms

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
    int H,W,Q;cin>>H>>W>>Q;
    vector<set<int>> row(H),col(W);
    rep(i,0,H-1){
    	rep(j,0,W-1){
    		row[i].insert(j);
    		col[j].insert(i);
    	}
    }
    int ans = H*W;
    rep(i,1,Q){
    	int R,C;cin>>R>>C;R--,C--;
    	if(row[R].contains(C)){
    		ans--;
    		row[R].erase(C);
    		col[C].erase(R);continue;
    	}
    	auto it = row[R].lower_bound(C);
    	if(it!=row[R].begin()){
    		int x = *prev(it);
    		row[R].erase(x);
    		col[x].erase(R);
    		ans--;
    	}
    	if(it!=row[R].end()){
    		row[R].erase(*it);
    		col[*it].erase(R);
    		ans--;
    	}
    	it = col[C].lower_bound(R);
    	if(it!=col[C].begin()){
    		int x = *prev(it);
    		row[x].erase(C);
    		col[C].erase(x);
    		ans--;
    	}
    	if(it!=col[C].end()){
    		row[*it].erase(C);
    		col[C].erase(*it);
    		ans--;
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
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
