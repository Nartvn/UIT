#include <bits/stdc++.h>
#define pii pair < int , int >
#define fi first
#define se second
#define iii pair < int , pii >

using namespace std;

vector < iii > vi;
int n;

bool cmp(iii a, iii b)
{
    if (a.fi == b.fi)
    {
        if (a.se.fi == b.se.fi) return a.se.se < b.se.se;
        return a.se.fi > b.se.fi;
    }
    return a.fi < b.fi;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

int partition(int low, int high) {

    int rnd = rand(low, high);
    swap(vi[rnd], vi[high]);

    iii pivot = vi[high];
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
    cin.tie(0);
    cout.tie(0);
    srand(time(NULL));
    cin >> n;
    vi.push_back(iii(0, pii(0, 0)));
    for (int i = 1 ; i <= n ; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        vi.push_back(iii(x, pii(y, z)));
    }
    vi.push_back(iii(0, pii(0, 0)));
    kps(1, n);

    for (int i = 1 ; i <= n ; ++i) cout << vi[i].fi << ' ' << vi[i].se.fi << ' ' << vi[i].se.se << '\n';

    return 0;
}