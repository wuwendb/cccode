// Problem: P3501 [POI2010] ANT-Antisymmetry
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3501
// Memory Limit: 125 MB
// Time Limit: 1000 ms

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
const int N = 5e5+10;
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
 

hashv h1[N], rh1[N];
void solve() {  
    int n;cin>>n;
    string a;cin>>a;
    string b="";
    inithash();
    rep(i,0,n-1){
    	b.push_back(a[i]=='0'?'1':'0');
    }
    __ha(' '+a,n,h1);
    __rha(' '+b,n,rh1);
    ll sum = 0;
    auto check = [&](int i){
    	int l = 0,r = min(i,n-i)+1;
    	while(l+1<r){
    		int mid = l+r>>1;
    		if(geth(h1,i-mid+1,i+mid)==getrh(rh1,i-mid+1,i+mid)){
    			l = mid;
    		}else{
    			r = mid;
    		}
    	}
    	sum+=l;
    };
    rep(i,1,n-1){//轴，一共n-1条
    	check(i);
    }
    cout<<sum<<endl;
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
