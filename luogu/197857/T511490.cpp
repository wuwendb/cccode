// Problem: T511490 【入门赛】H 考试
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T511490?contestId=197857
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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
int a[mx];
  
void solve() {  
    int n;cin>>n;
    rep(i,1,n){
    	cin>>a[i];
    }
    int hcnt = 0,lcnt=0,ecnt = 0;
    priority_queue<int,vector<int>,greater<>> pq;
    rep(i,1,n){
    	int b;cin>>b;
    	if(b>a[i]){
    		lcnt++;
    		pq.push(b-a[i]);
    	}else if(b<a[i]){
    		hcnt++;
    	}else{
    		ecnt++;
    	}
    }
    int res = 0;
    while(ecnt+hcnt<=lcnt){
    	auto t= pq.top();pq.pop();
    	if(hcnt == lcnt){
    		res += t;
    	}else{
	    	res += t+1;		
    	}
    	hcnt++,lcnt--;
    }
    if(hcnt>lcnt) cout<<res<<endl;
    else cout<<res+lcnt-hcnt+1<<endl;
    
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
