#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[20000];
int32_t main()
{
    int x;
    cin >> n;
    int first = -1, last = -1;
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
    }
    cin >> x;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (a[i] == x && first == -1) first = i;
        if (a[i] == x) last = i;
    }
    if (first == -1) return cout << -1, 0;
    cout << first - 1 << '\n';
    
    cout << first << '\n';
    cout << n - last << '\n';
    cout << n - last + 1 << '\n';
    return 0;
}