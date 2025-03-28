// Problem: SSH
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87865/L
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i)  
//#define ll long long  
#define int long long  
using namespace std;  
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

  
void solve() {  
    int m,n,q;
    cin>>m>>n>>q;
    unordered_map<string,string> pubpri;
    string pub,pri;
    while(m--){
    	cin>>pub>>pri;
    	pubpri[pri]=pub;
    }
    unordered_map<string,set<string>> clients;
    unordered_map<string,set<string>> userspub;
    string ip;int users;
    while(n--){
    	cin>>ip>>users;
    	string name;
    	int pubnums;
    	while(users--){
    		cin>>name>>pubnums;
    		clients[ip].insert(name);
    		string userspubname;
    		while(pubnums--){
    			cin>>userspubname;
    			userspub[name].insert(userspubname);
    		}
    	}
    }
    string queryname,queryip,querypri;
    while(q--){
    	cin>>queryname>>queryip>>querypri;
    	if(clients[queryip].count(queryname)
    		&& userspub[queryname].count(pubpri[querypri])){
    		cout<<"Yes\n";
    	}else{
    		cout<<"No\n";
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
