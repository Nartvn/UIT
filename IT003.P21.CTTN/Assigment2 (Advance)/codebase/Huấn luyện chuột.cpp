#include <bits/stdc++.h>
#define pii pair < int , int >
#define ll long long
#define int long long
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5 + 55;

int mod;

int frac[MAXN];
int finv[MAXN];

ll power(int u, int e)
{
    if (e == 0) return 1;
    long long val = power(u , e / 2);
    val = (val * val) % mod;
    if (e % 2) return (val * u) % mod;
    return val;
}

void setup()
{
    frac[0] = finv[0] = 1;
	for(int i = 1; i < MAXN; i++) {
		frac[i] = 1LL * frac[i - 1] * i % mod;
		finv[i] = power(frac[i], mod - 2);
	}
}

int comb(int k, int n) {
	if (k > n) return 0;
	return 1LL * frac[n] * finv[k] % mod * finv[n - k] % mod;
}

int lucas(int n, int k)
{
//    cout << n << ' ' << k << '\n';
    int ans = 1;
    while (k || n)
    {
        (ans *= comb(k % mod, n % mod)) %= mod;
        k /= mod;
        n /= mod;
    }
    ans = ans + mod;
    ans %= mod;
    return ans;

}

void solve()

{
    int n;
    cin >> n;
    cout << lucas(n * 2 - 1, n) << '\n';/// 2*n-1 choose n
}



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test = 1;
    cin  >> test;
    cin >> mod;
    setup();
    while (test--) solve();
    return 0;
}