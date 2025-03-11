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
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> a[i];
    }
    cin >> x;
    vector < int > vi;
    for (int i = 0 ; i < n ; ++i)
    {
        if (a[i] == x)
            vi.push_back(i);
    }
    if (!vi.size()) cout << 0;
    else
    {
        cout << vi.size() << '\n';
        for (int i = 0 ; i < vi.size() ; ++i) cout << vi[i] << ' ' << vi[i] + 1 << '\n';
    }
        
    return 0;
}