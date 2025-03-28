// Problem: Picture 
// Contest: HDOJ
// URL: https://acm.hdu.edu.cn/showproblem.php?pid=1828
// Memory Limit: 32 MB
// Time Limit: 6000 ms

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
bool lbd[mx*4],rbd[mx*4];
int num[mx*4];
int length[mx*4];
int tag[mx*4]; 
struct ScanLine{
	int y;
	int right_x,left_x;
	int inout;
	ScanLine(){}
	ScanLine(int y,int x2,int x1,int io):y(y),right_x(x2),left_x(x1),inout(io){}
}line[mx];
bool cmp(ScanLine &a,ScanLine &b){return a.y<b.y||(a.y==b.y&&a.inout>b.inout);}  
void pushUp(int node,int start,int end){  
	if(tag[node]){
		lbd[node] =rbd[node] = 1;
		length[node] = end-start+1;
		num[node] = 1;
		
	} 
	else if(start==end) length[node] = num[node] = lbd[node] = rbd[node] = 0;
	else{
		lbd[node] = lbd[ls];
		rbd[node] = rbd[rs];
		length[node] = length[ls]+length[rs];
		num[node] = num[ls]+num[rs];
		if(lbd[rs]&&rbd[ls]) num[node]-=1;
	} 
}  
  
void add(int node,int start,int end,int l,int r,int io){  
    if(l<=start&&end<=r){  
        tag[node] += io;
        pushUp(node,start,end);  
        return;  
    }
    int mid=start+end>>1;  
    if(l<=mid) add(ls,start,mid,l,r,io);  
    if(r>mid) add(rs,mid+1,end,l,r,io);  
    pushUp(node,start,end);  
}  
  
void solve() {  
    int n;
    cin>>n;
    int cnt = 0;
    int lbd = 1000,rbd =-1000;
    while(n--){
    	int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
    	lbd = min(lbd,x1);
    	rbd = max(rbd,x2);
    	line[++cnt] = ScanLine(y1,x2,x1,1);
    	line[++cnt] = ScanLine(y2,x2,x1,-1);
    }
    if(lbd<=0){
    	rep(i,1,cnt){
    		line[i].left_x += -lbd+1;
    		line[i].right_x += -lbd+1;
    	}
    	rbd -= lbd;
    }
    sort(line+1,line+cnt+1,cmp);
    int ans = 0,last = 0;
    rep(i,1,cnt){
		add(1,1,rbd,line[i].left_x,line[i].right_x-1,line[i].inout);
    	ans += num[1]*2*(line[i+1].y-line[i].y);
    	ans += abs(last - length[1]);
    	last = length[1];
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
