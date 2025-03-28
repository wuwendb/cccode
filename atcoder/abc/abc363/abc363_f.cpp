// Problem: F - Palindromic Expression
// Contest: AtCoder - AtCoder Beginner Contest 363
// URL: https://atcoder.jp/contests/abc363/tasks/abc363_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
// #define rev(i, a, b) for (int i = (a); i >= (b); --i) 
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
    auto check =[&](i64 x){
    	string s= to_string(x);
    	return s.find('0')==string::npos;
    };
    auto rev = [&](i64 x){
    	string s = to_string(x);
    	reverse(s.begin(),s.end());
    	return stoll(s);
    };
    auto ispal =[&](i64 x){
    	return x==rev(x);
    };
    auto f = [&](auto& self,i64 x)->string{
    	if(check(x)&&ispal(x)){
    		return to_string(x);
    	}
    	for(i64 i=2;i*i<=x;i++){
    		if(x%i==0&&check(i)&&(x/i)%rev(i)==0){
    			string res =self(self,x/i/rev(i));
				if(res!=""){
					return to_string(i)+"*"+res+"*"+to_string(rev(i));
				}
    		}
    	}
    	return "";
    };
    auto ans = f(f,n);
    cout<<(ans==""?"-1":ans)<<endl;
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
