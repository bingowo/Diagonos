#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printnumber(int n)
{
    if(n<10)
        printf("%d",n);
    else
        printf("%c",n+55);
}
void transnumber(int n,int r)
{
       if(n/r==0)
       {
           printnumber(n%r);
           return;
       }
       else
        {
            transnumber(n/r,r);
            printnumber(n%r);
       }
}

int main()
{
    int T,r,n;
    scanf("%d",&T);
    int a[T-1][1];
    for(int i=0;i<T;i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
   for(int i=0;i<T;i++)
    {
        n=a[i][0];r=a[i][1];
        transnumber(n,r);
    return 0;
}
}
