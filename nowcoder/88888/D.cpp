// Problem: 小红的线段
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88888/D
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

  
void solve() {  
    int n,k,b;
    cin>>n>>k>>b;
    stack<int> up,low,on;
    rep(i,1,2*n){
    	int x,y;
    	cin>>x>>y;
    	if(k*x+b==y) on.push(i);
    	else if(k*x+b<y) up.push(i);
    	else low.push(i);
    }
    int ans = min(low.size(),up.size());
    if(ans!=n){
    	int tmp = min(abs((int)low.size()-(int)up.size()),(int)on.size());
		ans+=tmp;
    	if((int)on.size()!=tmp){
    		ans += ((int)on.size()-tmp)/2;
    	}
    }
    cout<<ans<<endl;
    while(!low.empty()&&!up.empty()){
    	cout<<low.top()<<" "<<up.top()<<" "<<"Y"<<endl;
    	low.pop();up.pop();
    }
    while(!on.empty()&&(!low.empty()||!up.empty())){
    	cout<<on.top()<<" ";
    	if(low.empty()){
    		cout<<up.top()<<" Y"<<endl;
    		up.pop();
    	} else{
    		cout<<low.top()<<" Y"<<endl;
    		low.pop();
    	}
    	on.pop();
    }
    while(!on.empty()){
    	cout<<on.top()<<" ";on.pop();
    	cout<<on.top()<<" Y"<<endl;on.pop();
    }
    while(!low.empty()){
    	cout<<low.top()<<" ";low.pop();
    	cout<<low.top()<<" N"<<endl;low.pop();
    }
    while(!up.empty()){
    	cout<<up.top()<<" ";up.pop();
    	cout<<up.top()<<" N"<<endl;up.pop();
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
