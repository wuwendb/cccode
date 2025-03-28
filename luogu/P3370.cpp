// Problem: P3370 【模板】字符串哈希
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3370
// Memory Limit: 128 MB
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
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
namespace Hash{
    typedef unsigned long long ull;
    struct node{ull hash1,hash2;}a[10010];
    const int mod1=19260817;const int mod2=2333333333;
    inline void gethash1(int pos,string s){
        int len=s.size();ull tmp=0;
        for(int i=0;i<len;i++)
            tmp=(tmp*255+s[i])%mod1;
        a[pos].hash1=tmp;
    }
    inline void gethash2(int pos,string s){
        int len=s.size();ull tmp=0;
        for(int i=0;i<len;i++)
            tmp=(tmp*255+s[i])%mod2;
        a[pos].hash2=tmp;
    }
    inline void get_hash(int pos,string s){gethash1(pos,s);gethash2(pos,s);}
    inline bool cmp(node x,node y){return x.hash1<y.hash1||(x.hash1==y.hash1&&x.hash2<y.hash2);}
    bool operator != (node x,node y){return !((x.hash1==y.hash1)&&(x.hash2==y.hash2));}
    bool operator == (node x,node y){return (x.hash1==y.hash1)&&(x.hash2==y.hash2);}
}
using namespace Hash;
  
void solve() {  
    int n;cin>>n;
    rep(i,1,n){
    	string s;cin>>s;
    	get_hash(i,s);
    }
    ranges::sort(a+1,a+1+n,cmp);
    int ans = n;
    rep(i,2,n){
    	if(a[i]==a[i-1]){
    		ans--;
    	}
    }
    cout<<ans<<endl;
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
