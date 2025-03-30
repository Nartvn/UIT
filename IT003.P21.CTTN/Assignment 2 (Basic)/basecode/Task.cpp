#include <bits/stdc++.h>

using namespace std;

int n, k, p, q;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> p >> q;

    int num = (p - 1) * 2 + (q - 1);

    int ans = -1;

    if (num - k >= 0)
    {
        ans = num - k;
    }

    if (ans == -1 && num + k <= (n - 1))
    {
        ans = num + k;
    }

    if (ans == -1)
    {
        cout << -1;
        return 0;
    }

    cout << ans / 2 + 1 << ' ' << ans % 2 + 1 << '\n';

    return 0;
}