// Problem: P1111 修复公路
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1111
// Memory Limit: 125 MB
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
class dsu {
    vector<int> pa, size;
public:
    explicit dsu(int n) : pa(n), size(n, 1) {
        iota(pa.begin(), pa.end(), 0);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) {
            swap(x, y);
        }
        pa[y] = x;
        size[x] += size[y];
    }
    int find(int x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }
    bool sameSet(int x, int y) {
        return find(x) == find(y);
    }
    int setSize(int x) {
        return size[find(x)];
    }
};

void solve() {
    int n,m;cin>>n>>m;
    dsu dsu(n);
    vector<array<int,3>> road;
    rep(i,1,m){
        int x,y,t;
        cin>>x>>y>>t;x--;y--;
        road.push_back({t,x,y});
    }
    ranges::sort(road);
    rep(i,0,m-1){
        dsu.unite(road[i][1],road[i][2]);
        if(dsu.setSize(road[i][1])==n){
            cout<<road[i][0]<<endl;return;
        }
    }
    cout<<-1<<endl;
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
    // cout<<pow(2,22)<<endl;
    return 0;
}
