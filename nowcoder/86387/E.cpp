// Problem: 折半丢弃
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/86387/E
// Memory Limit: 524288 MB
// Time Limit: 4000 ms

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
const int mx = 2e6+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
  
void solve() {  
    int n;cin>>n;
    vector<int> a(n);
    rep(i,0,n-1){
    	cin>>a[i];
    }
    auto check = [&](int mid)->bool{
    	unordered_set<int> s;
    	rep(i,0,n-1){
    		int x = a[i];
    		while(x>=mid) x/=2;
    		while(x>0&&s.contains(x)) x/=2;
    		s.insert(x);
    	}
    	return s.size()==mid;
    };
    int l = 0,r = n+1;
    while(l+1<r){
    	int mid = l+r>>1;
    	(check(mid)?l:r)=mid;
    }
    cout<<l<<endl;
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
