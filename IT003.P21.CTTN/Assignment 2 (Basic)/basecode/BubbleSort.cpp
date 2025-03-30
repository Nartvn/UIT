#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 55;

int mod;
int n, arr[MAXN];

void bubbleSort(int l, int r)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);

                for (int key = 0 ; key < n  ; ++key) cout << arr[key] << ' ';cout << '\n';
                swapped = true;

            }
        }
        if (!swapped)
            break;
    }
}

void solve()
{
    cin >> n;
    for (int i = 0 ; i < n ; ++i) cin >> arr[i];
    bubbleSort(1, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test = 1;
    while (test--) solve();
    return 0;
}