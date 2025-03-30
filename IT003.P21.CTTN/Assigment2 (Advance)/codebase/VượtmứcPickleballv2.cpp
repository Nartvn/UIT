#include <bits/stdc++.h>
#define pii pair < int , int >
#define fi first
#define se second
using namespace std;
const int maxn = 2e5 + 55;
int n, d;
int a[maxn];
int pre[205];
void solve()
{
    cin >> n >> d;
    int cnt = 0;

    for (int  i = 0 ; i <= 200 ; ++i) pre[i] = 0;

    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];

        if (i > d)
        {
            int val = 0;
            int co = 0;
            for  (int j = 0 ; j <= 200 ; ++j)
            {
                if (co + pre[j] >= (d + 1) / 2)
                {
                    val = j;
                    break;
                }
                co += pre[j];
            }
            co = 0;
            if (d % 2 == 0)
            for (int j = 0 ; j <= 200 ; ++j)
            {
                if (co + pre[j] >= (d + 1) / 2 + 1)
                {
                    val += j;
                    break;
                }
                co += pre[j];
            }

            else val *= 2;


            if (a[i] >= val) cnt++;

            pre[a[i - d]]--;
            pre[a[i]]++;
        }
        else pre[a[i]]++;

    }
    cout << cnt << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test = 1;
//    cin  >> test;
    while (test--) solve();
    return 0;
}