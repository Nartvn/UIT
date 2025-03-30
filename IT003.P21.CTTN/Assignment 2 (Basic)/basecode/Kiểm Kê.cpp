#include <bits/stdc++.h>
#define pii pair < int , int >
#define fi first
#define se second
using namespace std;

int n, k;
vector < string > vi;

bool cmp(string a, string b)
{
    return a < b;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

int partition(int low, int high) {

    int rnd = rand(low, high);
    swap(vi[rnd], vi[high]);

    string pivot = vi[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (cmp(vi[j], pivot)) {
            i++;
            swap(vi[i], vi[j]);
        }
    }
    swap(vi[i + 1], vi[high]);
    return i + 1;
}

void kps(int low, int high) {

    if (low < high) {
        int pi = partition(low, high);
        kps(low, pi - 1);
        kps(pi + 1, high);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand(time(NULL));
    cin >> n;
    string x;
    vi.push_back("0");
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> x;
        vi.push_back(x);
    }
    vi.push_back("0");
    kps(1, n);
    int cnt = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (vi[i] != vi[i + 1]) cnt++;
    }

    cout << cnt;

    return 0;
}