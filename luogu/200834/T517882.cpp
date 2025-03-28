// Problem: T517882 【MX-X6-T3】さよならワンダーランド
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T517882?contestId=200834
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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
    int n;cin>>n;
    vector<int> a(n+1);
    rep(i,1,n){
    	cin>>a[i];
    } 
    vector<pii> subfix(n+1);
    subfix[n] = {a[n]-n,n};
    rev(i,n-1,1){
    	subfix[i].first = max(subfix[i+1].first,a[i]-i);
    	subfix[i].second = subfix[i].first==a[i]-i?i:subfix[i].second;
    }
    rep(i,1,n){
    	if(i+a[i]>n){
    		cout<<0<<endl;
    	}else if(subfix[max(1LL,i+a[i])].first>=(-1)*i){
    		cout<<1<<" "<<subfix[max(1LL,i+a[i])].second<<endl;
    	}else{
    		cout<<0<<endl;
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
