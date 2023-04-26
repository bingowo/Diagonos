#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point
{
   double x, y;
   double p, angle;
};

struct point s[1000];

int cmp (const void * a, const void *b)
{
    struct point p1, p2;
    p1 = *(struct point *)a;
    p2 = *(struct point *)b;
    
    if (p1.angle > p2.angle) return 1;				//极角大的排在后
    else if (fabs( p1.angle - p2.angle ) < 1e-10)   //极角相同
        if (p2.p > p1.p )return 1;                  //按极径大的放在前
    return -1;
}
int main (void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
    scanf( "%lf%lf", &s[i].x, &s[i].y);
    s[i].p  = sqrt ( s[i].x * s[i].x + s[i].y * s[i].y ); //计算极径
    int t;
    t = atan2( s[i].y, s[i].x );                          //计算极径的反正切
    if (t < 0 ) s[i].angle = 2 * M_PI + t;				  //由于atan2()返回值为(-π,π]，所以要把负值加2π
    else s[i].angle = t;								  //正值不变
    qsort ( s, n ,sizeof(s[0]), cmp );
    for (int i=0; i<n; i++)
        printf("(%.4f,%.4f)\n", s[i].p, s[i].angle);
}
}