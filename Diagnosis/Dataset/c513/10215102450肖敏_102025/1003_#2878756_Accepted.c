#include<stdio.h>
#include<stdlib.h>
int num(long long int a[10000],int b[10000],int N)
{
    int n=0,i=64,x;
    long long int m=1;
    for(x=0;x<N;x++)
    {
        while(i>0)
            {
            if(a[x]&m)n++;
            m=m<<1;
            i--;
            }
    i=64;
    b[x]=n;
    n=0;
    m=1;
    }
    return 0;
}
int sort(int N,long long int a[10000],int b[10000])
{
    int y;
    long long int z;
    for(int i=0;i<N-1;i++)
        for(int m=0;m<N-1-i;m++)
        {
            if(b[m]<b[m+1]){y=b[m],b[m]=b[m+1],b[m+1]=y;
                            z=a[m],a[m]=a[m+1],a[m+1]=z;}
            if(b[m]==b[m+1]&&a[m]>a[m+1])z=a[m],a[m]=a[m+1],a[m+1]=z;
        }

        return 0;
}
int main()
{
    int t,n,i,s=0;
    long long int a[10000];
    int b[10000];
    scanf("%d",&t);
    while(t>0){
        scanf("%d",&n);
        for (i=0;i<n;i++) scanf("%lld",&a[i]);
        num(a,b,n);
        sort(n,a,b);
        printf("case #%d:\n",s);
        for (i=0;i<n;i++) printf("%lld ",a[i]);
        printf("\n");
        t--;
        s++;
    }
    return 0;
}
