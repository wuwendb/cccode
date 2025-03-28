// Problem: E - Remove Pairs
// Contest: AtCoder - Panasonic Programming Contest 2024（AtCoder Beginner Contest 354）
// URL: https://atcoder.jp/contests/abc354/tasks/abc354_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using namespace std;  

const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n;cin>>n;
    vector<int> a(n),b(n);
    rep(i,0,n-1) cin>>a[i]>>b[i];
    vector<int> f(1<<n,-1);
    auto sg = [&](auto self,int x)->int{
    	if(f[x]!=-1) return f[x];
    	vector<int> v;
    	for(int j=0;j<n;j++){
    		if((x>>j)&1){
    			continue;
    		}
    		v.pb(j);
    	}
    	unordered_set<int> st;
    	int len = v.size();
    	rep(i,0,len-2){
    		rep(j,i+1,len-1){
    			int f =v[i],s = v[j];
    			if(a[f]==a[s]||b[f]==b[s]){
    				st.insert(self(self,x|(1<<f)|(1<<s)));
    			}
    		}
    	}
    	for(int i=0;;i++){
    		if(!st.contains(i)){
    			return f[x] = i;
    		}
    	}
    };
    cout<<(sg(sg,0)!=0?"Takahashi":"Aoki")<<endl;
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
    return 0;  
}
