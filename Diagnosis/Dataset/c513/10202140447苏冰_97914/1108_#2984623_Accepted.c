#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int a[100];
int b[100];
int x1,x2;
int cal(int n,int m)
{
    a[0]=n/m;
    b[0]=n%m;
    n=n-a[0]*m;
    int i=1,j=1;
    while(n<m)
    {
        n=n*10;
        a[i++]=n/m;
        b[j++]=n%m;
        n=n%m;
        if(n==0) return i;
        for(int k=0;k<j-1;k++)
        {
            if(b[k]==n)
            {
                x1=k+1;
                x2=j-1;
                return -1;
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int n,m;
    for(int cas=0;cas<T;cas++)
    {
        x1=0;x2=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d %d",&n,&m);
        printf("case #%d:\n",cas);
        if(cal(n,m)!=-1)
        {
             printf("%d.",a[0]);
            for(int i=1;i<cal(n,m);i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");
        }
        else
        {
             printf("%d.",a[0]);
            for(int i=1;i<=x2;i++)
            {
                printf("%d",a[i]);
            }
            printf("\n");
            printf("%d-%d\n",x1,x2);
        }
    }
    return 0;
}

