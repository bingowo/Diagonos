#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,j=0,k=0,g,n=0,n1=0,ans=0;
	
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		char a[100]={0},b;
		j=0,k=0,g=0,n=0,n1=0,ans=0;
		scanf("%s",a);
		j=1;b=a[0];
		while(a[j]!='\0')
		{
			
			if(a[j]==b)
			{
				k=j-1;
				while(a[k]==b&&a[k]!='\0')
				{
					while(a[k]!='\0')
					{
						a[k]=a[k+1];k++;
					}
					k=j-1;
					ans++;
				}
				b=a[j-1];
			}
			else
			{
				j++;
				b=a[j-1];
			}
		}
		k=1;g=1;
		while(a[k+g]!='\0')
		{
			if(a[k-g]==a[k+g])
			{
				g++;n1=n1+2;
			}
			else
			{
				if(n1>n){n=n1;n1=0;k++;g=1;}
				else{n1=0;k++;g=1;}
			}
		}
		if(n1>n) {n=n1;n1=0;}
		if(a[0]!=0||n!=0) ans=ans+n+2;
		else ans=ans+1;
		printf("case #%d:\n%d\n",i,ans);
	}

	
	
	

	
	return 0;
	
	
 } 