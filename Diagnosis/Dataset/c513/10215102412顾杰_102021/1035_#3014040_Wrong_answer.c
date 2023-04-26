#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"
int cmp(const void*a,const void*b)
{
    return ((long long*)a)[2]>((long long*)b)[2]?-1:1;
}
int main()
{
    long long a[2000][3],ans=0,max=0;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
        a[i][2]=a[i][0]*a[i][0]+2*a[i][0]*a[i][1];
    }

    qsort(a,n,sizeof(a[0]),cmp);//printf("!!");
    for(int i=0;i<m;i++)
    {ans+=2*a[i][0]*a[i][1];if(a[i][0]>max)max=a[i][0];}
    printf("%lld",ans+max*max);
}
