#include <bits/stdc++.h>

using namespace std;

struct node
{
    int l, r, id;
    node(int a = 0, int b = 0, int c = 0) : l(a), r(b), id(c) {};
} a[100055];
int m, n;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int first = 1, last = n;
    for (int i = 1 ; i <= n ; ++i) a[i] = node(i - 1, i + 1, i);
    while (m--)
    {
        int x;
        cin >> x;
        if (x != first)
        {
            int pre = a[x].l;
            int nxt = a[x].r;

            a[pre].r = nxt;
            a[nxt].l = pre;

            a[first].l = x;

            a[x].r = first;
            a[x].l = 0;

            first = x;

            if (x == last) last = pre;
        }
        /// << last << ' ';
    }
    while (first != n + 1) cout << first << ' ', first = a[first].r;
    return 0;
}