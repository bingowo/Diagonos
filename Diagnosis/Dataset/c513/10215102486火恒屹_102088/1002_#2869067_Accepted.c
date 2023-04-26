#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
long long mypow(int R,int a)
{
    long long sum=1;
    for(int i=0;i<a;i++)
    {
        sum=sum*R;
    }
    return sum;
}
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
                    {sum=sum+mypow(R,strlen(c)-j-1);//数字太大时pow会出问题
                    break;}
                   else if(k==1)
                    {sum=sum+0;
                    break;}
                   else
                    {sum=sum+k*mypow(R,strlen(c)-j-1);
                    break;}
               }
           }}
       printf("case #%d:\n",i);
       printf("%lld\n",sum);
    }
    return 0;
}
