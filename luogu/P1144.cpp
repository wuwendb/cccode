// Problem: P1144 最短路计数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1144
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
#define pii pair<int,int>
#define pb push_back
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
template <size_t S> struct Scanner {
    char buf[S], *l = buf, *r = buf;
    bool flush() { l = buf; r = l + fread(buf, 1, S, stdin); return l == r; }
    void get(char& c) { c = l == r && flush() ? ' ' : *l++; }
    friend Scanner& operator >>(Scanner& in, char& c) { return in.get(c), in; }
    friend Scanner& operator >>(Scanner& in, char* s) {
        for (in.get(s[0]); isspace(s[0]); in.get(s[0]));
        for (int i = 0; !isspace(s[i]) || (s[i] = '\0'); i++) in.get(s[i + 1]);
        return in;
    }
    friend Scanner& operator >>(Scanner& in, std::string& s) {
        char c;
        for (in.get(c); isspace(c); in.get(c));
        for (s = ""; !isspace(c); in.get(c)) s += c;
        return in;
    }
    template <class T, std::enable_if_t<std::is_integral_v<T>, int> = 0>
    friend Scanner& operator >>(Scanner& in, T& x) {
        char c, f = '+';
        for (in.get(c); !isdigit(c); in.get(c))
            if constexpr (std::is_signed_v<T>) f = c;
        for (x = 0; isdigit(c); in.get(c)) x = x * 10 + c - '0';
        if constexpr (std::is_signed_v<T>) x = f == '-' ? -x : x;
        return in;
    }
    template <class T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
    friend Scanner& operator >>(Scanner& in, T& x) {
        std::string s; in >> s; x = std::stod(s);
        return in;
    }
    template <class T, class U>
    friend Scanner& operator >>(Scanner& in, std::pair<T, U>& a) {
        return in >> a.first >> a.second;
    }
    template <class T>
    friend Scanner& operator >>(Scanner& in, std::vector<T>& a) {
        for (int i = 0, n = a.size(); i < n; i++) in >> a[i];
        return in;
    }
};
 
template <size_t S> struct Printer {
    char buf[S], *l = buf, *r = buf + S - 1;
    int format = 0, precision = 15;
    ~Printer() { flush(); }
    void flush() { fwrite(buf, 1, l - buf, stdout); l = buf; }
    void put(const char& c) { *l++ = c; if (l == r) flush(); }
    friend Printer& operator <<(Printer& out, const char& c) { return out.put(c), out; }
    friend Printer& operator <<(Printer& out, const char* s) {
        for (int i = 0; s[i] != '\0'; i++) out.put(s[i]);
        return out;
    }
    friend Printer& operator <<(Printer& out, const std::string& s) {
        for (int i = 0, n = s.size(); i < n; i++) out.put(s[i]);
        return out;
    }
    template <class T, std::enable_if_t<std::is_integral_v<T>, int> = 0>
    friend Printer& operator <<(Printer& out, T x) {
        static char s[40];
        static int i = 0;
        if (x == 0) { out.put('0'); return out; }
        if constexpr (std::is_signed_v<T>) x = x < 0 ? out.put('-'), -x : x;
        while (x > 0) s[++i] = x % 10 + '0', x /= 10;
        while (i > 0) out.put(s[i--]);
        return out;
    }
    template <class T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
    friend Printer& operator <<(Printer& out, T x) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(out.precision) << x;
        return out << oss.str();
    }
    template <class T, class U>
    friend Printer& operator <<(Printer& out, const std::pair<T, U>& a) {
        return out << a.first << " \n"[out.format > 1] << a.second;
    }
    template <class T>
    friend Printer& operator <<(Printer& out, const std::vector<T>& a) {
        int n = a.size();
        for (int i = 0; i < n - 1; i++) out << a[i] << " \n"[out.format > 0];
        return n > 0 ? (out << a[n - 1]) : out;
    }
};
 
Scanner<1048576> in;
Printer<1048576> out;
//---------------------------------------------------------  
  
void solve() {  
    int n,m;in>>n>>m;
    vector<vector<int>> g(n+1);
    rep(i,1,m){
    	int u,v;in>>u>>v;
    	g[u].pb(v);
    	g[v].pb(u);
    }
    vector<int> dis(n+1,LLONG_MAX/2);
    vector<int> ans(n+1,0);
    dis[1] = 0,ans[1] =1;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.emplace(0,1);
    while(!pq.empty()){
    	auto [d,u] = pq.top();
    	pq.pop();
    	if(d>dis[u]) continue;
    	for(auto v:g[u]){
    		if(dis[v]>dis[u]+1){
    			dis[v] =dis[u]+1;
    			ans[v] = ans[u];
    			pq.emplace(dis[v],v);
    		}else if(dis[v] == dis[u]+1){
    			ans[v] = (ans[v]+ans[u])%100003;
    		}
    	}
    }
    rep(i,1,n){
    	out<<ans[i]<<endl;
    }
}  
  
signed main() {  
    // ios_base::sync_with_stdio(false);  
    // cin.tie(nullptr);  
    int t=1;  
    // cin >> t; 
    // cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
