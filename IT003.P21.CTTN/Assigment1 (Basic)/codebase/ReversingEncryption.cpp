#include <bits/stdc++.h>

using namespace std;

string s;
char c[100055];
int32_t main()
{
    cin >> s;
    int n = s.size();

    for (int i = 1 ; i <= n ; ++i) 
    {
        c[i] = s[i - 1];
        if (n % i == 0)
            reverse(c + 1, c + i + 1);
    }
    for (int i = 1 ; i <= n ; ++i) cout << c[i];
    return 0;
}