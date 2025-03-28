// Problem: 游戏
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87865/I
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rev(i, a, b) for (int i = (a); i >= (b); --i)
//#define ll long long
#define int long long
using namespace std;
const int mx = 2e5+5;
const int mod = 1e9+7;
const int MOD = 998244353;
//---------------------------------------------------------



void solve() {
    int n,m,k;cin>>n>>m>>k;
    vector<vector<array<int,3>>> g(n+1);
    int a,b,c,d;
    rep(_,1,m){
        cin>>a>>b>>c>>d;
        g[a].push_back({b,c,d});
        g[b].push_back({a,c,d});
    }
    auto shortestPath = [&](int start, int end,int haveKey)->int {
        // dis[i] 表示从起点 start 出发，到节点 i 的最短路长度
        vector<int> dis(g.size(), LLONG_MAX);
        dis[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            if (x == end) { // 计算出从起点到终点的最短路长度
                return d;
            }
            if (d > dis[x]) { // x 之前出堆过，无需更新邻居的最短路
                continue;
            }
            for (auto &[y, w, k] : g[x]) {
                if(haveKey==1 || k==1){
                    if (d + w < dis[y]) {
                        dis[y] = d + w; // 更新最短路长度
                        pq.push({dis[y], y});
                    }
                }
            }
        }
        return -1; // 无法到达终点
    };
    int OnetoN = shortestPath(1,n,0);
    int OnetoK = shortestPath(1,k,0);
    int ktoN = shortestPath(k,n,1);
    if(OnetoN==-1&&(OnetoK==-1 || ktoN==-1)){
        cout<< -1 <<endl;
    }else if(OnetoN==-1&& OnetoK != -1 && ktoN!=-1){
        cout<<OnetoK+ktoN<<endl;
    }else{
        cout<<min(OnetoN, (OnetoK!=-1&&ktoN!=-1)? OnetoK+ktoN:LLONG_MAX);
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
    // cout<<pow(2,22)<<endl;
    return 0;
}
