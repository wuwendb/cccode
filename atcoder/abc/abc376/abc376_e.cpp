// Problem: E - Max × Sum
// Contest: AtCoder - AtCoder Beginner Contest 376
// URL: https://atcoder.jp/contests/abc376/tasks/abc376_e
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
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int n,k;cin>>n>>k;
    vector<pii> ab(n);
    rep(i,1,n) cin>>ab[i-1].first;
    rep(i,1,n) cin>>ab[i-1].second;
    ranges::sort(ab,[](auto& p1,auto& p2){
    	return p1.first<p2.first;
    });
    int maxa = 0,sumb = 0;
    priority_queue<int> pq;
    rep(i,0,k-1){
    	maxa = max(maxa,ab[i].first);
    	sumb += ab[i].second;
    	pq.push(ab[i].second);
    }
    int ans = maxa*sumb;
    rep(i,k,n-1){
    	maxa = ab[i].first;
    	auto x = pq.top();pq.pop();
    	sumb += ab[i].second - x;
    	ans = min(ans,maxa*sumb);
    	pq.push(ab[i].second);
    }
    cout<<ans<<endl;
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
