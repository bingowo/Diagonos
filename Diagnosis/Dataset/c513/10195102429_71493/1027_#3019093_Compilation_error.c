#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
struct point
{
    double x;
    double y;
    double p;
    double angle;
    point()
    {
        x = y = p = angle = 0.0;
    }
};

bool cmp(point a, point b)
{
    if (abs(a.angle - b.angle) <= 10e-8) return a.p > b.p;
    else return a.angle < b.angle;
}


int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n; cin >> n;
        point a[1000];
        for (int j = 0; j < n; j++)
        {
            cin >> a[j].x >> a[j].y;
            a[j].p = sqrt(a[j].x*a[j].x + a[j].y*a[j].y);
            if (a[j].y >= 0) a[j].angle = acos(a[j].x / a[j].p);
            else a[j].angle = 2 * acos(-1) - acos(a[j].x / a[j].p);
        }
        sort(a, a + n, cmp);
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < n; j++)
            printf("(%.4lf,%.4lf)\n", a[j].p, a[j].angle);
    }
}
