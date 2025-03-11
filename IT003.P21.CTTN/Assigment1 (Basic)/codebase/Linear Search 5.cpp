#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e18;
int n;
int a[200050];
int lmax[200050], lmin[200050];
void Cal()
{
    cin >> n;
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = a[n] - a[1];
    int mx = -inf, mn = inf;
    for (int i = 2 ; i < n ; ++i)
    {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    ans = max(ans, ans + mx - mn);
    cout << ans << '\n';
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test = 1;
    cin >> test;
    while (test--) Cal();

    return 0;
}