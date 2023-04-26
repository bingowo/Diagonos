#include <stdio.h>
#include <stdlib.h>

int cmp(const void*a,const void*b)
{
    return(*(int*)a-*(int*)b);
}

int GCD(int a,int b)
{
    if(b) return GCD(b,a%b);
    else return a;
}

int main()
{
    int n,s,a[1000],p1=1,p2,sum1=0,sum2,i;
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++)
    while(scanf("%d ",&a[i])!=EOF);
    qsort(a,n,sizeof(int),cmp);
    for(i=1;s>sum1;i++)
    {
        if(a[i]==a[i-1])p1++;
        else
        {
            sum2=sum1;
            sum1=sum1+p1*(a[i]-a[i-1]);
            p2=p1;
            p1=0;
        }
    }
    if(s==sum1)printf("%d",a[i]);
    else printf("%d+%d/%d",a[i-1],(s-sum2)/GCD((s-sum2),p2),p2/GCD((s-sum2),p2));
    return 0;
}