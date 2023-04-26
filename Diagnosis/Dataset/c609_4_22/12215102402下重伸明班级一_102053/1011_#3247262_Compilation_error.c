#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long GCD(long long  m,long long  n)
{
    
    long long int x,y;
    long long int z=n;
    if(m<n)
    {
        long long int t;
        t=m,m=n,n=t;
    }
    while(z>0)
    {
        x=m%z;
        y=n%z;
        if((x==0)&&(y==0))
            return z;
        else
            z=z-1;
    }
int main()
{
    int y=0;
    char m[100];
    scanf("%s",&m);
    int sign =0; //double
    if (strchr(m,'.')==0)
    {
        sign =1; //int
    }
    int x=strlen(m);
    if(sign==1)
    {
        
        for(int i=0;i<x;i++)
        {
            if(m[i]=='1')
                y=y+(1*3);
            if(m[i]=='0')
                y=y+(*3);
            if(m[i]=='2')
                y=y-(1*3);
        }
    }
    printf("%d",y);
    
}