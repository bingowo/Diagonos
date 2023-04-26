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
    
    for(i = cnt-1; i >= 0; i--)printf("%c",ans[i]);
}
    return 0;
}
