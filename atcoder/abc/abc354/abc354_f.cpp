// Problem: F - Useless for LIS
// Contest: AtCoder - Panasonic Programming Contest 2024（AtCoder Beginner Contest 354）
// URL: https://atcoder.jp/contests/abc354/tasks/abc354_f
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
int lengthOfLIS(vector<int> &nums) {
    vector<int> g;
    for (int x : nums) {
        auto it = ranges::lower_bound(g, x);
        if (it == g.end()) {
            g.push_back(x); // >=x 的 g[j] 不存在
        } else {
            *it = x;
        }
    }
    return g.size();
}
vector<int> LIS(vector<int> &nums) {
	vector<int> res;
    vector<int> g;
    for (int i=0;i<nums.size();i++) {
    	int x=nums[i];
        auto it = ranges::lower_bound(g, x);
        res.pb(it-g.begin()+1);
        if (it == g.end()) {
            g.push_back(x); // >=x 的 g[j] 不存在
        } else {
            *it = x;
        }
    }
    return res;
}
void solve() {  
    int n;cin>>n;
    vector<int>a(n);
    rep(i,0,n-1) cin>>a[i];
    auto len = lengthOfLIS(a);
    vector<int> ans;
    auto v1 = LIS(a);
    vector<int> tmp{a};
    rep(i,0,n-1){
    	tmp[i] *= -1;
    }
    reverse(tmp.begin(),tmp.end());
    auto v2 = LIS(tmp);
    reverse(v2.begin(),v2.end());
    rep(i,0,n-1){
    	if(v1[i]+v2[i]-1==len){
    		ans.pb(i+1);
    	}
    }
    cout<<ans.size()<<endl;
    rep(i,0,ans.size()-1){
    	cout<<ans[i]<<" \n"[i==ans.size()-1];
    }
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
    return 0;  
}
