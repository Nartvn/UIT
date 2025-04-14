#include <bits/stdc++.h>

using namespace std;

int n, m, q;
vector < vector < char > > vi;

const int NUMBEROFNODES = 2e6;

struct Node{
    int child[26];
    int exist, cnt;
} nodes[NUMBEROFNODES];

int cur = 0;

int new_node() {
    cur++;
    memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
    nodes[cur].exist = nodes[cur].cnt = 0;
    return cur;
}

 void add_string(int x, int y, int nx, int ny) {
    int pos = 0;
    for (int i = x ; i <= nx ; ++i) for (int j = y ; j <= ny ; ++j)
    {
        int c = vi[i][j] - 'a';
        if (nodes[pos].child[c] == -1) {

            nodes[pos].child[c] = new_node();
        }
        pos = nodes[pos].child[c];
        nodes[pos].cnt++;
        nodes[pos].exist = 1;
    }
}

bool find_string(string s) {
    int pos = 0;
    for (auto f : s) {
        int c = f - 'a';
        if (nodes[pos].child[c] == -1) return false;
        pos = nodes[pos].child[c];
    }
    return (nodes[pos].exist != 0);
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    char c;
    vector < char > emty;
    for (int i = 1 ; i <= n ; ++i)
    {
        vi.push_back(emty);
        for (int j = 1 ; j <= m ; ++j)
        {
            cin >> c;
            vi[i - 1].push_back(c);
        }
    }
    memset(nodes[0].child, -1, sizeof(nodes[cur].child));
    nodes[0].exist = nodes[0].cnt = 0;

    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
        {
            add_string(i, j, min(i + 9, n - 1), j);
            add_string(i, j, i, min(j + 9, m - 1));
        }
        string s;
    while (q--)
    {
        cin >> s;
        cout << find_string(s);
    }
    return 0;
}