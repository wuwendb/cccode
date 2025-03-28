// Problem: C - Count ABC Again
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Autumn (AtCoder Beginner Contest 372)
// URL: https://atcoder.jp/contests/abc372/tasks/abc372_c
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
    int n,q;cin>>n>>q;
    string s;cin>>s;
    unordered_set<int> st;
    rep(i,0,s.size()-3){
    	if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
    		st.insert(i);
    	}
    }
    rep(i,1,q){
    	int x;char c;cin>>x>>c;x--;
    	if(s[x]=='A'&&st.contains(x)&&c!='A'){
    		st.erase(x);
    	}
    	if(s[x]=='B'&&st.contains(x-1)&&c!='B'){
    		st.erase(x-1);
    	}
    	if(s[x]=='C'&&st.contains(x-2)&&c!='C'){
    		st.erase(x-2);
    	}
    	if(x<s.size()-2&&c=='A'&&s[x+1]=='B'&&s[x+2]=='C'
    		||x<s.size()-1&&x>0&&c=='B'&&s[x-1]=='A'&&s[x+1]=='C'
    		||x>1&&c=='C'&&s[x-2]=='A'&&s[x-1]=='B'){
    		st.insert(x-(c-'A'));	
    	}
    	s[x] = c;
    	cout<<st.size()<<endl;
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
