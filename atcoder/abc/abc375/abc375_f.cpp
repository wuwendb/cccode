// Problem: F - Road Blocked
// Contest: AtCoder - Panasonic Programming Contest 2024（AtCoder Beginner Contest 375）
// URL: https://atcoder.jp/contests/abc375/tasks/abc375_f
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
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
class Graph {
    const int INF = LLONG_MAX / 3;
    vector<vector<int>> f;
public:
    Graph(int n, vector<vector<int>> &edges) : f(n, vector<int>(n, INF)) {
        for (int i = 0; i < n; i++) {
            f[i][i] = 0;
        }
        for (auto &e : edges) {
            f[e[0]][e[1]] = e[2]; // 添加一条边（题目保证没有重边和自环）
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                if (f[i][k] == INF) continue;
                for (int j = 0; j < n; j++) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
    }

    void addEdge(vector<int> e) {
        int x = e[0], y = e[1], w = e[2], n = f.size();
        if (w >= f[x][y]) { // 无需更新
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f[i][j] = min(f[i][j], f[i][x] + w + f[y][j]);
            }
        }
    }

    int shortestPath(int start, int end) {
        int ans = f[start][end];
        return ans < INF ? ans : -1;
    }
};
  
void solve() {  
    int N,M,Q;cin>>N>>M>>Q;
    vector<vector<int>> edge;
    rep(i,1,M){
    	int a,b,c;cin>>a>>b>>c;a--,b--;
    	edge.pb({a,b,c});
    	edge.pb({b,a,c});
    }
    vector<int> ans;
    vector<vector<int>> query;
    set<int,greater<>> st;
    rep(q,1,Q){
    	int op;cin>>op;
    	if(op==1){
    		int i;cin>>i;i--;query.pb(edge[i*2]);query.pb(edge[i*2+1]);
    		st.insert(i);
    	}else{
    		int x,y;cin>>x>>y;x--,y--;query.pb({x,y});
    	}
    }
    for(auto& x:st) {
    	edge.erase(next(edge.begin(),x*2+1));
    	edge.erase(next(edge.begin(),x*2));
    }
    Graph g(N,edge);
    reverse(query.begin(),query.end());
    for(auto q:query){
    	if(q.size()==2){
    		ans.pb(g.shortestPath(q[0],q[1]));
    	}else{
    		g.addEdge(q);
    	}
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
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
