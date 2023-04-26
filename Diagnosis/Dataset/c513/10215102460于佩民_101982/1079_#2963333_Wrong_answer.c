#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
    return (int*)a-(int*)b;
}
void solve(int a[],int s[],int n)
{
    int i,j=0,k;
    for(i=0;i<n;i++)
    {
        s[j]=a[i],j++;
        for(k=i+1;k<n;k++)
        {
            s[j]=s[j-1]+a[k];
            j++;
        }
    }
    qsort(s,j,sizeof(s[0]),cmp);
}

int main()
{
    int t,cas;
    int m,n,i,j,a[1001],l[32],u[32],s[500501];
    long long int sum;
    scanf("%d",&cas);
    for(t=0;t<cas;t++)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&l[i],&u[i]);
        }
        printf("case #%d:\n",t);
        solve(a,s,n);
        for(i=0;i<m;i++)
        {   sum=0;
            for(j=l[i]-1;j<u[i];j++) {sum+=s[j];}
            printf("%lld\n",sum);
        }
    }
    return 0;
}