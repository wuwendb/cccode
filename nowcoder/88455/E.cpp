// Problem: 多米诺骨牌
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88455/E
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
int h[mx];
pair<int,int> p[mx];

  
void solve() {  
    int n,m;cin>>n>>m;
    rep(i,1,n){
    	cin>>h[i];
    }
    rep(i,1,n){
    	cin>>p[i].first;
    	p[i].second = h[i];
    }
    ranges::sort(p+1,p+n+1);
    vector<int> nums;
    int fx = 0,cnt = 0;
    for(int i =1;i<=n;i++){
    	if(cnt==0){
    		fx = p[i].second+p[i].first;
    		cnt++;
    		continue;
    	}
    	if(fx>=p[i].first){
    		fx = max(fx,p[i].second+p[i].first);
    		cnt++;
    	}else{
    		nums.push_back(cnt);
    		fx = p[i].second+p[i].first;
    		cnt=1;
    	}
    }
    nums.push_back(cnt);
    ranges::sort(nums,greater<>());
    int ans = 0,sz = nums.size();
	rep(i,0,min(m,sz)-1){
    	ans+=nums[i];
    }
    cout<<ans<<endl;
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
