#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() 
{ 	int t,T;
	scanf("%d\n",&T);
	for(t=0;t<T;t++)
	{	
		int co[9]={0};
		int i;
		for(i=8;i>=0;i--) scanf("%d",&co[i]);
		printf("case #%d:\n",t);
		for(i=8;i>=0&&co[i]==0;i--);
		if(i==-1) printf("0\n");
		else 
	{	int j=i;
		for(;i>=0;i--)
		{	if(co[i]==0) continue;
		
			if(i==0&&co[i]>0&&i<j) putchar('+');//'+'
			if(i==0&&co[0]>0) printf("%d",co[0]);//带符号系数 
			else if(i==0&&co[0]<0) printf("%d",co[0]);
			
			else if(i>0)
			{
			if(co[i]>0&&i<j) putchar('+');//'+'
			
			if(!(co[i]==1||co[i]==-1)) printf("%d",co[i]);//输出非1和-1的系数 
			
			if(co[i]==-1) printf("-x");//未知数 
			else printf("x");
			
			if(i!=1) printf("^%d",i);//次数 
			
			}
			
		}
		putchar('\n');
	}
	}
    return 0;
}
