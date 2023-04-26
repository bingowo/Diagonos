#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    int *p1,*p2;
    p1=(int *)a;
    p2=(int *)b;
    int i=0;
    while(1)
    {
        if(p1[i]!=p2[i])
            return p2[i]-p1[i];
        else
            i++;
    }
}
int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        int n,i,j;
        scanf("%d",&n);
        int a[n][51];
        for(i=0;i<n;i++)
        {
            j=0;
            while(scanf("%d",&a[i][j])&&a[i][j]!=-1)
                j++;
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(i=0;i<n;i++)
        {
            j=0;
            while(a[i][j]!=-1)
            {
                printf("%d",a[i][j]);
                if(a[i][j+1]!=-1)
                    printf(" ");
                j++;
            }
            printf("\n");
        }
    }
    return 0;
}
