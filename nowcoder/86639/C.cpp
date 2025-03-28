// Problem: 有大家喜欢的零食吗
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/86639/C
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

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
vector<int> g[mx];
int match[mx],reserve[mx];
int n,k,a;
bool dfs(int x){
	for(auto y:g[x]){
		if(!reserve[y]){
			reserve[y] = 1;
			if(!match[y]||dfs(match[y])){
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}
  
void solve() {  
    cin>>n;
    rep(i,1,n){
    	cin>>k;
    	rep(j,1,k){
    		cin>>a;
    		g[a].push_back(i);
    	}
    }
    int cnt = 0;
    rep(i,1,n){
        memset(reserve,0,sizeof(reserve));
    	if(dfs(i)) cnt++; 
    }
    if(cnt==n){
    	cout<<"Yes"<<endl;
    }else{
    	cout<<"No"<<endl;
	    cout<<n-cnt<<endl;
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
