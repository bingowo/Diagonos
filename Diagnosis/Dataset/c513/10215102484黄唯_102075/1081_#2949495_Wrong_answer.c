#include<stdio.h>
#include<stdlib.h>

#define N 95

void mul(int *result,int a,int n)
{
	int carry = 0;
	for(int j = 0;j < n ;j++)
	{
	
		for(int i = 0;i < N; i++)
		{
			int t = result[i] * a +carry;
			
			if(t > 9)
			{
		
				result[i] = t % 10;
				
		
				carry = t / 10;	
				
			
	    	}
	    	else 
			{
				result[i] = t;
				carry = 0;
	    	
			}
	    	
		}
	}
 } 
 int main()
 {
 	int a,n,T;
 	int result[95] = {1} ;
	
 	
 	int *p = result;
 	
 	scanf("%d",&T);
 	for(int i = 0;i < T;i++)
 	{
 		scanf("%d%d",&a,&n);
		mul(p,a,n) ;
		printf("case #%d:\n",i);
		
		
		
		
		int flag = n+1;
		do{flag =flag-1;
		}
		while(result[flag]== 0);
		for(int i =flag;i>=0;i--)
		{
			printf("%d",result[i]);
			if(i = 0) printf("\n");
		}
	
	
		
	 }
 }