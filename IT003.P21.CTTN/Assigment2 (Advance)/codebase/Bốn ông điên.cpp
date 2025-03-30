#include <bits/stdc++.h>
#define pii pair < int , int >
#define fi first
#define se second
using namespace std;
const int maxn = 1e5 + 55;

int n;
vector < int > p1[maxn], p2[maxn];
int a[maxn];
vector < int > vi;
int pre[maxn];
int res = 0;

void dfsU(int u, int par)
{
    pre[u] = 1;
    res++;
    for (int i = 0 ; i < p1[u].size() ; ++i)
    {
        int v = p1[u][i];
        if (!pre[v]) dfsU(v, u);
    }
}

int getU()
{
    res = 0;
    for (int i = 1 ; i <= n ; ++i) pre[i] = 0;
    for (int i = 1 ; i <= n ; ++i) if (!pre[i])
    {
        res--;
        dfsU(i, -1);
    }
    return res;
}

void dfsD(int u, int par)
{
    pre[u] = 1;
    res++;
    for (int i = 0 ; i < p2[u].size() ; ++i)
    {
        int v = p2[u][i];
        if (!pre[v]) dfsD(v, u);
    }
}

int getD()
{
    res = 0;
    for (int i = 1 ; i <= n ; ++i) pre[i] = 0;
    for (int i = 1 ; i <= n ; ++i) if (!pre[i])
    {
        res--;
        dfsD(i, -1);
    }
    return res;
}

void solve()
{
    cin >> n;
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
        vi.push_back(a[i]);
    }

    sort(vi.begin(), vi.end());
    vi.resize(unique(vi.begin(), vi.end()) - vi.begin());
    for (int i = 1 ; i <= n ; ++i)
    {
        int x = lower_bound(vi.begin(), vi.end(), a[i]) - vi.begin() + 1;
        p1[i].push_back(x);
        p2[i].push_back(n - x + 1);
    }

    cout << min(getU(), getD()) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test = 1;
//    cin  >> test;
    while (test--) solve();
    return 0;
}