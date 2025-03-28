// Problem: P1341 无序字母对
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1341
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
int g[128][128];
int degree[128];
string ans;
void dfs(char s){
	degree[s]--;
	rep(i,0,127){
		if(g[s][i]){
			g[s][i]--;
			g[i][s]--;
			dfs(i);
		}
	}
	ans = s+ans;
}
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
    int n;
    cin>>n;
    dsu d(128);
    set<char> st;
    rep(i,1,n){
    	char c1,c2;cin>>c1>>c2;
    	d.unite(c1,c2);
    	st.insert(c1);
    	st.insert(c2);
    	g[c1][c2]++;
    	g[c2][c1]++;
    	degree[c1]++;
    	degree[c2]++;
    }
    if(d.setSize(*st.begin())!=st.size()){
    	cout<<"No Solution"<<endl;
    	return;
    }
    int c1=0,c2=0,cnt=0;
    rep(i,0,127){
    	if(degree[i]%2){
    		cnt++;
    		c1=c2;
    		c2=i;
    	}
    }
    if(cnt&&cnt!=2){
    	cout<<"No Solution"<<endl;
    	return;
    }
    if(c1==0){//不存在奇点
    	rep(i,0,127){
    		if(degree[i]){
    			dfs(i);
    			break;
    		}
    	}
    }else{
    	dfs(c1);
    }
    cout<<ans<<endl;
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
