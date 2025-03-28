// Problem: C - Buy Balls
// Contest: AtCoder - AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= int(b); ++i)  
#define rev(i, a, b) for (int i = int(a); i >= (b); --i) 
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
	int N,M;cin>>N>>M;
	vector<int> B(N), W(M);
	rep(i,0, N-1) cin>>B[i];
	rep(i,0, M-1) cin>>W[i];
	ranges::sort(B,greater<>());
	ranges::sort(W,greater<>());
	i64 sum = 0;
	int i=0;
	for(;i<min(N,M);i++){
		if(W[i]>0&&W[i]+B[i]>0){
			sum += (W[i]+B[i]);
		}else if(W[i]>0){
			cout<<sum<<endl;
			return;
		}else{
			break;
		}
	}
	while(i<N&&B[i]>0){
		sum+= B[i];
		i++;
	}
	cout<<sum<<endl;
	
	 
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
