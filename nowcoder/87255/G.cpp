// Problem: lxy的通风报信
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87255/G
// Memory Limit: 524288 MB
// Time Limit: 4000 ms

#include <bits/stdc++.h>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rev(i, a, b) for (int i = (a); i >= (b); --i)
#define all(a) (a).begin(),(a).end()
#define ll long long
// #define int long long  
using namespace std;
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;
const int mod = 1e9+7;
const int MOD = 998244353;
//---------------------------------------------------------  

struct dsu {
    vector<int> pa, size;
    explicit dsu(int n) : pa(n), size(n, 1) {
        iota(pa.begin(), pa.end(), 0);
    }
    int find(int x) {
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }
    bool unite(int x, int y, int lens) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (size[x] < size[y]) {
            swap(x, y);
        }
        // 将 y 的根节点设为 x，同时更新 x 的集合大小  
        pa[y] = x;
        size[x] += size[y];
        return true;
    }
    bool sameSet(int x, int y) {
        return find(x) == find(y);
    }
    int setSize(int x) {
        return size[find(x)];
    }
};


struct Edge{
    int from;
    int to;
    int weight;
};

void solve() {
    int n,m;cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    map<pair<int,int>,int> index;
    int cnt=0;
    rep(i,0,n-1){
        rep(j,0,m-1){
            cin>>a[i][j];
            if(a[i][j]=='*'){
                index[{i,j}] = cnt++;
            }
        }
    }
    vector<Edge> g;
    auto shortestPath = [&](int i, int j) {
        int count = 1;
        vector<vector<int>> dis(n, vector<int>(m,0));
        dis[i][j] = 1;
        queue<pair<int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            rep(k,0,3){
                int newx = x + dx[k];
                int newy = y + dy[k];
                if(newx>=0&&newx<n&&newy>=0&&newy<m&&a[newx][newy]!='#'&&dis[newx][newy]==0){
                    dis[newx][newy] = 1+dis[x][y];
                    q.push({newx,newy});
                    if(a[newx][newy] == '*'){
                        count++;
                        g.push_back(Edge{index[{i,j}],index[{newx,newy}],dis[x][y]});
                    }
                }
            }
        }
        if(count<cnt){
            return -1;
        }else{
            return 1;
        }
    };

    rep(i,0,n-1){
        rep(j,0,m-1){
        	if(a[i][j]=='*'){
        		int w = shortestPath(i,j);
	            if(w==-1){
	                cout<<"No"<<endl;
	                return;
	            }
        	}
        }
    }
    auto kruskal = [&]() {
        sort(g.begin(),g.end(),[](auto &a,auto &b){
            return a.weight<b.weight;
        });
        dsu dsu(n);
        int ans=0,num=1;
        for(auto & i : g){
            if(dsu.unite(i.from,i.to,i.weight)){
                ans+=i.weight;
                num++;
                if(num==cnt){
                    break;
                }
            }
        }
        return ans;
    };
    cout<<kruskal()<<endl;
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
