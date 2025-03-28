// Problem: E - How to Win the Election
// Contest: AtCoder - AtCoder Beginner Contest 373
// URL: https://atcoder.jp/contests/abc373/tasks/abc373_e
// Memory Limit: 1024 MB
// Time Limit: 2500 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define ll long long  
// #define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
void solve() {  
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (auto& e : a) cin >> e;
    const ll rem = k - accumulate(a.begin(), a.end(), 0LL);

    if (n == m) {
        for (int i = 0; i < n; ++i) cout << 0 << " \n"[i == n - 1];
        return;
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
    auto b = a;
    sort(b.begin(), b.end());
    vector<ll> sumb(n + 1);  
    for (int i = 0; i < n; ++i) sumb[i + 1] = sumb[i] + b[i];

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll l = -1, r = rem + 1;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            ll rid = lower_bound(b.begin(), b.end(), b[i] + mid + 1) - b.begin();  
            ll lid = n - m - (i >= n - m ? 1 : 0); 
            ll cnt = 0;
            if (rid > lid) cnt += (rid - lid) * (b[i] + mid + 1) - (sumb[rid] - sumb[lid]);
            if (lid <= i && i < rid)
                cnt--;  
            else
                cnt += mid; 
            if (cnt > rem)
                r = mid;
            else
                l = mid;
        }
        if (l == rem)
            ans[ord[i]] = -1;
        else
            ans[ord[i]] = r;
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
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
