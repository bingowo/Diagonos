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
    long long num[10001]={0};
    char s[10001][16]={'\0'};
    for (int i=0;i<a;i++)
    {
       char b[16]={'\0'};
       scanf("%s",&s[i]);
       b[0]=s[i][0];
       int d=1;
       for (int j=1;j<strlen(s[i]);j++)
       {
           int flag=1;
           for(int k=0;k<strlen(b);k++)
           {
               if (s[i][j]==b[k])
               {flag=0;
               break;}
            }
            if(flag==1)
            {
                b[d]=s[i][j];
                d++;
            }
       }
       int R=strlen(b);
       if(R==1)
        R=2;
       long long sum=0;
       for (int j=0;j<strlen(s[i]);j++)
       {
           for(int k=0;k<strlen(b);k++)
           {
               if(s[i][j]==b[k])
               {
                   if(k==0)
                    {sum=sum+mypow(R,strlen(s[i])-j-1);//数字太大时pow会出问题
                    break;}
                   else if(k==1)
                    {sum=sum+0;
                    break;}
                   else
                    {sum=sum+k*mypow(R,strlen(s[i])-j-1);
                    break;}
               }
           }
        }
       num[i]=sum;
       //printf("%s %lld\n",s[i],num[i]);
    }
    for(int i=0;i<a;i++)
    {
        int smallest=0;
        while(num[smallest]==-1) smallest++;
        for(int j=0;j<a;j++)
        {
            if(smallest==j)
                continue;
            else if(num[j]==-1) continue;
            else if(num[smallest]>num[j])
                smallest=j;
            else if((num[smallest]==num[j])&&(strcmp(s[smallest],s[j])>0))
                smallest=j;
        }
        printf("%s\n",s[smallest]);
        num[smallest]=-1;
    }
    return 0;
}
