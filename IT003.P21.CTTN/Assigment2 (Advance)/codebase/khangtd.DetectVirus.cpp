#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

const int MAXN = 1e4 + 5;
string s, t;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = s + ' ';
    if (m > n)
    {
        cout << "NO";
        return 0;
    }
    s = ' ' + s;
    t = t;
    vector < int > vi;
    string nw = "";
    for (int i = 1 ; i <= m ; ++i) nw = nw + s[i];
    for (int i = 1 ; i <= n - m + 1 ; ++i)
    {
        if (nw == t) vi.push_back(i);
        nw.erase(0, 1);
        nw = nw + s[i + m];
//        cout << nw << '\n';
    }
    if (vi.size())
    {
        cout << "YES\n";
        for (int i = 0 ; i < vi.size() ; ++i) cout << vi[i] << ' ';
    }
    else cout << "NO\n";
    return 0;
}