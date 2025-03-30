#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 55;

int mod;
int n, arr[MAXN];

void insertionSort(int l, int r)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            for (int i = 0 ; i < n ; ++i) cout << arr[i] << ' ';
            cout << '\n';
        }
        arr[j + 1] = key;
        for (int i = 0 ; i < n ; ++i) cout << arr[i] << ' ';
            cout << '\n';
    }
}

void solve()
{
    cin >> n;
    for (int i = 0 ; i < n ; ++i) cin >> arr[i];
    insertionSort(1, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test = 1;
    while (test--) solve();
    return 0;
}