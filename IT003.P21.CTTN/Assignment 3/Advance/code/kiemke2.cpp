#include <bits/stdc++.h>
#define pii pair < string , int >
#define fi first
#define se second
using namespace std;

int n;
vector < pii > vi;

bool tangdan(string & a, string & b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

bool cmp(pii a, pii b)
{
    if (a.se == b.se)
    {
        return tangdan(a.fi, b.fi);
    }
    return a.se > b.se;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

int partition(int low, int high) {

    int rnd = rand(low, high);
    swap(vi[rnd], vi[high]);

    pii pivot = vi[high];
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


//---------------
const int maxn = 5e4 + 55;
string a[maxn];
int partition2(int low, int high) {

    int rnd = rand(low, high);
    swap(a[rnd], a[high]);

    string pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (a[j]< pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void kps2(int low, int high) {

    if (low < high) {
        int pi = partition2(low, high);
        kps2(low, pi - 1);
        kps2(pi + 1, high);
    }
}

//-------------

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand(time(NULL));
    cin >> n;
    string x;
    for (int i = 1 ; i <= n ; ++i) cin >> a[i];
    kps2(1, n);
//    for (int i = 1 ; i <= n ; ++i) cout << a[i] << ' ';

    int l = 1;
    vi.push_back(pii("0", 0));
    for (int i = 1 ; i <= n ; ++i)
    {
        if (a[i] != a[i + 1])
        {
            vi.push_back(pii(a[i], i - l + 1));
            l = i + 1;
        }
    }
    vi.push_back(pii("0", 0));
    n = vi.size() - 2;
    kps(1, n);
    for (int i = 1 ; i <= n ; ++i) cout << vi[i].fi << ' ' << vi[i].se << '\n';
    return 0;
}