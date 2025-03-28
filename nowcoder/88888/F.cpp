// Problem: 小红的数组操作
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88888/F
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
#define ls (node << 1)  
#define rs (node << 1 | 1)  
int a[mx],tree[mx*4];  
  
void pushUp(int node){  
    tree[node]=min(tree[ls],tree[rs]);  
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
  
void update(int node,int start,int end,int l,int r,int val){  
    if(l<=start&&end<=r){  
        tree[node]=val;
        return;  
    }  
    int mid=start+end>>1;  
    if(mid>=l) update(ls,start,mid,l,r,val);  
    if(mid<r) update(rs,mid+1,end,l,r,val);  
    pushUp(node);  
}  
  
int query(int node,int start,int end,int l,int r){  
    if(l<=start&&end<=r) return tree[node];  
    int mid=start+end>>1;
    int ans = 1e9+10;
    if(mid>=l) ans = min(ans,query(ls,start,mid,l,r));
    if(mid<r) ans = min(ans,query(rs,mid+1,end,l,r));  
    return ans;
}
  
void solve() {  
    int n;cin>>n;
    vector<int> nums(n+1);
    nums[0]=0;
    rep(i,1,n){
    	int m;cin>>m;
    	nums[i] = nums[i-1]+m;
    	rep(j,1,m){
    		cin>>a[j+nums[i-1]];
    	}
    }
    int sum = nums[n];
    build(1,1,sum);
    int q;cin>>q;
    rep(k,1,q){
    	int t;cin>>t;
    	if(t==1){
    		int i,j,x;cin>>i>>j>>x;
    		update(1,1,sum,nums[i-1]+j,nums[i-1]+j,x);
    	}else{
    		int i;cin>>i;
    		cout<<query(1,1,sum,1,nums[i])<<endl;
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
