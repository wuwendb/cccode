// Problem: E - Guess the Sum
// Contest: AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2024（AtCoder Beginner Contest 355)
// URL: https://atcoder.jp/contests/abc355/tasks/abc355_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
// #define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
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
    int n,l,r;cin>>n>>l>>r;
    vector<vector<int>> g((1<<n)+1);
    rep(i,0,n){
    	for(int j=0;j<(1<<n);j+=(1<<i)){
    		g[j].pb(j+(1<<i));
    		g[j+(1<<i)].pb(j);
    	}
    }
    queue<int> q;
    vector<int> pre((1<<n)+1,-1);
    pre[l] = l;
    q.push(l);
    while(!q.empty()){
    	auto x =q.front();q.pop();
    	if(x==r+1){
    		break;
    	}
    	for(auto y:g[x]){
    		if(pre[y]!=-1){
    			continue;
    		}
    		q.push(y);
    		pre[y] = x;
    	}
    }
    vector<array<int,2>> query;
    for(int i=r+1;i!=l;i = pre[i]){
    	query.pb({pre[i],i});
    }
    reverse(query.begin(),query.end());
    int ans = 0;
    for(auto [a,b]:query){
    	int f = 1;
    	if(a>b){
    		swap(a,b);
    		f=-1;
    	}
    	cout<<"? "<<__lg(b-a)<<" "<<a/(b-a)<<endl;
    	int res;cin>>res;
    	ans = (ans+res*f+100)%100;
    }
    cout<<"! "<<ans<<endl;
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
