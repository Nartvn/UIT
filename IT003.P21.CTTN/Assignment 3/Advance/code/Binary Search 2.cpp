#include <bits/stdc++.h>
#define pii pair < int , int >
#define fi first
#define se second

using namespace std;

int n, test = 1;
vector < pii > vi;

bool cmp(pii a, pii b)
{
    if (a.fi == b.fi) return a.se < b.se;
    return a.fi < b.fi;
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

int CutDown(int x)
{
    int l = 1, r = n;
    int res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (vi[mid].fi >= x)
        {
            r = mid - 1;
            if (vi[mid].fi == x) res = mid;
        }
        else l = mid + 1;
    }
    return res;
}

int CutUp(int x)
{
    int l = 1, r = n;
    int res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (vi[mid].fi <= x)
        {
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> test;
    srand(time(NULL));

    int x;

    vi.push_back(pii(0, 0));
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> x;
        vi.push_back(pii(x, i));
    }
    vi.push_back(pii(0, 0));

    kps(1, n);

    string s;

    while (test--)
    {
        cin >> s >> x;
        if (x == 1)
        {
            cin >> x;
            int pos = CutDown(x);
//            cout << pos << '\n';
            cout << ((vi[pos].fi != x) ? -1 : vi[pos].se) << '\n';
        }
        else
        {
            cin >> x;
            int pos = CutUp(x);
            cout << ((vi[pos].fi != x) ? -1 : vi[pos].se) << '\n';
        }
    }
    return 0;
}