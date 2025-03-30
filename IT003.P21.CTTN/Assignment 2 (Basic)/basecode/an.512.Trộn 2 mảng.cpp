void merge(int * a, int n, int * b, int m, int * c)
{
//    for (int i = 0 ; i < n ; ++i) cout << a[i] << ' ';
//    cout << '\n';
//    for (int i = 0 ; i < m ; ++i) cout << b[i] << ' ';
//    cout << '\n';

    int ia = 0, ib = 0, ic = 0;
    while (1)
    {
        if (ia == n && ib == m) break;
        if (ia == n)
        {
            c[ic] = b[ib];
            ic++;
            ib++;
            continue;
        }
        if (ib == m)
        {
            c[ic] = a[ia];
            ia++;
            ic++;
            continue;
        }
        if (a[ia] < b[ib])
        {
            c[ic] = a[ia];
            ia++;
            ic++;
        }
        else
        {
            c[ic] = b[ib];
            ib++;
            ic++;
        }
    }
}