#include <bits/stdc++.h>

using namespace std;

stack < char > q;
bool ans = 1;

void wrong()
{
    cout << 0;
    exit(0);
    return;
}

void xuly(char c)
{
    if (c != '{' && c != '}' && c != '(' && c != ')' && c != '[' && c != ']') return;
    if (c == '{' || c == '(' || c == '[') q.push(c);
    else
    {
        if (q.empty()) wrong();
        ///cout << c << ' ' << q.top() << '\n';
        if (c == '}') if (q.top() == '{') q.pop(); else wrong();
        if (c == ')') if (q.top() == '(') q.pop(); else wrong();
        if (c == ']') if (q.top() == '[') q.pop(); else wrong();
    }
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    char c;
    while (cin >> c)
    {
        xuly(c);
    }
    cout << (q.size() == 0) << '\n';
    return 0;
}