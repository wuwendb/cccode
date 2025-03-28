// Problem: T497979 因友情而终结
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T497979?contestId=188303
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
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
    string s;
    cin>>s;
    int n = s.size();
    if(n<6){
    	cout<<0<<endl;return;
    }
    int ans=0;
    int lastend=-1,lastcount = 1;
    rep(i,0,n-6){
    	if(s[i]=='f'&&s[i+1]=='r'&&s[i+2]=='i'&&s[i+3]=='e'&&s[i+4]=='n'&&s[i+5]=='d'){
    		if(lastend!=-1&&i-lastend<=3&&lastcount==1){
    			lastcount=0;
    			continue;
    		}else{
    			lastcount=1;
    			ans++;
    			lastend = i+5;
    			i+=5;
    		}
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
