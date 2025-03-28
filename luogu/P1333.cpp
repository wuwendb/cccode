// Problem: P1333 瑞瑞的木棍
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1333
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
const int mx = 5e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
string c1,c2;
unordered_map<string,int> mp; 
int de[mx]; 
int cnt = 0;
class dsu {
    vector<int> pa, size;
public:
    explicit dsu(int n) : pa(n), size(n, 1) {
        iota(pa.begin(), pa.end(), 0);
    }

    int unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        if (size[x] < size[y]) {
            swap(x, y);
        }
        pa[y] = x;
        size[x] += size[y];
        return 1;
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
int getId(string s){
	return mp[s]?mp[s]:mp[s]=++cnt;
}
void solve() {  
	dsu d(mx);
	int count = 0;
    while(cin>>c1>>c2){
    	int l1 = getId(c1);
    	int l2 = getId(c2);
    	count += d.unite(l1,l2);
    	de[l1]++;
    	de[l2]++;
    }
    if(count<cnt-1){
    	cout<<"Impossible"<<endl;return;
    }
    int sum=0;
    for(auto v:de){
    	if(v%2){
    		sum+=1;
    	}
    }
    if(sum!=0&&sum!=2){
    	cout<<"Impossible"<<endl;
    }else{
    	cout<<"Possible"<<endl;
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
