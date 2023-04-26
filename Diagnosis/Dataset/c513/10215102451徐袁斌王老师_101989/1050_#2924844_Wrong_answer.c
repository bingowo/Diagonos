#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int n,start=0,end=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		char a[80]={0},b[80]={0},c[80]={0};
		scanf("%s",a);
		scanf("%s",b);
		scanf("%s",c);
		int j=0,k=0,g=0,x=0;
		while(c[k]!='\0')
		{
			if(a[j]=='\0')
			{
				if(x==1) {start=k-1;break;}
			}
			if(a[j]==c[k])
			{
				j++;k++;x=1;
			}
			else
			{
				j=0;k++;x=0;
			}
		}
		k=strlen(c)-1;g=strlen(b)-1;x=0;
		while(k!=0)
		{
			if(g==-1)
			{
				if(x==1) {end=k+1;break;}
			}
			if(b[g]==c[k])
			{
				g--;k--;x=1;
			}
			else
			{
				g=strlen(b)-1;k--;x=0;
			}		
			
			
		}
		printf("case #%d:\n%d\n",i,end-start-1);
		start=0,end=0;
			
			
		
		
	}
	 
	return 0;
	
	
 } 