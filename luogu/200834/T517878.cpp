// Problem: T517878 【MX-X6-T0】Arcaea Scoring System
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T517878?contestId=200834
// Memory Limit: 512 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a)
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
//#define ll long long  
#define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    double p1,p0,f,l;cin>>p1>>p0>>f>>l;
    double score = (p1+p0+f/2)/(p1+p0+f+l)*1e7+p1;
    if((int)score>=99e5){
    	cout<<"EX+"<<endl;
    }else if((int)score>=98e5){
    	cout<<"EX"<<endl;
    }else if((int)score>=95e5){
    	cout<<"AA"<<endl;
    }else if((int)score>=92e5){
    	cout<<"A"<<endl;
    }else if((int)score>=89e5){
    	cout<<"B"<<endl;
    }else if((int)score>=86e5){
    	cout<<"C"<<endl;
    }else{
    	cout<<"D"<<endl;
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
