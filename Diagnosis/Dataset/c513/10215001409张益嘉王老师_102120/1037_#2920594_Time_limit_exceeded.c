#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
   long long *aa=(long long*)a;
   long long *bb=(long long*)b;
    if(*aa>*bb) return -1;
    else if(*aa<=*bb) return 1;

}

int main()
{
    int n,m,i,j;


    scanf("%d%d",&n,&m);
    long long *x=(long long*)malloc(n*sizeof(long long));
    for(i=0;i<n;i++)
    {
        scanf("%lld",&x[i]);
    }
    qsort(x,n,sizeof(long long),cmp);

    long long re,ans=999999999999999999;

    for(i=0;i<n-m+1;i++)
    {
        re=0;
        for(j=i+1;j<i+m;j++)
        {
            re+=(x[i]-x[j]);
        }
        
        if(re<=ans) ans=re;
    }

    printf("%lld",ans);
    return 0;

}
