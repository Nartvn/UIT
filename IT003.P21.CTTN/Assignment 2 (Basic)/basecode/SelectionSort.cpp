#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 55;

int mod;
int n, arr[MAXN];

void selectionSort(int l, int r)
{
//    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
        if (i != min_idx) {for (int key = 0 ; key < n ; ++key) cout << arr[key] << ' ';
        cout << '\n';}
    }
}

void solve()
{
    cin >> n;
    for (int i = 0 ; i < n ; ++i) cin >> arr[i];
    selectionSort(1, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test = 1;
    while (test--) solve();
    return 0;
}