// Problem: D - Go Stone Puzzle
// Contest: AtCoder - Denso Create Programming Contest 2024（AtCoder Beginner Contest 361）
// URL: https://atcoder.jp/contests/abc361/tasks/abc361_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
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

  
void solve() {  
    int n;cin>>n;
    string s,t;cin>>s>>t;
    vector<int> st(n+2,2),ed(n+2,2);
    rep(i,0,n-1) st[i]=s[i]=='B',ed[i]=t[i]=='B';
    queue<vector<int>> q;
    map<vector<int>,int> mp;
    q.push(st);
    mp[st]=0;
    while(!q.empty()){
    	auto x = q.front();q.pop();
    	if(x==ed){
    		break;
    	}
    	auto pos = find(x.begin(),x.end(),2)-x.begin();
    	rep(i,0,n){
    		auto y = x;
    		if(y[i]!=2&&y[i+1]!=2){
    			swap(y[i],y[pos]);
    			swap(y[i+1],y[pos+1]);
    			if(!mp.contains(y)){
	    			q.push(y);
	    			mp[y]=mp[x]+1;
    			}
    		}
    	}
    }
    if(mp.contains(ed)) cout<<mp[ed]<<endl;
    else cout<<-1<<endl;
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
