// Problem: P4124 [CQOI2016] 手机号码
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4124
// Memory Limit: 250 MB
// Time Limit: 1000 ms

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

int num[15];
int memo[15][11][11][2][2][2];

int dfs(int i, int last,int llast, int state, bool eight, bool four, bool islimit) {
    if(eight&&four) return 0;
    if (i == 0) {
        return state;
    }
    if (!islimit && memo[i][last][llast][state][eight][four] != -1) {
        return memo[i][last][llast][state][eight][four];
    }
    int up = islimit ? num[i] : 9;
    int res = 0;
    for (int d = 0; d <= up; d++) {
        res += dfs(i - 1, d, last, state||(last == d && last ==llast),eight || d == 8, four || d == 4, d == up && islimit);
    }
    if (!islimit) {
         memo[i][last][llast][state][eight][four] = res;
    }
    return res;
}

int work(int x) {
    int len = 0;
    while (x) {
        num[++len] = x % 10;
        x /= 10;
    }
    if(len!=11) return 0;
    memset(memo,-1,sizeof(memo));
    int ans = 0;
    rep(i,1,num[len]){
    	ans += dfs(len-1, i, 0,0, i==8, i==4, i==num[len]);
    }
    return ans;
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << work(r) - work(l - 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
