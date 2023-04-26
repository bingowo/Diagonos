#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
   unsigned long long *aa=(unsigned long long*)a;
   unsigned long long *bb=(unsigned long long*)b;
    if(*aa>*bb) return -1;
    else if(*aa<=*bb) return 1;

}

int main()
{
    int n,m,i,j;


    scanf("%d%d",&n,&m);
    unsigned long long *x=(unsigned long long*)malloc(n*sizeof(unsigned long long));
    for(i=0;i<n;i++)
    {
        scanf("%llu",&x[i]);
    }
    qsort(x,n,sizeof(unsigned long long),cmp);

    unsigned long long re,ans=999999999999999999;

    for(i=0;i<n-m+1;i++)
    {
        re=0;
        for(j=i+1;j<i+m;j++)
        {
            re+=(x[i]-x[j]);
        }
        
        if(re<=ans) ans=re;
    }

    printf("%llu",ans);
    return 0;

}
