#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int Num(int x)
{
    int n = 0,w;
    w = x;
    if(x<0)x = -x;
    while(x>0)
            {
                if(x%2==1)n++;
                x = x/2;
            }
    if(w<0)n = 8-n+1;
    return n;
}
void Turn(int n,int m)
  {
        for(int i = 2;i<=n;i++)
   {
       while(n%i==0&&m%i==0)
       {
           n = n/i;
           m = m/i;
        }
   }
   printf("%d/%d\n",n,m);
  }
int main()
{
    int k,i,j = 0;
    int x = 0,n = 0;
    char s[121];
    scanf("%d%*c",&k);
    for(i = 0;i<k;i++)
    {
        gets(s);
        for(j = 0;j<strlen(s);j++)
        {
            x = s[j];
            n += Num(x);
        }
    Turn(n,strlen(s)*8);
    n = 0;
    }
    return 0;
}
