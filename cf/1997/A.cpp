// Problem: A. Strong Password
// Contest: Codeforces - Educational Codeforces Round 168 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1997/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	string s;cin>>s;int n = s.size();
	for(int i =1;i<n;i++){
		if(s[i]==s[i-1]){
			s.insert(i,1,(s[i]-'a'+1)%26+'a');
			break;
		}
	}
	if(n==s.size()){
		s.push_back((s[n-1]-'a'+1)%26+'a');
	}
	cout<<s<<endl;
}  

signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    cin >> t;  
    while (t--) {  
        solve();  
    }  
//    cout<<pow(2,22)<<endl;  
    return 0;  
}