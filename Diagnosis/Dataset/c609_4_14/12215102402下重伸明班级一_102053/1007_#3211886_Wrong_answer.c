#include<stdio.h>
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        int t,x;
        scanf("%d",&t);
        int a[t];
        for(int tt=0;tt<t;tt++)
        {
            scanf("%d",&a[tt]);
            printf("%d",a[tt]);
        }
    }
}