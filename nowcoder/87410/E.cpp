// Problem: 相亲数据匹配
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87410/E
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) (a).begin(),(a).end() 
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
    vector<pair<int,int>> know;  
public:  
    explicit dsu(int n,vector<int>& gender) : pa(n), size(n, 1), know(n) {  
        iota(pa.begin(), pa.end(), 0);  
        rep(i,0,n-1){
        	know[i] = {gender[i],1-gender[i]};
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
        know[x].first += know[y].first;
        know[x].second += know[y].second;
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
    pair<int,int> getKnow(int x){
    	return know[x];
    }
};
  
void solve() {  
	int n,m;cin>>n>>m;
	vector<int> gender(n);rep(i,0,n-1) cin>>gender[i];
	map<int,pair<int,int>> know;
	dsu dsu(n,gender);
	rep(i,1,m){
		int x,y;cin>>x>>y;x--;y--;
		dsu.unite(x,y);
	}
    rep(i,0,n-1){
		auto [ma,fe] = dsu.getKnow(dsu.find(i));
		if(gender[i]){
			cout<<fe<<endl;
		}else{
			cout<<ma<<endl;
		}
    	
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
