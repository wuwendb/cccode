// Problem: C - Balls and Bag Query
// Contest: AtCoder - AtCoder Beginner Contest 366
// URL: https://atcoder.jp/contests/abc366/tasks/abc366_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i)  
//#define ll long long  
#define int long long  
using namespace std;  
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n;cin>>n;
    unordered_map<int,int> cnt;
    while(n--){
    	int op,x;cin>>op;
    	if(op==1){
    		cin>>x;cnt[x]++;
    	}else if(op==2){
    		cin>>x;cnt[x]--;if(cnt[x]==0) cnt.erase(x);
    	}else{
    		cout<<cnt.size()<<endl;
    	}
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
