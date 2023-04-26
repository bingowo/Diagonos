#include <stdio.h>
int main()
{
    int T,res;
    long long x,y,a,q;
    scanf ("%d",&T);
    for (int i=0;i<T;i++)
    {
        scanf("%d %d",&x,&y);
        a=x^y;res=0;
        for (int j=0;j<21;j++)
        {
            q=1LL<<j;
            if (a&q) res++;
        }
        printf("case #%d:\n%d\n",i,res);
    }
    return 0;
}
