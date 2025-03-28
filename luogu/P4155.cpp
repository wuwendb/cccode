// Problem: P4155 [SCOI2015] 国旗计划
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4155
// Memory Limit: 250 MB
// Time Limit: 1500 ms

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
int n,m;
struct soldier{
	int id,l,r;
	bool operator<(const soldier& other){
		return this->l<other.l;
	}
}s[mx*2];
int st[mx*2][20];
int res[mx];
void pre(){
	for(int i = 1,p=i;i<=2*n;i++){
		while(p<=2*n&&s[p].l<=s[i].r) p++;
		st[i][0] = p-1;
	}
	for(int i = 1;i<20;i++){
		for(int j = 1;j<=2*n;j++){
			st[j][i] = st[st[j][i-1]][i-1];
		}
	}
}
void cal(int k){
	int ans = 1,lmt = s[k].l+m,p=k;
	for(int i=19;i>=0;i--){
		if(st[k][i]!=0&&s[st[k][i]].r<lmt){
			ans+=(1<<i);
			k = st[k][i];
		}
	}
	res[s[p].id]=ans+1;
}
void solve() {  
    cin>>n>>m;
    rep(i,1,n){
    	cin>>s[i].l>>s[i].r;
    	if(s[i].l>s[i].r) s[i].r+=m;
    	s[i].id = i;
    }
    sort(s+1,s+1+n);
    rep(i,1,n){
    	s[i+n] = s[i];
    	s[i+n].l = s[i].l+m;
    	s[i+n].r = s[i].r+m;
    }
    pre();
    rep(i,1,n){
		cal(i);
    }
    rep(i,1,n){
    	cout<<res[i]<<" ";
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
