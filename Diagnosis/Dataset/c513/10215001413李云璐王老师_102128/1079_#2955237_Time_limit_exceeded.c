#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int cmp(const void*a1,const void*a2)
{
    int a=*(int*)a1;
    int b=*(int*)a2;
    return a-b;
}

int chuli(int*a,int n,int l,int u)
{
    int b[n*(n+1)/2+1],c[n*(n+1)/2+1];
    for(int o=0;o<=n*(n+1)/2;o++)
        c[o]=b[o]=0;
    int p=1;
    for(int f=0;f<n;f++)
    {
        c[p-1]=0;
        for(int i=f;i<n;i++)
    {
    c[p]=b[p]=c[p-1]+a[i];
    p++;}}
    qsort(b+1,n*(n+1)/2,sizeof(int),cmp);
    for(int k=1;k<=n*(n+1)/2;k++)
        printf("%d ",b[k]);
    printf("\n");
    int data=0;
    for(int k=l;k<=u;k++)
        data+=b[k];
    return data;



}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int a[n+1];
        for(int k=0;k<n;k++)
            scanf("%d",&a[k]);
        printf("case #%d:\n",i);
        for(int k=0;k<m;k++)
        {
            int l,u;
            scanf("%d%d",&l,&u);
            int data=chuli(a,n,l,u);
            printf("%d\n",data);
        }

    }
    return 0;
}
