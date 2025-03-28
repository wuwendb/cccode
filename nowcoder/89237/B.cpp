// Problem: 百变吗喽
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/89237/B
// Memory Limit: 1048576 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
#define ll long long  
// #define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
// 双哈希 
const int N = 1e6+10;
typedef pair<ll, ll> hashv;
const ll base1 = 233333, mod1 = 1222827239;
const ll base2 = 131313, mod2 = 1610612741;
hashv base = make_pair(base1, base2);
 
hashv operator+(hashv a, hashv b) {ll h1 = a.first + b.first, h2 = a.second + b.second;  if (h1 >= mod1) h1 -= mod1;  if (h2 >= mod2) h2 -= mod2;  return make_pair(h1, h2);}
 
hashv operator-(hashv a, hashv b) {ll h1 = a.first - b.first, h2 = a.second - b.second;  if (h1 < 0) h1 += mod1;  if (h2 < 0) h2 += mod2;  return make_pair(h1, h2);}
 
hashv operator*(hashv a, hashv b) {ll h1 = a.first * b.first, h2 = a.second * b.second;  if (h1 >= mod1) h1 %= mod1;  if (h2 >= mod2) h2 %= mod2;  return make_pair(h1, h2);}
 
hashv operator+(hashv a, ll b) {ll h1 = a.first + b, h2 = a.second + b;  if (h1 >= mod1) h1 -= mod1;  if (h2 >= mod2) h2 -= mod2;  return make_pair(h1, h2);}
 
hashv operator-(hashv a, ll b) {ll h1 = a.first - b, h2 = a.second - b;  if (h1 < 0) h1 += mod1;  if (h2 < 0) h2 += mod2;  return make_pair(h1, h2);}
 
hashv operator*(hashv a, ll b) {ll h1 = a.first * b, h2 = a.second * b;  if (h1 >= mod1) h1 %= mod1;  if (h2 >= mod2) h2 %= mod2;  return make_pair(h1, h2);}
 
bool operator==(hashv a, hashv b) {return (a.first == b.first) && (a.second == b.second);}
 
hashv hp[N];
inline void inithash() {
	hp[0] = make_pair(1ll, 1ll);
	for (int i = 1; i < N; i ++) hp[i] = hp[i - 1] * base;
}
// 前缀哈希计算 
inline void __ha(string s, int n, hashv ha[]) {  for (int i = 1; i <= n; i ++) ha[i] = ha[i - 1] * base + s[i] - 'a' + 1;}
 
inline hashv geth(hashv ha[], int l, int r) {  return ha[r] - ha[l - 1] * hp[r - l + 1];}
 
// 后缀哈希计算
inline void __rha(string s, int n, hashv ha[]) {  for (int i = n; i >= 1; i --) ha[i] = ha[i + 1] * base + s[i] - 'a' + 1;}
 
inline hashv getrh(hashv ha[], int l, int r) {  return ha[l] - ha[r + 1] * hp[r - l + 1];}
 
// 判断回文串
inline bool is_pp(hashv ha[], hashv rha[], int l, int r) {  return geth(ha, l, r) == getrh(rha, l, r);}
 

hashv h1[N], h2[N];
void solve() {  
    string s,t;cin>>s>>t;
    int n = s.length();
    inithash();
    __ha(' '+s,n,h1);
    __ha(' '+t,n+1,h2);
    vector<pair<int,char>> ans;
    if(geth(h1,1,n)==geth(h2,2,n+1)){
    	ans.emplace_back(0,t[0]);
    }
    rep(i,1,n+1){
    	if(geth(h1,1,i)==geth(h2,1,i) && geth(h1,i+1,n) == geth(h2,i+2,n+1)){
    		ans.emplace_back(i,t[i]);
    	}
    }
    cout<<ans.size()<<endl;
    for(auto [i,c]:ans){
    	cout<<i<<" "<<c<<endl;
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
