#include<stdio.h>
 
#include<string.h>
 
#include<math.h>
 
//函数用法：把字符串转为数字
 
int huan(char a[],double b[],int len)
 
{
 
       int i,j=0,n;
 
       for(i=len-1;i>=0;i--)
 
       {
 
              if(a[i]=='-')
 
              {
 
                     n=-1;
 
              }
 
              else if(a[i]=='0')
 
              {
 
                     n=0;
 
              }
 
              else if(a[i]=='1')
 
              {
 
                     n=1;
 
              }
 
              b[j]=n;
 
              j++;
 
       }
 
}
 
int main()
 
{
 
       int k;
 
       scanf("%d",&k);
 
       while(k--)
 
       {
 
              char a[1000]={0};
 
              double b[1000]={0};
 
              int i,len,sum=0;
 
              scanf("%s",&a);
 
              len=strlen(a);
 
              huan(a,b,len);
 
              for(i=0;i<len;i++)
 
              {
 
                     sum+=b[i]*pow(3,i);//转换为十进制的方法
 
              }
 
              printf("%d\n",sum);
 
       }
 
}
