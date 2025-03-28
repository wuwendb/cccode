// Problem: 又是一年毕业季
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88455/D
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

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
const int N = 1e8+10;  
vector<bool> not_prime(N);  
vector<int> prime;  
  
int k=0;  
  
void pre(int n) {  
    for (int i = 2; i <= n; ++i) {  
        if (!not_prime[i]) {  
            prime.push_back(i);  
            if(prime.size()>2e5){
                break;
            }
        }  
        for (int pri_j : prime) {  
            if (i * pri_j > n) break;  
            not_prime[i * pri_j] = true;  
            if (i % pri_j == 0) {  
                break;  
            }  
        }  
    }  
}
int a[mx];
void solve() {  
    int n;cin>>n;
    int a;
    unordered_map<int,int> mp;
    rep(i,1,n){
    	cin>>a;
    	mp[a]=1;
    }
    rep(i,0,mx){
    	if(!mp[prime[i]]){
    		cout<<prime[i]<<endl;
    		return;
    	}
    }
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    pre(N);
    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
