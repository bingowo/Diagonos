#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hui(int x,int n)
{
    char a[11],b[11],c[11];
    int i=0,w=0;
    while(x>0)
    {
        a[i]=x%10+'0';
        x/=10;
        i++;
    }
    w=i;
    a[w]='\0';
    for(i=0;i<w;i++)
    {
        b[i]=a[w-i-1];
    }
    b[w]='\0';
    if(strcmp(a,b)==0)
        printf("%d %d",n,atoi(a));
    else
        hui(atoi(a)+atoi(b),n+1);
}
int main()
{
    int x,n=0;
    scanf("%d",&x);
    hui(x,n);
    return 0;
}
