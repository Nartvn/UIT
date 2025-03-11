#include <bits/stdc++.h>

using namespace std;

string s;
char decode(char c, int k)
{
    ///if (c < 'A' || c > 'Z') return c;
    int a = c - 'A';
    a += k;
    a = a % 26;
    a += 26;
    a = a % 26;
    return char(a + 'A');
}
int32_t main()
{
    int k;
    cin >> k;
    while(cin >> s){
    for (int i = 0 ; i < s.size() ; ++i)
    {
        s[i] = decode(s[i], k);
    }
    cout << s << ' ';}
    return 0;
}