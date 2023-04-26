#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
       char str[120];
       gets(str);
       int len=strlen(str);//一行字符的个数
       int count=0;//一行字符中1的个数
       for(int k=0;k<len;k++)//对每一个字符来说
       {  
          n=str[k]; 
          for(int p=0;p<8;p++)
          {
              if((n>>>p)&1==1) count++;
          }
        }
          int max,o,b;
       int GCD(int m,int n)//求最大公约数
       {
           int c;
           if(m<n) c=m,m=n,n=c ;
           if(m%n==0) return n;
           else {m=m%n;return GCD(m,n);}
       }
       max=GCD(len*8,count);
       o=len*8/max;//分母
       b=count/max;//分子
       printf("%d/%d\n",b,o);
       getchar();
    }
    return 0;
    
}