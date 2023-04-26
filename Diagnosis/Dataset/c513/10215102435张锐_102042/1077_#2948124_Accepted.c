#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int s1=*(int*)a,s2=*(int*)b;
    if(s1>s2) return 1;
    else return -1;
}
int main()
{
    int n1,n2;
    scanf("%d",&n1);
    int a[n1];
    for(int i=0;i<n1;i++) scanf("%d",&a[i]);
    scanf("%d",&n2);
    int b[n2];int ans[n2],ii=0,jj=0;
    for(int i=0;i<n2;i++) scanf("%d",&b[i]);
    qsort(b,n2,sizeof(int),cmp);
    int p=0;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(a[i]==b[j]) {printf("%d ",a[i]);b[j]=-1;}
        }
    }
    for(int i=n2-1;i>=0;i++)
    {
        if(b[i]!=-1) {p=i;break;}
    }
    for(int i=0;i<n2;i++)
    {
        if(b[i]!=-1&&i!=p) printf("%d ",b[i]);
        if(b[i]!=-1&&i==p) printf("%d\n",b[i]);
    }
    return 0;
}

