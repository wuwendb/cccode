// Problem: T511487 【入门赛】F 始终
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T511487?contestId=197857
// Memory Limit: 512 MB
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
// #define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    string s;cin>>s;
    int n = s.length();
    int ans =0;
    auto cal = [&](int i)->int{
    	if(i<1) return 0; 
    	else return (i+1)*i/2;
    };
    rep(i,0,25){
    	char c = i+'a';
    	int cnt = 0;
    	rep(j,0,n-1){
    		if(s[j] == c){
    			cnt++;
    		}else if(!(s[j]>='a'&&s[j]<='z')){
    			ans += cal(cnt);
    			cnt = 0;
    		}
    	}
    	ans += cal(cnt);
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
