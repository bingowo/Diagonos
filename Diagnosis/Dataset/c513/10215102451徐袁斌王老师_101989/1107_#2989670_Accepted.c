#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int a[9];
		for(int j=0;j<9;j++) scanf("%d",&a[j]);
		printf("case #%d:\n",i);
		if(abs(a[0]-a[1]-a[3])%2==1) printf("0 ");
		else printf("1 ");
		if(abs(a[1]-a[0]-a[2]-a[4])%2==1) printf("0 ");
		else printf("1 ");	
		if(abs(a[2]-a[1]-a[5])%2==1) printf("0\n");
		else printf("1\n");		
		if(abs(a[3]-a[0]-a[4]-a[6])%2==1) printf("0 ");
		else printf("1 ");		
		if(abs(a[4]-a[1]-a[3]-a[5]-a[7])%2==1) printf("0 ");
		else printf("1 ");
		if(abs(a[5]-a[4]-a[2]-a[8])%2==1) printf("0\n");
		else printf("1\n");		
		if(abs(a[6]-a[7]-a[3])%2==1) printf("0 ");
		else printf("1 ");		
		if(abs(a[7]-a[4]-a[6]-a[8])%2==1) printf("0 ");
		else printf("1 ");		
		if(abs(a[8]-a[5]-a[7])%2==1) printf("0\n");
		else printf("1\n");		
			
	}
	
}