// Problem: 区间
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87865/E
// Memory Limit: 524288 MB
// Time Limit: 4000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i)  
//#define ll long long  
#define int long long  
using namespace std;  
const int mx = 1e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------
#define ls (node << 1)  
#define rs (node << 1 | 1)  
int a[mx],tree[mx*4],lm[mx*4],rm[mx*4];  
  
void pushUp(int node,int start,int end){
	int mid = start+end>>1;
	lm[node]=(lm[ls]==mid-start+1)?lm[ls]+lm[rs]:lm[ls]; 
	rm[node] = (end-mid==rm[rs])?rm[ls]+rm[rs]:rm[rs];
    tree[node]	= max({tree[ls],tree[rs],lm[rs]+rm[ls]});
}  
  
void build(int node,int start,int end){  
    if(start==end){  
        tree[node]=1;  
        lm[node]=rm[node]=1;
        return;  
    }  
    int mid=start+end>>1;  
    build(ls,start,mid);  
    build(rs,mid+1,end);  
    pushUp(node,start,end);  
}  
  
void add(int node,int start,int end,int idx){  
    if(start==end) {  
    	tree[node] =lm[node] =rm[node] = tree[node]==0; 
        return;  
    }  
    int mid=start+end>>1;  
    if(idx<=mid) add(ls,start,mid,idx);  
    if(idx>mid) add(rs,mid+1,end,idx);  
    pushUp(node,start,end);  
}  
  
array<int,3> query(int node,int start,int end,int l,int r){  
    if(l<=start&&end<=r) return {tree[node],lm[node],rm[node]}; 
    int mid=start+end>>1;   
    if(l>mid) return query(rs,mid+1,end,l,r);
    else if(r<=mid) return query(ls,start,mid,l,r); 
    else{
    	auto a1 = query(ls,start,mid,l,mid);
    	auto a2 = query(rs,mid+1,end,mid+1,r);
    	return {max({a1[0],a2[0],a1[2]+a2[1]}), (a1[1]==mid-l+1)?a1[1]+a2[1]:a1[1], (a2[2]==r-mid)?a2[2]+a1[2]:a2[2]};
    					
    }
}  
  
void solve() {  
    int n,q;
    cin>>n>>q;
    build(1,1,n);
    int op,x,l,r;
    rep(_,1,q){
    	cin>>op;
    	if(op==1){
    		cin>>x;
    		add(1,1,n,x);
    	}else{
    		cin>>l>>r;
    		cout<<query(1,1,n,l,r)[0]<<endl;
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
