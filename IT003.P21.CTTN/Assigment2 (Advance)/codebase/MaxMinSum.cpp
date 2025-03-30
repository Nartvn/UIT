#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
int n, k;
int a[MAXN];

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

void prepare()
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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
    }

    prepare();
//    cout << comb(2, 10);
//    return 0;
    sort(a + 1, a + n + 1);
    long long ans = 0;
    int cnt = 1;

    for (int i = n ; i >= k ; --i)
    {
        (ans += 1LL * a[i] * comb(k - 1, n - cnt) % mod) %= mod;
        cnt++;
    }
    cnt = 1;
    for (int i = 1 ; i <= (n - k + 1) ; ++i)
    {
        (ans -= (1LL * a[i] * comb(k - 1, n - cnt) % mod)) %= mod;
        cnt++;
    }
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans;
    return 0;
}