#include<stdio.h>
#include<string.h>
int main()
{
	char m[32];
	int i,j,t,temp,x,k,result;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		j=0;temp=1;result=0;
		scanf("%d",&x);
		while(x!=0)
		{
			m[j++]=x%2;
			x=x/2;
		}
		for(k=0;k<j-1;k++)
		{
			if(m[k]!=m[k+1])temp++;
			else
			{
				if(result<temp)result=temp;	
				temp=1;
			}			
		}
		if(result<temp)result=temp;	
		printf("case #%d:\n%d\n",i,result);
	}
}