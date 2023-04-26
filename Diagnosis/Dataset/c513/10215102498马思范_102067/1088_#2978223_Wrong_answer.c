#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double result(double m,double n)
{
    double sum1=1,sum2=1;
    double k=m-n;
    while (m>k)
    {
        sum1=sum1*m;
        m--;
    }
    while(n>0)
    {
        sum2=sum2*n;
        n--;
    }
    return sum1/sum2;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        double m,n;
        double r;
        scanf("%lf%lf",&m,&n);
        printf("case #%d:\n",i);
        if(n==0)
            printf("%d\n",1);
        else if(n==1)
            printf("%d\n",(int)m);
        else
        {
            r= result(m,n);
            printf("%lld\n",(long long int)r);
        }
    }
    return 0;
}