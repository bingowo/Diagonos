#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int intcmp(int* p1,int*p2)
{
    while(*p1 == *p2)
    {
        p1++;p2++;
    }
    if(*p1==-1 && *p2!=-1) return -1;
    else if(*p2==-1 && *p1!=-1) return 1;
    else if(*p1==-1 && *p2==-1) return 0;
    return (*p1 - *p2);
}
int cmp(const void*_a,const void*_b)
{
    int* a=(int*)_a;
    int* b=(int*)_b;
    return intcmp(b,a);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int a[1100][60];
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<60;k++)
            {
                scanf("%d",&a[j][k]);
                if(a[j][k]==-1) break;
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<60;k++)
            {
                if(a[j][k]==-1) break;
                printf("%d ",a[j][k]);
            }
            printf("\n");
        }
    }

    return 0;
}
