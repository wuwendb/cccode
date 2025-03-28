// Problem: A*BBBB
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/87255/D
// Memory Limit: 524288 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>  
#define endl "\n"  
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)  
#define rev(i, a, b) for (int i = (a); i >= (b); --i) 
#define all(a) (a).begin(),(a).end() 
#define ll long long  
// #define int long long  
using namespace std;  
const int mx = 2e5+5;  
const int mod = 1e9+7;  
const int MOD = 998244353;  
//---------------------------------------------------------  
#define complex complex<double>
const int N = 4e6 + 5;
const double PI = acos(-1);
int __ = 1, n = 0, m;
int R[N];
complex A[N], B[N];
void change(complex A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        R[i] = R[i / 2] / 2 + (i & 1) * n / 2;
    }
    for (int i = 0; i < n; i++)
    {
        if (i < R[i])
            swap(A[i], A[R[i]]);
    }
}
void FFT(complex A[], int n, int op)
{
    change(A, n);
    for (int m = 2; m <= n; m <<= 1)
    {
        complex w1(cos(2 * PI / m), op * sin(2 * PI / m));
        for (int i = 0; i < n; i += m)
        {
            complex w(1, 0);
            for (int j = 0; j < m / 2; j++, w = w * w1)
            {
                complex u = A[i + j], v = w * A[i + j + m / 2];
                A[i + j] = u + v, A[i + j + m / 2] = u - v;
            }
        }
    }
}
void bigStrMul(string a,string b)
{
    n = a.size() - 1, m = b.size() - 1;
    for (int i = 0; i <= n; i++)
        A[i] = a[n - i] - '0';
    for (int i = 0; i <= m; i++)
        B[i] = b[m - i] - '0';
    for (m = n + m, n = 1; n <= m; n <<= 1)
        ;
    FFT(A, n, 1), FFT(B, n, 1);
    for (int i = 0; i < n; i++)
        A[i] *= B[i];
    FFT(A, n, -1);
    vector<int> ans;
    for (int i = 0, t = 0; i < n || t; i++)
    {
        t += A[i].real() / n + 0.5;
        ans.push_back(t % 10);
        t /= 10;
    }
    while (ans.size() > 1 && ans.back() == 0)
        ans.pop_back();
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << endl;
    for (int i = 0; i < n; i++)
        A[i] = B[i] = R[i] = 0;
    return;
}
                        
void solve() {  
    string s1,s2;cin>>s1>>s2;
    bigStrMul(s1,s2);
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
