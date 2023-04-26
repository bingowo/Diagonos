#include <stdio.h>
#include <string.h>
int main()
{
	char b[100];
	int a[100]={0};
	int m,n;
	scanf("%d %d",&m,&n);
	int i,len=0;

	if((m%n)==0)
	{
	
		m=m/n;
	
		i=0;
		while(m){
			n=m%3;
			a[i]=n;
			
			m/=3;
		
			len++;
			i++;
		
		}
		
		for(i=0;i<len;i++)
		{
			if(a[i]==2)
			{
				a[i+1]=a[i]+1;
				if(i==len-1)
				{
					a[i+1]=1;
					len++;
				}
			}
			 
			if(a[i]==3)
			{
				a[i]=0;
				a[i+1]=a[i]+1;
				if(i==len-1){
					a[i+1]=1;len++;
				}
			}
		}
		for(i=len-1;i>=0;i--) printf("%d",a[i]);
	
	}
	
	return 0;
	
	
	
}