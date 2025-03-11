#include <bits/stdc++.h>

using namespace std;

int n, k, x;

int main()
{
    cin >> n >> k;
    vector < int > now, nope;
    map < int , int > mp;
    for (int i = 1 ; i <= n ; ++i)
    {
        int x;
        cin >> x;
        if (mp[x] != 1)
            now.push_back(x);
        else
            nope.push_back(x);
        mp[x] = 1;
    }
    for (int i = 0 ; i < min(k, (int)now.size()) ; ++i) cout << now[i] << ' ';
    for (int i = 0 ; i < k - ((int)now.size()) ; ++i) cout << nope[i] << ' ';

    return 0;
}
/*
10 4
8 8 8 8 8 8 8 8 2 1
*/