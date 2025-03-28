// Problem: P1955 [NOI2015] 程序自动分析
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1955
// Memory Limit: 500 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
#define ll long long  
// #define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 4e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
int fa[mx],g[mx];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void dsu(){
	iota(begin(fa), end(fa), 0);
}
  
void solve() {  
    dsu();
    int n;cin>>n;
    bool f=true;
    vector<tuple<int,int,int>> input;
    int cnt = 0;
    rep(_,1,n){
    	int i,j,e;cin>>i>>j>>e;
    	input.emplace_back(e,i,j);
    	g[cnt++]=i;
    	g[cnt++]=j;
    }
    sort(g,g+cnt);
    int num = unique(g,g+cnt)-g;
    ranges::sort(input,greater<>());
    rep(t,1,n){
    	auto [e,i,j] = input[t-1];
    	i = lower_bound(g,g+num,i)-g;
    	j = lower_bound(g,g+num,j)-g;
    	int fi = find(i);
		int fj = find(j);
    	if(e==1){
			fa[fi] = fj;
    	}else{
    		if(fi==fj){
    			f= false;
    			cout<<"NO"<<endl;
    			break;
    		}
    	}
    }
    if(f) cout<<"YES"<<endl;
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
