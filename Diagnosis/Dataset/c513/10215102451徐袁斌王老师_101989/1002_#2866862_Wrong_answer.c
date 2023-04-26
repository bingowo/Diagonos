#include<stdio.h>
int main()
{
	long long int t,b[10];
	int c[128];
	for(int i=0;i<128;i++)
	{
		c[i]=-1;
	}
	char a[10][60];
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s",a[i]);
		c[a[i][0]]=1;
		int j=1,k=0;
		while(a[i][j]!='\0')
		{
			if(c[a[i][j]]!=-1){
				j++;
			}
			else{c[a[i][j]]=k;
				if(k==0){k=k+2;}
				else{k++;}}
		}
		if(k<2){k=2;}
		long long int ans=1;j=1;
		while(a[i][j]!='\0')
		{
			ans=ans*k+c[a[i][j]];
			j++;
		}
		b[i]=ans;
	}
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n%lld\n",i,b[i]);
		
	}
	
	
	
	
	return 0;
	
	
 } 