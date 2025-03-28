// Problem: D - Strange Mirroring
// Contest: AtCoder - AtCoder Beginner Contest 380
// URL: https://atcoder.jp/contests/abc380/tasks/abc380_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= int(b); ++i)  
#define rev(i, a, b) for (int i = int(a); i >= (b); --i) 
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
    string s;cin>>s;
    i64 q,k;cin>>q;
    int n = s.size();
    vector<i64> a{0};
    for(i64 i=1;;i++){
    	a.pb(a.back()+i*n);
    	if(a.back()>1000000000){
    		break;
    	}
    }
    rep(i,0,q-1){
    	cin>>k;
    	if(k<=n){
    		cout<<s[k-1]<<" \n"[i==q-1];
    		continue;
    	}
		k-=n+1;	
    	int j = ranges::upper_bound(a,k)-a.begin();
    	k-=a[j-1];
    	int t = k/n;
    	char ch = s[k%n];
    	if(t%2==0){
    		ch = islower(ch) ? toupper(ch) : tolower(ch);
    	}
    	cout<<ch<<" \n"[i==q-1];
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
    return 0;  
}
