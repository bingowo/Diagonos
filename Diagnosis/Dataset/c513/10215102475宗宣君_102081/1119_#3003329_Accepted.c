#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    if((*(double *)b)>(*(double *)a)) return 1;
    else return -1;
}
int main()
{
    int d;
    scanf("%d",&d);
    int n;
    scanf("%d",&n);
    int i,k[n],s[n];
    double t[n];
    for(i = 0;i<n;i++)
        {
            scanf("%d %d",&k[i],&s[i]);
            t[i] = (d-k[i])/(double)s[i];
        }
    qsort(t,n,sizeof(double),cmp);
    printf("%f",d/t[0]);
    return 0;

}
