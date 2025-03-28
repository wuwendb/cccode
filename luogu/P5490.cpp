// Problem: P5490 【模板】扫描线 & 矩形面积并
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5490
// Memory Limit: 512 MB
// Time Limit: 1000 ms

//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#define endl "\n"
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rev(i, a, b) for (int i = (a); i >= (b); --i)
// #define ll long long
#define int long long
using namespace std;
const int mx = 2e5+5;
const int mod = 1e9+7;
const int MOD = 998244353;
//---------------------------------------------------------
#define ls (node << 1)  
#define rs (node << 1 | 1)  
int length[mx*4];
int tag[mx*4]; 
int xx[mx];
struct ScanLine{
	int y;
	int right_x,left_x;
	int inout;
	ScanLine(){}
	ScanLine(int y,int x2,int x1,int io):y(y),right_x(x2),left_x(x1),inout(io){}
}line[mx];
bool cmp(ScanLine &a,ScanLine &b){return a.y<b.y;}  
void pushUp(int node,int start,int end){  
	if(tag[node]) length[node] = xx[end]-xx[start];
	else if(start+1==end) length[node] = 0;
	else length[node] = length[ls]+length[rs];
}  
  
void add(int node,int start,int end,int l,int r,int io){  
    if(l<=start&&end<=r){  
        tag[node] += io;
        pushUp(node,start,end);  
        return;  
    }
    if(start+1==end) return;
    int mid=start+end>>1;  
    if(l<=mid) add(ls,start,mid,l,r,io);  
    if(r>mid) add(rs,mid,end,l,r,io);  
    pushUp(node,start,end);  
}  


void solve(){
    int n;cin>>n;
    int x1,y1,x2,y2,cnt=0;
    for(int i = 1; i <= n; i++){
        cin>>x1>>y1>>x2>>y2;
        line[++cnt] = ScanLine(y1,x2,x1,1);
    	xx[cnt] = x1;
    	line[++cnt] = ScanLine(y2,x2,x1,-1);
    	xx[cnt] = x2;
    }
    sort(line + 1, line + cnt +1,cmp);
    sort(xx + 1, xx + cnt + 1);
    int num = unique(xx + 1, xx + cnt + 1) - (xx + 1);
    int ans = 0;
    rep(i,1,cnt){
        ans += length[1]*(line[i].y-line[i-1].y);
		int l = lower_bound(xx+1,xx+num+1,line[i].left_x)-xx;
    	int r = lower_bound(xx+1,xx+num+1,line[i].right_x)-xx;
    	add(1,1,num,l,r,line[i].inout);
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
}