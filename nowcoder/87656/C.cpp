// Problem: 小红的数组重排
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87656/C
// Memory Limit: 1048576 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i)  
#define all(a) (a).begin(),(a).end()
//#define ll long long  
#define int long long  
using namespace std;  
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n;cin>>n;vector<int> a(n);rep(i,0,n-1) cin>>a[i];
    sort(all(a));
    if(a[0]==a[1]&&a[0]==0){
        cout<<"NO"<<endl;
        return;
    }
    rep(i,2,n-1){
    	if(a[i]==a[i-2]){
    		cout<<"NO"<<endl;
    		return;
    	}
    }
    cout<<"YES"<<endl;
    rep(i,0,n-1){
    	cout<<a[i]<<" \n"[i==n-1];
    }
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
//    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
//    cout<<pow(2,22)<<endl;  
    return 0;  
}
