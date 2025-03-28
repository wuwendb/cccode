// Problem: 正则表达式
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87865/B
// Memory Limit: 524288 MB
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

vector<string> split(const string& s, vector<string>& res, char delim) {
    std::stringstream ss(s);
    string item;
    while (std::getline(ss, item, delim)) {
        res.push_back(item);
    }
    return res;
}
void solve() {  
    int n;cin>>n;
    int ans=0;
    while(n--){
    	string s;cin>>s;
    	vector<string> res;
    	split(s,res,'.');
    	bool b=true;
    	for(auto str:res){
    		if(stoi(str)>255||stoi(str)<0){
    			b=false;
    			break;
    		}
    	}
    	if(b) ans++;
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
