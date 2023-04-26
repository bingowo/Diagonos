#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,m,cnt,i,num,a,rest;
    char ans[1007];
    scanf("%d%d",&n,&m);
    cnt = 0;rest = 0;
    if(n == 0)printf("0");
    else
    {
      while(n)
      {
            if(n%m == 0)
            {
                ans[cnt++] = '0';
                n /= m;
            }
            else if(n > 0)
            {
                a = n;
                n /= m;
                num = a - n*m + rest;
               if(num >= abs(m))
               {
                 rest = num/abs(m);
                 num %= abs(m);
               }
               if(num >= 10)ans[cnt++] = num+'A'-10;
               else ans[cnt++] = num+'0';
            }
            else if(n < 0)
            {
                a = n;
                n = n/m+1;
                num = a - n*m + rest;
               if(num >= abs(m))
               {
                 rest = num/abs(m);
                 num %= abs(m);
               }
               if(num >= 10)ans[cnt++] = num+'A'-10;
               else ans[cnt++] = num+'0';
            }
    }
    for(i = cnt-1; i >= 0; i--)printf("%c"#include<stdio.h>
#include<math.h>

int main()
{
    int n,m,i=0,j=0,a=0,b=0,rest=0;
    char ans[10000];
    scanf("%d%d",&n,&m);
    if(n==0) printf("0");
    else if(n>0)
    {
        while(n)
        {
            if(n%m==0)
            {
                ans[i++]='0';
                n/=m;
            }
            else if(n>0)
            {
                a=n;
                n/=m;
                b=a-n*m+rest;
                if(b>abs(m))
                {
                    b%=abs(m);
                    rest/=b;
                }
                if(b>=10) ans[i++]=b+'A'-10;
                else ans[i]=b+'0';
            }
            else if(n<0)
            {
                a=n;
                n/=m+1;
                b=a-m*n+rest;
                if(b>abs(m))
                {
                    b%=abs(m);
                    rest/=abs(m);
                }
                if(b>=10) ans[i++]=b+'A'-10;
                else ans[i++]=b+'10';
            }
        }
        for(j=i-1;j>=0;j--) printf("%c",ans[j]);
    }
    return 0;
}
,ans[i]);
}
    return 0;
}
