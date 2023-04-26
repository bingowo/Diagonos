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
    char m[100];
    scanf("%s",&m);
    int sign =0; //double
    if (strchr(m,'.')==0)
    {
        sign =1; //int
    }
    for(int i=0;i<100;i++)
    {
        if(m[i]==2)
        {
            m[i]=-1;
        }
    }
    
}