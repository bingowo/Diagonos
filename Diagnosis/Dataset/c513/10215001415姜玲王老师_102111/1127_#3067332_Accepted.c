#include <stdio.h>
#include <stdlib.h>
typedef struct{int a;int b;}num;
int gcd(int x,int y)
{
    if(x%y)  return gcd(y,x%y);
    else return y;
}
int lcm (int x,int y)
{
    int k;
    k=gcd(x,y);
    return x*y/k;
}
int main()
{
    int n,i,c=1,sum=0,k;
    scanf("%d",&n);
    num p[100];
    for(i=0;i<n;i++)
    {
        scanf("%d/%d\n",&p[i].a,&p[i].b);
    }
    for(i=0;i<n;i++)
    {
      c=lcm(p[i].b,c);
    }
    for(i=0;i<n;i++)
    {
        sum+=p[i].a*c/p[i].b;
    }
    k=gcd(sum,c);
    sum/=k;
    c/=k;
    printf("%d/%d",sum,c);
}
