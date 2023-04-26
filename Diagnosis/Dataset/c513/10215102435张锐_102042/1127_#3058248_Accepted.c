#include <stdio.h>
#include <stdlib.h>

int gcd(int x,int y)
{
    while(1)
    {
        if(x>y) x-=y;
        else if(x<y) y-=x;
        else return x;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a,b;char f;
    scanf("%d%c%d",&a,&f,&b);
    for(int i=1;i<n;i++)
    {
        int c,d;
        scanf("%d%c%d",&c,&f,&d);
        int x,y;
        x=a*d+b*c,y=b*d;
        int temp=gcd(x,y);
        a=x/temp,b=y/temp;
    }
    printf("%d/%d",a,b);
    return 0;
}
