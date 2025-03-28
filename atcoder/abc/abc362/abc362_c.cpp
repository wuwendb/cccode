// Problem: C - Sum = 0
// Contest: AtCoder - Toyota Programming Contest 2024#7（AtCoder Beginner Contest 362）
// URL: https://atcoder.jp/contests/abc362/tasks/abc362_c
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
    vector<i64> L(n),R(n);
    rep(i,0,n-1) cin>>L[i]>>R[i];
    vector<pair<i64,i64>> suf(n);
    suf[n-1]={0,0};
    rev(i,n-1,1){
    	suf[i-1] = {suf[i].first+L[i],suf[i].second+R[i]};
    }
    if(suf[0].first+L[0]<=0&&suf[0].second+R[0]>=0){
    	cout<<"Yes"<<endl;
    	i64 pre = 0;
    	rep(i,0,n-2){
    		if(pre-suf[i].second<=L[i]){
    			cout<<L[i]<<" ";
    			pre+=-L[i];
    		}else{
    			cout<<R[i]<<" ";
    			pre+=-R[i];
    		}
    	}
    	cout<<pre<<endl;
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
