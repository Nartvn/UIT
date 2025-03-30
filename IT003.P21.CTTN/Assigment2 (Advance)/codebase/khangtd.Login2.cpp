#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

const int MAXN = 1e4 + 5;
int n, q;
map < string, int > mp;
vector < vector < string > > vi;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    string s, t;
    int cnt = 1;
    vector < string > n0;
    vi.push_back(n0);
    vi.push_back(n0);
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> s >> t;
        if (!mp[s])
        {
            mp[s] = cnt;

            cnt++;
            vi.push_back(n0);
        }
//        cout << s << ' ' << mp[s] << '\n';
        vi[mp[s]].push_back(t);
//        cout << s << ' ' << vi[mp[s]].size() << '\n';
    }
//    return 0;
    while (q--)
    {
        cin >> s;
        if (mp[s])
        {
            for (int i = 0 ; i < vi[mp[s]].size() ; ++i)
            {
                cout << vi[mp[s]][i] << ' ';
            }
            cout << '\n';
        }
        else cout << "Chua Dang Ky!\n";
    }
    return 0;
}