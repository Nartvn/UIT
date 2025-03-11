#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, x;
vector < int > vi;
int32_t main()
{
    cin >> n >> x;
    for (int i = 1 ;  i <= n ; ++i)
    {
        int a;
        cin >> a;
        vi.push_back(a);
    }
    int ans = 0;
    sort(vi.begin(), vi.end());
    for (int i = 1 ; i < (int)vi.size() ; ++i)
    {
        int val = vi[i];
        int l = 0, r = i - 1, val2 = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (vi[mid] + val <= x)
            {
                l = mid + 1;
                val2 = mid;
            }
            else r = mid - 1;
        }
        if (val + vi[val2] <= x) ans = max(ans, val + vi[val2]);
    }
    cout << ans;
    return 0;
}