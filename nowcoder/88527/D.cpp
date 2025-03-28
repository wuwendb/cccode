// Problem: 区间问题1
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88527/D
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
#define ls (node << 1)  
#define rs (node << 1 | 1)  
int a[mx],tree[mx*4],lazy[mx*4];  
  
void pushUp(int node){  
    tree[node]=tree[ls]+tree[rs];  
}  
  
void build(int node,int start,int end){  
    if(start==end){  
        tree[node]=a[start];  
        return;  
    }  
    int mid=start+end>>1;  
    build(ls,start,mid);  
    build(rs,mid+1,end);  
    pushUp(node);  
}  
  
void pushDown(int node,int start,int end){  
    int mid = start+end>>1;  
    lazy[ls] += lazy[node];  
    lazy[rs] += lazy[node];  
    tree[ls] += lazy[node]*(mid-start+1);  
    tree[rs] += lazy[node]*(end-mid);  
    lazy[node] = 0;  
}  
  
void add(int node,int start,int end,int l,int r,int val){  
    if(l<=start&&end<=r){  
        tree[node]+=(end-start+1)*val;  
        lazy[node]+=val;  
        return;  
    }  
    if(lazy[node]!=0){  
        pushDown(node,start,end);  
    }  
    int mid=start+end>>1;  
    if(l<=mid) add(ls,start,mid,l,r,val);  
    if(r>mid) add(rs,mid+1,end,l,r,val);  
    pushUp(node);  
}  
  
int query(int node,int start,int end,int l,int r){  
    if(l<=start&&end<=r) return tree[node];  
    if(lazy[node]!=0){  
        pushDown(node,start,end);  
    }  
    int mid=start+end>>1;  
    int res=0;  
    if(l<=mid) res+=query(ls,start,mid,l,r);  
    if(r>mid) res+=query(rs,mid+1,end,l,r);  
    return res;  
}
  
void solve() {  
    int n;cin>>n;
    rep(i,1,n){
    	cin>>a[i];
    }
    build(1,1,n);
    int q;cin>>q;
    rep(i,1,q){
    	int op;cin>>op;
    	if(op==1){
    		int l,r,d;cin>>l>>r>>d;
    		add(1,1,n,l,r,d);
    	}else{
    		int x;cin>>x;
    		cout<<query(1,1,n,x,x)<<endl;
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
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
