// Problem: C - Word Ladder
// Contest: AtCoder - Toyota Programming Contest 2024#9（AtCoder Beginner Contest 370）
// URL: https://atcoder.jp/contests/abc370/tasks/abc370_c
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
    string S,T;cin>>S>>T;
    stack<int> st;
    vector<string> ans;
    int n = S.length();
    rep(i,0,n-1){
    	if(S[i]<T[i]){
    		st.push(i);
    	}else if(S[i]>T[i]){
    		S[i]=T[i];
    		ans.pb(S);
    	}
    }
    while(!st.empty()){
    	auto i = st.top();st.pop();
    	S[i]=T[i];
		ans.pb(S);
    } 
    cout<<ans.size()<<endl;
    for(auto& s:ans) cout<<s<<endl;
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
