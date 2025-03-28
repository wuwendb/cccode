// Problem: D - Palindromic Number
// Contest: AtCoder - AtCoder Beginner Contest 363
// URL: https://atcoder.jp/contests/abc363/tasks/abc363_d
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
    i64 n;cin>>n;
    int d=1;
    if(n==1){
    	cout<<0<<endl;
    	return;
    }
    n--;
    while(true){
    	auto p = 9*(i64)pow(10,(d+1)/2-1);
    	if(n>p){
    		d++;
    		n-=p;continue;
    	}else{
    		auto half = (i64)pow(10,(d+1)/2-1)+n-1;
			string s=to_string(half);
			cout<<s;
    		if(d%2){
    			s.pop_back();
    		}
    		reverse(s.begin(),s.end());
			cout<<s<<endl;
			break;
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
    return 0;  
}
