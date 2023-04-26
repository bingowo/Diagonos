#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
    int x = 0,y = 2,n = 0;
    int a[2];
    char s[121];
    scanf("%d%*c",&k);
    for(i = 0;i<k;i++)
    {
        gets(s);
        for(j = 0;j<strlen(s);j++)
        {
            x = s[j];
           while(x>0)
            {
                if(x%2==1)n++;
                x = x/y;
            }
        }
    Turn(n,strlen(s)*8);
    n = 0;
    }
    return 0;
}
