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
       int R=strlen(b);
       int sum=0;
       for (int j=0;j<strlen(c);j++)
       {
           for(int k=0;k<strlen(b);k++)
           {
               if(c[j]==b[k])
               {
                   if(k==0)
                    sum=sum+pow(R,strlen(c)-j-1);
                   else if(k==1)
                    sum=sum+0;
                   else
                    sum=sum+k*pow(R,strlen(c)-j-1);
               }
           }
       }
       printf("case #%d:\n",i);
       printf("%d\n",sum);
    }
    return 0;
}
