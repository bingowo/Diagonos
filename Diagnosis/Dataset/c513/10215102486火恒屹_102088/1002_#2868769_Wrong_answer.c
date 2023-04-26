#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int a;
    scanf("%d",&a);
    for (int i=0;i<a;i++)
    {
       char c[61]={'\0'};
       char b[61]={'\0'};
       scanf("%s",&c);
       b[0]=c[0];
       int d=1;
       for (int j=1;j<strlen(c);j++)
       {
           int flag=1;
           for(int k=0;k<strlen(b);k++)
           {
               if (c[j]==b[k])
               {flag=0;
               break;}
            }
            if(flag==1)
            {
                b[d]=c[j];
                d++;
            }
       }
       long long R=strlen(b);
       if(R==1)
        R=2;
       long long sum=0;
       for (int j=0;j<strlen(c);j++)
       {
           for(int k=0;k<strlen(b);k++)
           {
               if(c[j]==b[k])
               {
                   if(k==0)
                    {sum=sum+pow(R,strlen(c)-j-1);
                    //printf("%d %d \n",R,strlen(c)-j-1);
                    //printf("%lld\n",sum);
                    break;}
                   else if(k==1)
                    {sum=sum+0;
                    break;}
                   else
                    {sum=sum+k*pow(R,strlen(c)-j-1);
                    break;}
               }
           }
           //printf("%lld\n",sum);
           //不知道为什么数字太大时会出现计算错误，比如15的14次方在这段代码里算出来的数字比我自己计算器上算的结果小1
       }
       printf("case #%d:\n",i);
       printf("%lld\n",sum);
    }
    return 0;
}
