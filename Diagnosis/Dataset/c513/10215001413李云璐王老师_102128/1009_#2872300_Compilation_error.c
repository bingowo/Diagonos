#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
       char str[120]={0};
       gets(str);
       int len,cnt=0;
       len=strlen(str);//字符的个数
       int count=0;//1的个数
       for(int k=0;k<len;k++)
       {
          n=str[k]; 
          int a[100];//转换成二进制
		  while(n != 0)
		{
			a[cnt] = n%2;
			cnt++;
			n /= 2;
		}
		int count=0;//1的个数
		for(int l=0;l<=cnt;l++)
		{
		    if(a[l]==1) count++； 
		}
		
       }
       int max,a,b;
       int GCD(int m,int n)//求最大公约数
       {
           int c;
           if(m<n) c=m,m=n,n=c ;
           if(m%n==0) return n;
           else {m=m%n;return GCD(m,n);}
       }
       max=GCD(len*8,count);
       a=len*8/max;
       b=count/max;
       printf("%d/%d",a,b);
       
    }
    return 0;
    
}