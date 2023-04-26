#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//typedef struct SSS
//{
//    long long value;
//    int single;
//}sss;
int intcmp(int* p,int* q)
{
    while(*p!=-1 && *q!=-1)
    {
       if(*p < *q) return -1;
       else if(*p > *q) return 1;
       else
       {
           p++;
           q++;
       }
    }
    if(*p == -1 && *q == -1) return 0;
    else if(*p==-1) return -1;
    else return 1;
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
    for(int cas=0;cas<T;cas++)
    {
        int n;
        scanf("%d",&n);
        int a[1001][51];
        for(int i=0;i<n;i++)
        {
            for(int j=0;;j++)
            {
                int x;
                scanf("%d",&x);
                a[i][j]=x;
                if(x==-1) break;
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;;j++)
            {
                if(a[i][j]==-1) break;
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
