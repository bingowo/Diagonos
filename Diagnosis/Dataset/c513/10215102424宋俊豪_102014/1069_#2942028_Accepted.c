#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int res(int n)
{
    int max=0,i;
    do
    {
        i=n%10;
        max=max*10+i;
        n=n/10;
    }while(n>0);
    return max;
}
void rev(int n,int dep)
{   int m=res(n);
    if(n+m==res(n+m))
    {
        printf("%d %d",dep,n+m);
        return;
    }
    else
        rev(n+m,dep+1);
}
int main()
{
    int n;
    scanf("%d",&n);
    rev(n,1);
    return 0;
}
