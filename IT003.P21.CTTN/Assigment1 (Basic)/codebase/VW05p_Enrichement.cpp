// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector < vector < int > > val;
int main() {
    vector < int > err;
    cin >> n >> m;
    int ans = 1e9;
    for (int i = 0 ; i < n ; ++i)
    {
        val.push_back(err);
        for (int j = 0 ; j < m ; ++j)
        {
            int x;
            cin >> x;
            val[i].push_back(x);
        }
    }
    for (int i = 0 ; i < n - 2 ; ++i)
    for (int j = 0 ; j < m - 2 ; ++j)
    {
        int res = 0;
        for (int x = i ; x <= i + 2 ; ++x)
        for (int y = j ; y <= j + 2 ; ++y)
            res += val[x][y];
        ans = min(ans, res);
    }
    cout << ans << '\n';
	return 0;
}