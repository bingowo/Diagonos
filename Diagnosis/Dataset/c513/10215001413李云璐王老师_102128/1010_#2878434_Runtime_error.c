#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{

    char a[500];
    scanf("%s",a);
    int l,len;
    l=len=strlen(a);
    printf("0001");
    int f[9]={0};//转换成二进制
     int ct=0;
		  while(len!= 0)
		{   f[ct] = len%2;
			ct++;
			len/= 2;
		}

		for(int r=9;r>=0;r--)
		printf("%d",f[r]);
    if(l%3==0)
    {   int z=l/3;//组数
        for(int i=0;i<z;i+=3)
        {
           char b[2]={} ;
           strncpy(b,a+i,3);
           int c=0;
           for(int g=2;g>=0;g--)
           c=c*10+b[g];
           printf("%d\n",c);}
           
          

    }
    return 0;
}