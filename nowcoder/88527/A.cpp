// Problem: 日历游戏
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88527/A
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
int days[14]{0,31,28,31,30,31,30,31,31,30,31,30,31,0};
int tx=24,ty=8,tz=1;
bool check(int year,int month){
	return (year%400==0||year%4==0&&year%100!=0)&&month==2;
}
int f[30][20][40];
int sg(int x,int y,int z){
	if(x==tx){
		if(y>ty||y==ty&&z>tz) return f[x][y][z] = 1;
		if(y==ty&&z&&tz) return f[x][y][z] = 0;
	}
	if(f[x][y][z]!=-1) return f[x][y][z];
	unordered_set<int> s;
	if(z==days[y]+check(x,y)){
		if(y!=12) s.insert(sg(x,y+1,1));
		else s.insert(sg(x+1,1,1));
	}
	if(z<days[y]+check(x,y)){
		s.insert(sg(x,y,z+1));
	}
	if(y!=12&&z<=days[y+1]) s.insert(sg(x,y+1,z));
	if(y==12) s.insert(sg(x+1,1,z));
	for(int i=0;;i++){
		if(s.count(i)==0) return f[x][y][z] = i;
	}
	
}
void solve() {  
	int year,month,day;
    cin>>year>>month>>day;
    year-=2000;
    memset(f,-1,sizeof(f));
    cout<<(sg(year,month,day)!=0?"YES":"NO")<<endl;
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
    // cout<<pow(2,22)<<endl;  
    return 0;  
}
