// Problem: E - Sinking Land
// Contest: AtCoder - AtCoder Beginner Contest 363
// URL: https://atcoder.jp/contests/abc363/tasks/abc363_e
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
    int H,W,Y;
    cin>>H>>W>>Y;
    vector A(H+2,vector<int>(W+2,-1));
    priority_queue<pii,vector<pii>,greater<>> pq;
    rep(i,1,H){
    	rep(j,1,W){
			cin>>A[i][j];
    		if(i==1||i==H||j==1||j==W){
    			pq.emplace(A[i][j],(i<<10)|j);
    			A[i][j]=-1;
    		}
    	} 
    }
    int level =1;
    int ans = H*W;
    while(level<=Y){
    	while(!pq.empty()&&pq.top().first<=level){
    		auto [_,position] = pq.top();pq.pop();ans--;
    		int x = position>>10;
    		int y = position&((1<<10)-1);
    		rep(i,0,3){
    			int nx = x+dx[i];
    			int ny = y+dy[i];
    			if(A[nx][ny]!=-1){
    				pq.emplace(A[nx][ny],(nx<<10)|ny);
    				A[nx][ny]=-1;
    			}
    		}
    	}
    	level++;
	    cout<<ans<<endl;
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
    return 0;  
}
