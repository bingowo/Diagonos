#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int cmp(const void*e1,const void*e2)
{
    int*p1 = (int*)e1,*p2 = (int*)e2;
    while(*p1!=-1&&*p2!=-1&&*p1==*p2)p1++,p2++;
    return *p2-*p1;
}
int main()
{
    int I,T;
    for(scanf("%d",&T),I = 0;I<T;I++)
    {
        int a[1000][51],i,j = 0,n;
        scanf("%d",&n);
        for(i = 0;i<n;i++,j = 0)
            do scanf("%d",&a[i][j++]);while(a[i][j-1]!=-1);

        qsort(a,n,sizeof(a[0]),cmp);

        for(i = 0;i<n;i++)
        {
            for(j = 0;a[i][j]!=-1;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
return 0;
}
