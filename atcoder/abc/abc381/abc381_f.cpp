// Problem: F - 1122 Subsequence
// Contest: AtCoder - AtCoder Beginner Contest 381
// URL: https://atcoder.jp/contests/abc381/tasks/abc381_f
// Memory Limit: 1024 MB
// Time Limit: 3000 ms

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
	int n, v, ans = 0;
    cin >> n;
    vector<vector<int>> pos(20);
    for (int i = 0; i < n; ++i) {
        cin >> v;
        pos[v - 1].push_back(i);
    }

    vector<int> f(1 << 20, INT_MAX);
    f[0] = 0;
    for (int i = 0; i < (1 << 20); ++i) {
        if (f[i] == INT_MAX) {
            continue;
        }
        ans = max(ans, (int)bitset<32>(i).count());
        int remaining = ((1 << 20) - 1) ^ i;
        while (remaining > 0) {
            int lb = remaining & -remaining;
            int bit = __builtin_ctz(lb);
            vector<int>& ps = pos[bit];
            auto it = lower_bound(ps.begin(), ps.end(), f[i]);
            if (it != ps.end()) {
                int k = it - ps.begin() + 1;
                if (k < ps.size()) {
                    f[i | lb] = min(f[i | lb], ps[k] + 1);
                }
            }
            remaining ^= lb;
        }
    }
    cout << ans * 2 << endl;

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
