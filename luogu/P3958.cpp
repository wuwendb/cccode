// Problem: P3958 [NOIP2017 提高组] 奶酪
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3958
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
int n,h,r;
class dsu {  
public:  
    vector<int> pa, size,low,high;  
    explicit dsu(vector<array<int,3>>& a) : pa(n), size(n, 1),low(n),high(n) {  
        iota(pa.begin(), pa.end(), 0);  
        rep(i,0,n-1){
        	low[i] = a[i][0]-r;
        	high[i] = a[i][0]+r;
        }
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
        low[x] = min(low[x],low[y]);
        high[x] = max(high[x],high[y]);
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
    bool isOk(int x){
    	return low[find(x)]<=0&&high[find(x)]>=h;
    }  
};
  
void solve() {  
    cin>>n>>h>>r;
    vector<array<int,3>> p;
    rep(i,1,n){
    	int x,y,z;
    	cin>>x>>y>>z;
    	p.push_back({z,x,y});
    }
    ranges::sort(p);
    dsu d(p);
    auto dist = [&](auto p1,auto p2){
    	return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1])+(p1[2]-p2[2])*(p1[2]-p2[2]);
    };
    rep(i,0,n-1){
    	rep(j,i+1,n-1){
    		if(dist(p[i],p[j])<=4*r*r){
    			d.unite(i,j);
    		}
    	}
    }
    rep(i,0,n-1){
    	if(d.isOk(i)){
    		cout<<"Yes"<<endl;
    		return;
    	}
    }
    cout<<"No"<<endl;
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
