// Problem: P1347 排序
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1347
// Memory Limit: 125 MB
// Time Limit: 1000 ms

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
vector<int> g[mx];
int inde[mx],outde[mx],inde2[mx],outde2[mx];
int n,m;
queue<int> q;
vector<int> ans;
void topo(int t){
	ans.clear();
	int cnt = 0;
	bool flag = true;
	rep(i,0,n-1){
		inde2[i]=inde[i];
		outde2[i]=outde[i];
		if(inde2[i]==0&&outde2[i]!=0){
			q.push(i);
			cnt++;
			ans.push_back(i);
			if(cnt>=2){
				flag=false;
			}
		}
	}
	while(!q.empty()){
		int f = q.front();
		q.pop();
		if(!q.empty()){
			flag = false;
		}
		for(auto i:g[f]){
			inde2[i]--;outde2[f]--;
			if(inde2[i]==0){
				q.push(i);
				cnt++;
				ans.push_back(i);
			}
		}
	}
	rep(i,0,n-1){
		if(inde2[i]!=0||outde2[i]!=0){
			cout<<"Inconsistency found after "<<t<<" relations."<<endl;
			exit(0);
		}
	}
	if(cnt==n) {
		if(flag){
			cout<<"Sorted sequence determined after "<<t<<" relations: ";
			rep(i,1,n){
				cout<<(char)(ans[i-1]+'A');
			}
			cout<<"."<<endl;
			exit(0);
		}else if(t==m){
			cout<<"Sorted sequence cannot be determined."<<endl;
		}
	}else if(t==m){
		cout<<"Sorted sequence cannot be determined."<<endl;
	}else{
		return;
	}
	
	
}  
void solve() {  
    cin>>n>>m;
    rep(i,1,m){
    	char c1,c2,c3;cin>>c1>>c3>>c2;
    	if(c1==c2){
    		cout<<"Inconsistency found after "<<i<<" relations."<<endl;
    		return;
    	}
    	g[c1-'A'].push_back(c2-'A');
    	inde[c2-'A']++;
    	outde[c1-'A']++;
    	topo(i);
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
