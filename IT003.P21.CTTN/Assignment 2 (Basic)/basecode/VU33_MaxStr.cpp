#include <bits/stdc++.h>

using namespace std;

int mp[15];

void chance(int & c)
{
    if (c == 1) c = 2;
    else c = 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    char c;
    int sum = 0;
    while (cin >> c)
    {
        mp[c - '0']++;
        (sum += (c - '0')) %= 3;
    }

    if (sum != 0)
    {
        bool ok = 0;
        for (int i = 1 ; i <= 9 ; ++i)
            if (i % 3 == sum && mp[i])
            {
                ok = 1;
                mp[i]--;
                break;
            }
        if (ok)
        {
            for (int i = 9 ; i >= 0 ; --i)
                while (mp[i]--) cout << i;
            return 0;
        }
        chance(sum);
        for (int i = 1 ; i <= 9 ; ++i)
        {
            if (i % 3 == sum && mp[i])
            {
                mp[i]--;
                break;
            }
        }
        for (int i = 1 ; i <= 9 ; ++i)
        {
            if (i % 3 == sum && mp[i])
            {
                mp[i]--;
                break;
            }
        }
    }

    for (int i = 9 ; i >= 0 ; --i)
        while (mp[i]--) cout << i;
    return 0;
}