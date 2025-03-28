#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int mx = 2e5 + 5;
const int mod = 1e9 + 7;
const int MOD = 998244353;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}


struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>{}(p.first) ^ (hash<T2>{}(p.second) << 1);
    }
};
void solve() {
    int n, m;
    n = read(),m = read();

    unordered_map<pair<int, int>, unordered_set<int>, pair_hash> mapAB;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
		a = read(),b = read(),c = read();
        mapAB[{a, b}].insert(c);
    }
    int ans = 0;
    for (auto& [pair1, c1] : mapAB) {
    	if(c1.size()==1) continue;
        vector<int> c1_vec(c1.begin(), c1.end());
        ranges::sort(c1_vec);
        for (int i = 0; i < c1_vec.size(); ++i) {
            for (int j = i+1; j < c1_vec.size(); ++j) {
            	if(mapAB.count({pair1.first, c1_vec[i]})&&mapAB.count({pair1.second, c1_vec[i]})){
            		if (mapAB[{pair1.first, c1_vec[i]}].contains(c1_vec[j]) && 
	                    mapAB[{pair1.second, c1_vec[i]}].contains(c1_vec[j])) {
	                    ans++;
	                }
            	}
                
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
