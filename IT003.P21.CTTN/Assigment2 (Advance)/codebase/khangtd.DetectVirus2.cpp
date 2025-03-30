#include <bits/stdc++.h>
#define N 2000005
using namespace std;

string a, b, s;
int z[N], zp[N];
int n, m;
vector <int> kq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> b >> a;
    n = a.size();
    s = " " + a + " " + b;

    z[1] = 0;

    int m = s.size();

    int l = 0, r = 0;

    for (int k = 2 ; k <= m ; ++k)
    {
        int x = 0;
        if (k <= r) x = min(z[k - l + 1], r - k + 1);
        while (k + x < m && s[x + 1] == s[k + x]) x++;
        z[k] = x;
        if (r < k + z[k] - 1)
        {
            l = k;
            r = k + z[k] - 1;
        }
    }

    for (int i = n + 2 ; i <= m ; ++i)
    {
        if (z[i] == n) kq.push_back(i - n - 1);
    }

    if (!kq.size())
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";

    for(int i = 0; i < kq.size(); i++)
        cout << kq[i] << " ";

    return 0;
}