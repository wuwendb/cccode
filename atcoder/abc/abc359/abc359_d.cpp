// Problem: D - Avoid K Palindrome
// Contest: AtCoder - UNIQUE VISION Programming Contest 2024 Summer (AtCoder Beginner Contest 359)
// URL: https://atcoder.jp/contests/abc359/tasks/abc359_d
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
template<typename T>
constexpr T power(T a, u64 b) {
    T res {1};
    for (; b != 0; b /= 2, a *= a) {
        if (b % 2 == 1) {
            res *= a;
        }
    }
    return res;
}

template<u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
    return 1ULL * a * b % P;
}

template<u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

template<typename U, U P>
requires std::unsigned_integral<U>
struct ModIntBase {
public:
    constexpr ModIntBase() : x {0} {}

    template<typename T>
    requires std::integral<T>
    constexpr ModIntBase(T x_) : x {norm(x_ % T {P})} {}

    constexpr static U norm(U x) {
        if ((x >> (8 * sizeof(U) - 1) & 1) == 1) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }

    constexpr U val() const {
        return x;
    }

    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = norm(P - x);
        return res;
    }

    constexpr ModIntBase inv() const {
        return power(*this, P - 2);
    }

    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<P>(x, rhs.val());
        return *this;
    }

    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }

    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }

    constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr ModIntBase operator*(ModIntBase lhs, const ModIntBase &rhs) {
        lhs *= rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator+(ModIntBase lhs, const ModIntBase &rhs) {
        lhs += rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator-(ModIntBase lhs, const ModIntBase &rhs) {
        lhs -= rhs;
        return lhs;
    }

    friend constexpr ModIntBase operator/(ModIntBase lhs, const ModIntBase &rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr std::ostream &operator<<(std::ostream &os, const ModIntBase &a) {
        return os << a.val();
    }

	friend constexpr std::istream &operator>>(std::istream &is, ModIntBase &a) {
    U value;
    is >> value;
    a = ModIntBase(value);
    return is;
}

    friend constexpr bool operator==(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() == rhs.val();
    }

    friend constexpr bool operator!=(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() != rhs.val();
    }

    friend constexpr bool operator<(ModIntBase lhs, ModIntBase rhs) {
        return lhs.val() < rhs.val();
    }

private:
    U x;
};

template<u32 P>
using ModInt = ModIntBase<u32, P>;

template<u64 P>
using ModInt64 = ModIntBase<u64, P>;

constexpr u64 P = 998244353;
using mint = ModInt64<P>;
  
void solve() {  
    int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<bool> isPa(1<<k); 
    rep(i,0,(1<<k)-1){
    	string s = bitset<10>(i).to_string().substr(10-k);
    	string tmp = s;
    	reverse(tmp.begin(),tmp.end());
    	isPa[i] = s==tmp;
    }
    vector<mint> dp(1<<(k-1));
    int mask = (1<<(k-1))-1;
    dp[0]=1;
    rep(i,0,n-1){
    	char c = s[i];
    	vector<mint> dp2(1<<(k-1));
    	rep(j,0,(1<<(k-1))-1){
    		if(c == '?'){
    			if(i+1<k||!isPa[(j<<1)]){
    				auto next = (j<<1)&mask;
    				dp2[next] += dp[j];
    			}
    			if(i+1<k||!isPa[(j<<1)|1]){
    				auto next = ((j<<1)|1)&mask;
    				dp2[next] += dp[j];
    			}
    		}else{
    			if(i+1<k||!isPa[(j<<1)|(c-'A')]){
    				auto next = ((j<<1)|(c-'A'))&mask;
    				dp2[next] += dp[j];
    			}
    		}
    	}
    	dp=move(dp2);
    }
    mint ans = 0;
    rep(i,0,(1<<(k-1))-1){
    	ans += dp[i];
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
