// Problem: E - Yet Another Sigma Problem
// Contest: AtCoder - AtCoder Beginner Contest 353
// URL: https://atcoder.jp/contests/abc353/tasks/abc353_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= int(b); ++i)  
#define rev(i, a, b) for (int i = int(a); i >= (b); --i) 
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
class TrieNode{
public:
    vector<TrieNode*> child;
    vector<int> count;
    bool isWord;
    TrieNode() : child(26, nullptr), isWord(false),count(26,0) {};
    ~TrieNode() {
        for (auto c : child) delete c;
    }
    void insert(string word){
        TrieNode* node = this;
        for(auto c:word){
            if(node->child[c-'a']==nullptr){
                node->child[c-'a'] = new TrieNode();
            }
            node->count[c-'a']++;
            node  = node->child[c-'a'];
        }
        node->isWord = true;
    }
};
  
void solve() {  
    TrieNode* root = new TrieNode();
    int n;cin>>n;
    rep(i,0,n-1){
    	string s;cin>>s;
    	root->insert(s);
    }
    i64 ans =0;
    queue<TrieNode*> q;
    q.push(root);
    while(!q.empty()){
    	auto x = q.front();q.pop();
    	for(int i=0;i<26;i++){
	    	int cnt = x->count[i];
			ans += 1LL*(cnt-1)*cnt/2;
			if(cnt>1){
				q.push(x->child[i]);
			}
	    }
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
    return 0;  
}
