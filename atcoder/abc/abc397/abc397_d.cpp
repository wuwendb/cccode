// Problem: D - Cubes
// Contest: AtCoder - OMRON Corporation Programming Contest 2025 (AtCoder Beginner Contest 397)
// URL: https://atcoder.jp/contests/abc397/tasks/abc397_d
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
using i128 = __int128;
using u128 = unsigned __int128;

using namespace std;  

const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

void solve() {  
    i64 N;
    cin >> N;
    
    for (i64 d = 1; d * d * d <= N; d++) {
        if (N % d != 0) {
            continue;
        }
        i64 p = N / d - d * d;
        if (p % 3 != 0) {
            continue;
        }
        p /= 3;
        i64 x = (d + sqrt(d * d + 4 * p)) / 2;
        i64 y = x - d;
        if (y > 0 && i128(x) * x * x - i128(y) * y * y == N) {
            cout << x << " " << y << "\n";
            return;
        }
    }
    
    cout << -1 << "\n";
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
