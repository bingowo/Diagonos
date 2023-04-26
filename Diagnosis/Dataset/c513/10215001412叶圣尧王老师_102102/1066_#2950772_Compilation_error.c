#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int f(int m)
{
    int sum=1;
    for（int i=2;i<=m;i++)sum*=i;
    return sum;
}

int main()
{
    int n,p,m,t,cas; scanf("%d",&cas);
    for(int i=0;i<cas;i++)
    {
        scanf("%d %d %d %d",&n,&p,&m,&t);
        int m1,m2,sum;
        m1=(m-t+p)/2;
        m2=(m+t-p)/2;
        if(m1+m2!=m)printf("0\n");
        else
        {
            sum=f(m);
            sum/=m1*m2;
            
        }
        printf("%d\n",sum);
    }
}