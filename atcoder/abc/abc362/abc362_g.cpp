// Problem: G - Count Substring Query
// Contest: AtCoder - Toyota Programming Contest 2024#7（AtCoder Beginner Contest 362）
// URL: https://atcoder.jp/contests/abc362/tasks/abc362_g
// Memory Limit: 1024 MB
// Time Limit: 3000 ms

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
struct SA {
    int n;
    std::vector<int> sa, rk, lc;

    SA(std::string s) {
        n = s.size();
        sa.resize(n);
        lc.resize(n - 1);
        rk.resize(n);
        std::iota(sa.begin(), sa.end(), 0);
        std::sort(sa.begin(), sa.end(),
            [&](int a, int b) {
                return s[a] < s[b];
            });
        rk[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
        }
        int k = 1;
        std::vector<int> tmp, cnt(n);
        tmp.reserve(n);
        while (rk[sa[n - 1]] < n - 1) {
            tmp.clear();
            for (int i = 0; i < k; i++) {
                tmp.push_back(n - k + i);
            }
            for (auto i : sa) {
                if (i >= k) {
                    tmp.push_back(i - k);
                }
            }
            std::fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; i++) {
                cnt[rk[i]]++;
            }
            for (int i = 1; i < n; i++) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                sa[--cnt[rk[tmp[i]]]] = tmp[i];
            }
            std::swap(rk, tmp);
            rk[sa[0]] = 0;
            for (int i = 1; i < n; i++) {
                rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i - 1] + k] < tmp[sa[i] + k]);
            }
            k *= 2;
        }
        for (int i = 0, j = 0; i < n; i++) {
            if (rk[i] == 0) {
                j = 0;
            } else {
                for (j -= j > 0; i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j]; ) {
                    j++;
                }
                lc[rk[i] - 1] = j;
            }
        }
    }
    int count(const std::string &s, const std::string &t) {
        int m = t.size();
        if (m > n) return 0;

        auto lower_bound = [&](const std::string &t) -> int {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (s.compare(sa[mid], m, t) < 0) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        };

        auto upper_bound = [&](const std::string &t) -> int {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (s.compare(sa[mid], m, t) <= 0) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        };

        int l = lower_bound(t);
        int r = upper_bound(t);

        return r - l;
    }
};

  
void solve() {  
    string s;cin>>s;
    int q;cin>>q;
    SA sa(s);
    rep(i,1,q){
    	string t;cin>>t;
    	cout<<sa.count(s,t)<<endl;
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
