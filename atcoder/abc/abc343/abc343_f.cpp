// Problem: F - Second Largest Query
// Contest: AtCoder - AtCoder Beginner Contest 343
// URL: https://atcoder.jp/contests/abc343/tasks/abc343_f
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
template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Info {
	int ma=0,mcnt=0,se=0,scnt=0;
	Info(){}
	Info(int m,int mc, int s, int sc):ma(m),se(s),mcnt(mc),scnt(sc){}
};

Info operator+(const Info &a, const Info &b) {
	int ma,se,mcnt,scnt;
	if(a.ma==b.ma){
		ma = a.ma;
		mcnt = a.mcnt + b.mcnt;
		if(b.se>a.se){
			se = b.se;
			scnt = b.scnt;
		}else if(b.se<a.se){
			se = a.se;
			scnt = a.scnt;
		}
		if(b.se==a.se){
			se = a.se;
			scnt = a.scnt + b.scnt;
		}
	}else if(a.ma>b.ma){
		if(a.se==b.se||a.se < b.ma){
			se = b.ma;
			scnt = b.mcnt;
		}else if(a.se==b.ma){
			se = a.se;
			scnt = a.scnt + b.mcnt;
		}else{
			se = a.se;
			scnt = a.scnt;
		}
		ma = a.ma;
		mcnt = a.mcnt;
	}else if(a.ma<b.ma){
		if(a.se == b.se || b.se < a.ma){
			se = a.ma;
			scnt = a.mcnt;
		}else if(b.se == a.ma){
			se = a.ma;
			scnt = a.mcnt + b.scnt;
		}else{
			se = b.se;
			scnt = b.scnt;
		}
		ma = b.ma;
		mcnt = b.mcnt;
	}
    return {ma,mcnt,se,scnt};
}
  
void solve() {  
    int n,q;cin>>n>>q;
    vector<int> a(n);
    rep(i,0,n-1) cin>>a[i];
    SegmentTree<Info> seg(n);
    rep(i,0,n-1){
    	seg.modify(i,{a[i],1,0,0});
    }
    
    rep(i,0,q-1){
    	int op,x,y;cin>>op>>x>>y;x--;
    	if(op==1){
    		seg.modify(x,{y,1,0,0});
    	}else{
    		cout<<seg.rangeQuery(x,y).scnt<<endl;
    	}
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
