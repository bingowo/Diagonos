#include <iostream>
#include <climits>
#include <vector>
using namespace std;
const int M{102};
const int N{100};
int C(int L, int R, vector<vector<int>> a, int n)
{
    int r, i, j, min;
    for (r = j = 0; j < n; ++j)
    {
        for (min = INT_MAX, i = L; i <= R; ++i)
            if (a[i][j] < min)
                min = a[i][j];
        r += min;
    }
    return r;
}
int E(int L, int R, vector<vector<int>> c)
{
    int i, t;
    static vector<vector<int>> e(M, vector<int>(M, 0));
    if (L < R && !e[L][R])
        for (e[L][R] = INT_MAX, i = L; i < R; ++i)
            if ((t = E(L, i, c) + E(i + 1, R, c) + 2 * (c[L][i] + c[i + 1][R] - 2 * c[L][R])) < e[L][R])
                e[L][R] = t;
    return e[L][R];
}
int main()
{
    int i, j, m, n;
    vector<vector<int>> a(M, vector<int>(N, 0));
    vector<vector<int>> c(M, vector<int>(N, 0));
    cin >> m >> n;
    for (i = 1; i <= m; ++i)
        for (j = 0; j < n; ++j)
            cin >> a[i][j];
    for (i = 1; i <= m; ++i)
        for (j = i; j <= m; ++j)
            c[i][j] = C(i, j, a, n);
    cout << E(1, m + 1, c) << endl;
    return 0;
}