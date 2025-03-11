#include <bits/stdc++.h>

using namespace std;

string s1, s2;
char c[100055];
int32_t main()
{
    cin >> s1 >> s2;
    int key1 = (int)s1.size() - 1;
    int key2 = 0;
    int mx2 = (int)s2.size() - 1;
    int ans = 0;
    string nw1 = "", nw2 = "";
    int cnt = 0;
    while (key1 >= 0 && key2 <= mx2)
    {
        cnt++;
        nw1 = s1[key1] + nw1;
        nw2 = nw2 + s2[key2];
        key1--;
        key2++;
        
        if (nw1 == nw2)
        {
            ans = cnt;
        }
        ///cout << ans << " " << nw1 << ' ' << nw2 << '\n';   
    }
    string end = "";
    for (int i = 0 ; i < (int)s1.size() ; ++i) end = end + s1[i];
    for (int i = ans ; i <= mx2 ; ++i) end = end + s2[i];
    cout << end.size() << '\n' << end;
    return 0;
}