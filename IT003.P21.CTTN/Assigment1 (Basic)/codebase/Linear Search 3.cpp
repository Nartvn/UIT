#include <bits/stdc++.h>
using namespace std;

int n; 
int a[200005];
bool mp[200005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int mex = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
        mp[a[i]] = 1;
        while (mp[mex] == 1) mex++;
        cout << mex << ' ';
    }
        
    return 0;
}