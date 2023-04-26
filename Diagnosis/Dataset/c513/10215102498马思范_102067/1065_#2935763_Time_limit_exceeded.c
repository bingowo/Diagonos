#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cha(int a,int n,int r2)
{
    if(n==1)
        return a;
    else if(n==2)
        return 0;
    else if(n==3)
        return a;
    else if(n==4)
        return r2;
    else if(n>=5)
        return cha(a,n-1,r2)+cha(a,n-2,r2);
}
int main()
{
    int a,n,m,x;
    scanf("%d%d%d%d",&a,&n,&m,&x);
    int s=1;
    int sum=0;
    int sum1=0;
    while(1)
    {
        for(int i=1;i<=n;i++)
        {
            sum = sum +cha(a,i,s);
        }
        if(sum!=m)
        {
            s++;
            sum=0;
        }
        else
            break;
    }
    for(int j=1;j<=x;j++)
        sum1=sum1+ cha(a,j,s);
    printf("%d",sum1);
    return 0;
}