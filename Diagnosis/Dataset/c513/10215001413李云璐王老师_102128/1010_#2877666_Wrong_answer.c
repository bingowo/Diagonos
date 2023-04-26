#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    printf("0001");
    char a[500];
    scanf("%s",&a);
    int len;
    len=strlen(a);
    int f[9]={0};//转换成二进制
     int ct=0;
		  while(len!= 0)
		{   f[ct] = len%2;
			ct++;
			len/= 2;
		}
	
		for(int r=9;r>=0;r--)
		printf("%d",f[r]);
    if(len%3==0) 
    {   int z=len/3;//组数
        for(int i=0;i<z;i+=3)
        {
           char b[2] ;
           strncpy(b,a+i,3);
           int c=atoi(b);
           int d[10]={0};//转换成二进制
           int cnt=0;
		  while(c != 0)
		{   
			d[cnt] = c%2;
			cnt++;
			c /= 2;
		}
		d[cnt+1]=0;
		for(int e=9;e>=0;e--)
		printf("%d",d[e]);
	    }
	    
        
        
        
    }
    return 0;
}