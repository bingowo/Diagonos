#include <stdio.h>
#include <math.h>
#include <string.h>
int mod(int a,int b)
{
     if(abs(a)%abs(b)!=0)
     {
         if(a<0) return (a-(abs(a)/abs(b)+1)*b);
         else return (a-(abs(a)/abs(b)*b*(-1)));
     }
     return 0;
}
int main()
{
    char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n,r;
    char s[40];
    scanf("%d %d",&n,&r);
    int i=0;
    while(n!=0)
    {
        int x=mod(n,r);
        if(n<0) n=abs(n-x)/abs(r);
        else n=abs(n-x)/abs(r)*(-1);
        s[i]=table[x];
        i++;
    }
    for(int j=i-1;j>=0;j--)
    {
        printf("%c",s[j]);
    }
    return 0;
}

