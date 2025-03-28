// Problem: 国际旅行Ⅰ
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87255/A
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
    int n,m,q;cin>>n>>m>>q;
    vector<int> a(n);rep(i,0,n-1) cin>>a[i];
    dsu dsu(n);
    rep(i,1,m){
    	int u,v;cin>>u>>v;u--;v--;
    	dsu.unite(u,v);
    }
    int f = dsu.find(0);
    vector<int> nums;
    rep(i,0,n-1){
    	if(dsu.find(i)==f){
    		nums.push_back(a[i]);
    	}
    }
    sort(all(nums));
    rep(i,1,q){
    	int k;cin>>k;
    	cout<<nums[k-1]<<endl;
    }
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
//    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
//    cout<<pow(2,22)<<endl;  
    return 0;  
}
