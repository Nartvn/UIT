#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 55;

int mod;
int n, a[MAXN];

void merge(int l, int r, int mid)
{
    sort(a + l, a + r + 1);
    for (int i = 1 ; i < l ; ++i) cout << a[i] << ' ';
    cout << "[ ";
    for (int i = l ; i <= r ; ++i) cout << a[i] << ' ';
    cout << "] ";
    for (int i = r + 1 ; i <= n ; ++i) cout << a[i] << ' ';
    cout << '\n';
}

void mergesort(int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, r, mid);
}

void solve()
{
    cin >> n;
    for (int i = 1 ; i <= n ; ++i) cin >> a[i];
    mergesort(1, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test = 1;
    while (test--) solve();
    return 0;
}