// Problem: 狼狼的备忘录
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87255/H
// Memory Limit: 524288 MB
// Time Limit: 4000 ms

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

bool isSuffix(const string& s1, const string& s2) {
    if (s1.size() > s2.size()) {
        return false;
    }

    return s2.rfind(s1) == s2.size() - s1.size();
}
  
void solve() {  
    int n;cin>>n;
    map<string,vector<string>> book;
    rep(i,1,n){
    	string name;int nums;string info;
    	cin>>name>>nums;
    	rep(j,1,nums){
    		cin>>info;
    		bool f = true;
    		for(auto& s:book[name]){
    			if(isSuffix(info,s)){
    				f=false;break;
    			}else if(isSuffix(s,info)){
    				f=false;s = info;
    			}
    		}
    		if(f) book[name].push_back(info);
    	}
    }
    cout<<book.size()<<endl;
    for(auto& [k,v]:book){
    	cout<<k<<" "<<v.size();
    	sort(all(v));
    	for(auto s:v) cout<<" "<<s;
    	cout<<endl;
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
