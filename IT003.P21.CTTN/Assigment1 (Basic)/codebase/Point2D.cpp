#include <bits/stdc++.h>
#define pii pair < int , int >
#define fi first
#define se second
using namespace std;

bool cmp(pii a, pii b)
{
    if (a.fi == b.fi) return a.se > b.se;
    return a.fi < b.fi;
}
vector < pii > vi;
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1;  i <= n ; ++i)
    {
        int x, y;
        cin >> x >> y;
        vi.push_back(pii(x, y));
    }
    sort(vi.begin(), vi.end(), cmp);
    for (int i = 0 ; i < vi.size() ; ++i)
        cout << vi[i].fi << ' ' << vi[i].se << '\n';
    return 0;
}