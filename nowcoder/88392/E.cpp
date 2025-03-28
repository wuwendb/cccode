// Problem: 约会故事
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/88392/E
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) begin(a),end(a) 
//#define ll long long  
// #define int long long  
using namespace std;  
const int dx[4]{0,0,-1,1};
const int dy[4]{-1,1,0,0};
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
class FenwickTree {
public:
    FenwickTree(int n) : data(n + 1, 0) {}

    void update(int index, int delta) {
        while (index < data.size()) {
            data[index] += delta;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += data[index];
            index -= index & -index;
        }
        return sum;
    }

private:
    vector<int> data;
};
void solve() {  
    int n,m;cin>>n>>m;
    FenwickTree happytime(2400);
    bool happyallday=false;
    set<string> drink;
    rep(i,1,n){
    	string b,e;cin>>b>>e;
    	if(b==e){
    		happyallday = true;
    		continue;
    	}
        b.erase(2,1);
        e.erase(2,1);
		int t1 = stoi(b);
		int t2 = stoi(e);
		if(t1>t2){
			happytime.update(t1,1);
    		happytime.update(2400,-1);
    		happytime.update(1,1);
    		happytime.update(t2+1,-1);
		}else{
			happytime.update(t1,1);
    		happytime.update(t2+1,-1);
		}
    	
    }
    rep(i,1,m){
    	string name;cin>>name;
    	drink.insert(name);
    }
    int q;cin>>q;
    auto check = [&](string time){
    	if(time>"01:59"){
    		return false;
    	}
    	if(happyallday){
    		return true;
    	}
        time.erase(2,1);
        if(happytime.query(stoi(time))){
            return true;
        }
    	return false;
    };
    rep(i,1,q){
    	string time;cin>>time;
        string s1,s2;cin>>s1>>s2;
    	string d;cin>>d;
    	if(!check(time)){
    		cout<<"Loser xqq"<<endl;
    		continue;
    	}
    	if(s1>s2||drink.find(d)==drink.end()){
    		cout<<"Joker xqq"<<endl;
    		continue;
    	}
        cout<<"Winner xqq"<<endl;
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
