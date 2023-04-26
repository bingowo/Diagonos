#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cmp(const void* a1,const void *b1);
    int m,n;
    int a[520];
    int b[520];
    int b0[520];
    int c[520];

    scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);

    int cnt=0;


    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(b[i]==a[j])
            {
                c[j]=1;
                b[i]=-1;
                cnt++;
            }
        }


    for(int i=0;i<m;i++)
    {
        if(c[i]==1) printf("%d ",a[i]);
    }


    qsort(b,n,sizeof(int),cmp);


    for(int i=0;i<n;i++)
    {
        if(b[i]!=-1)
        {
            printf("%d ",b[i]);
        }

    }
    return 0;
}


int cmp(const void* a1,const void *b1)
{
    int a=*(int *)a1;
    int b=*(int *)b1;
    if(a>=b) return 1;
    if(a<b) return -1;
}
