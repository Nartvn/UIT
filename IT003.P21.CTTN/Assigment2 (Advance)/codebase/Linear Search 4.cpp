#include <bits/stdc++.h>
#define pii pair < int , int >
#define fi first
#define se second
using namespace std;

int n, k;
map < int , int > mp;

void solve()
{
    mp.clear();
    cin >> n >> k;
    int cp = 0, x;
    int c1 = 0, c2 = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> x;
        if (!mp[x])
        {
            cp++;
            c1++;
            c2++;
        }
        else if (mp[x] == 1) c1--;
        else if (mp[x] == 2) c2--;
        mp[x]++;
    }

    c2 -= c1;
    cp -= (c1 + c2);

    c2 = c2 + cp;

    if (c1 + c2 > 2 * k)
    {
        cout << "NO\n";
        return;
    }

//    cout << c1 << ' ' << c2 << ' ' << cp << '\n';
    int ans = k * 2;

    ans -= min(ans, c1);

//    cout << ans << ' ' << c2 << '\n';
    if ((int)((ans + 1) / 2) <= c2  && c2 <= ans) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test = 1;
    cin  >> test;
    while (test--) solve();
    return 0;
}