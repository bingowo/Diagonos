#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{

    char a[501];
    scanf("%s",a);
    int l,len;
    l=len=strlen(a);
    printf("0001");
    int f[10]={0};//转换成二进制
     int ct=0;
		  while(len!= 0)
		{   f[ct] = len%2;
			ct++;
			len/= 2;
		}
  	for(int r=9;r>=0;r--)
  	printf("%d",f[r]);
      if(l%3==0)  
        {
            int z=l/3;//组数
            for(int k=0;k<z;k++)
           {
               char b[3]={} ;
           strncpy(b,a+k*3,3);
           int c=atoi(b);
           int x[10]={0};
           int w=0;
           while(c!= 0)
		{   x[w] = c%2;
			w++;
			c/= 2;
		}
		for(int i=9;i>=0;i--)
		printf("%d",x[i]);}

          }
	
	if(l%3==1)
	{
	    int z=l/3;//组数
            for(int k=0;k<z;k++)
           {
               char b[3]={} ;
           strncpy(b,a+k*3,3);
           int c=atoi(b);
           int x[10]={0};
           int w=0;
           while(c!= 0)
		{   x[w] = c%2;
			w++;
			c/= 2;
		}
		for(int i=9;i>=0;i--)
		printf("%d",x[i]);}
		int e[4]={0};
		int g=0;
           while(a[len-1]!= 0)
		{   e[g] = m%2;
			g++;
			a[len-1]/= 2;
		}
		for(int i=3;i>=0;i--)
		printf("%d",e[i]);
	}
	if(l%3==2)
	{
	    int z=l/3;//组数
            for(int k=0;k<z;k++)
           {
               char b[3]={} ;
           strncpy(b,a+k*3,3);
           int c=atoi(b);
           int x[10]={0};
           int w=0;
           while(c!= 0)
		{   x[w] = c%2;
			w++;
			c/= 2;
		}
		for(int i=9;i>=0;i--)
		printf("%d",x[i]);}
		char s[2]={};
		strncpy(s,a+z*3,2);
		int m=atoi(s);
           int e[7]={0};
           int g=0;
           while(m!= 0)
		{   e[g] = m%2;
			g++;
			m/= 2;
		}
		for(int i=6;i>=0;i--)
		printf("%d",e[i]);
	}
	 return 0;
}