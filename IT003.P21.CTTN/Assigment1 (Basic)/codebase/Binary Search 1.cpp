#include <bits/stdc++.h>

using namespace std;

int n, a[50000];
int32_t main()
{
    int x;
    cin >> n;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> a[i];
    }
    cin >> x;
    int l = 0, r = n - 1;
    int res = -1, cnt = 0;
    while (l <= r)
    {
        cnt++;
        int mid = floor((l + r) / 2);
        if (a[mid] < x)
            l = mid + 1;
        else if (a[mid] > x)
            r = mid - 1;
        else{
            res = mid;
            break;}
       /// cout << mid << ' ' << l << ' ' << r << endl;
        ///if (a[l] > x || a[r] < x) break;
    }
    cout << res << '\n';
    if (res != -1)
    {
        cout << cnt;
    }
    return 0;
}