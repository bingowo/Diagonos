#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int t,a[10],b,e=1;
	for(int i=0;i<10;i++)
	{
		a[i]=0;
	}
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&b);
		int c=3;e=1;
		while(b!=0)
		{
			if((b&1)==0)
			{
				if(c==1){e++;c=0;b=b>>1;if(e>a[i]){a[i]=e;}}
				else{if(e>a[i]){a[i]=e;}e=1;c=0;b=b>>1;}
			}
			else
			{
				if(c==0){e++;c=1;b=b>>1;if(e>a[i]){a[i]=e;}}
				else{if(e>a[i]){a[i]=e;}e=1;c=1;b=b>>1;}
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n%d\n",i,a[i]);
	}
	
	return 0;
	
	
 } 