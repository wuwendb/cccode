// Problem: 虫洞操纵者
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87656/D
// Memory Limit: 1048576 MB
// Time Limit: 4000 ms

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
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
  
void solve() {  
    int n;cin>>n;
    vector<vector<int>> a(n+2,vector<int>(n+2,1));
    rep(i,1,n){
    	rep(j,1,n){
			cin>>a[i][j];
    	}
    }
    vector<vector<int>> path((1010<<10)+1010);
    rep(i,1,n){
    	rep(j,1,n){
    		if(a[i][j]==0){
    			int site = (i<<10)+j;
    			if(a[i+1][j]==1){
    				rev(k,i-1,0){
    					if(a[k][j]==1){
    						path[site].push_back((k+1<<10)+j);
   						 	break;
    					}
    				}
    			}
    			if(a[i-1][j]==1){
    				rep(k,i+1,n+1){
    					if(a[k][j]==1){
    						path[site].push_back((k-1<<10)+j);
    						break;
    					} 
    				}
    			}
    			if(a[i][j+1]==1){
    				rev(k,j-1,0){
    					if(a[i][k]==1){
    						path[site].push_back((i<<10)+k+1);
    						break;
    					} 
    				}
    				
    			}
    			if(a[i][j-1]==1){
    				rep(k,j+1,n+1){
    					if(a[i][k]==1){
    						path[site].push_back((i<<10)+k-1);
    						break;
    					} 
    				}
    			}
    			rep(idx,0,3){
		    		int newx = i+dx[idx],newy = j+dy[idx];
		    		int newsite = (newx<<10)+newy;
		    		if(a[newx][newy]==0){
		    			path[site].push_back(newsite);
		    		}
		    	}
    		}
    	}
    }
    auto shortestPath = [&](int start, int end)->int {
	    // dis[i] 表示从起点 start 出发，到节点 i 的最短路长度
	    vector<int> dis((1010<<10)+1010, INT_MAX);
	    dis[start] = 0;
	    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	    pq.emplace(0, start);
	    while (!pq.empty()) {
	        auto [d, x] = pq.top();
	        pq.pop();
	        if (x == end) { // 计算出从起点到终点的最短路长度
	            return d;
	        }
	        if (d > dis[x]) { // x 之前出堆过，无需更新邻居的最短路
	            continue;
	        }
	        for (auto &y : path[x]) {
	            if (d + 1 < dis[y]) {
	                dis[y] = d + 1; // 更新最短路长度
	                pq.push({dis[y], y});
	            }
	        }
	    }
	    return -1; // 无法到达终点
	};
    cout<<shortestPath((1<<10)+1,(n<<10)+n)<<endl;
}  
  
signed main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t=1;  
//    cin >> t; 
    cout<<fixed<<setprecision(1); 
    while (t--) {  
        solve();  
    }  
//    cout<<pow(2,22)<<endl;  
    return 0;  
}
