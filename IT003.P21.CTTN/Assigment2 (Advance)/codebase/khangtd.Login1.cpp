#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

const int MAXN = 1e4 + 5;
int n, q;
map < string, string > mp;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    string s, t;
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> s >> t;
        mp[s] = t;
    }
    while (q--)
    {
        cin >> s;
        if (mp[s] != "") cout << mp[s] << '\n';
        else cout << "Chua Dang Ky!\n";
    }
    return 0;
}