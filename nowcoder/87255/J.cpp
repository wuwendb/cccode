// Problem: 这是签到
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87255/J
// Memory Limit: 2097152 MB
// Time Limit: 10000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) (a).begin(),(a).end() 
//#define ll long long  
#define int long long  
using namespace std;  
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  

int determinant(vector<vector<int>> matrix,int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int det = 0;

    for (int i = 0; i < n; ++i) {
        // 创建子矩阵
        vector<vector<int>> subMatrix(n - 1, vector<int>(n - 1));

        for (int j = 1; j < n; ++j) {
            int subCol = 0;
            for (int k = 0; k < n; ++k) {
                if (k == i) {
                    continue;
                }
                subMatrix[j - 1][subCol] = matrix[j][k];
                ++subCol;
            }
        }
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(subMatrix,n-1);
    }

    return det;
}
void solve() {  
    int n,m;cin>>n>>m;
    int nn = max(n,m);
    vector<vector<int>> g(nn,vector<int>(nn,0));
    rep(i,0,n-1){
    	rep(j,0,m-1){
    		cin>>g[i][j];
    	}
    }
    int ans = LLONG_MAX;
    rep(k,1,nn){
    	ans = min(ans,determinant(g,k));
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
