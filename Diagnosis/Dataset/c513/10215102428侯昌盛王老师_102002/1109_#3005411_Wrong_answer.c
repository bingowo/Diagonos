#include <stdio.h>

int main()
{
	int t,e;
	scanf("%d",&t);
	for(e=0;e<t;e++)
	{
		int a[9];
		int k=8,count=0;
		for(k;k>=0;k--) scanf("%d",&a[k]);
		k=8;
		while(a[k]==0){
			
			if(k==0)
			{
				count=1;
			
				printf("case #%d:\n",e);
				goto ans;
			}
			else if(k<=2&&(a[1]!=0||a[0]!=0))
			{
				printf("case #%d:\n",e);
				count=2;
				if(a[1]==0) count=3;
				goto aw;
			}
			k--;
			
		}
		printf("%d\n",k);
		printf("case #%d:\n",e);

		if(a[k]==1) printf("x^%d",k);
		else if(a[k]==-1) printf("-x^%d",k);
		else printf("%dx^%d",a[k],k);
		k--;
		
		for(k;k>1;k--)
		{
			if(a[k]==1) printf("+x^%d",k);
			else if(a[k]==-1) printf("-x^%d",k);
			else
			{
				if(a[k]>0) printf("+%dx^%d",a[k],k);
				else if(a[k]<0) printf("%dx^%d",a[k],k);
			
					
			}
			
		}
		aw:
		
		
			if(a[1]==1&&count!=2) printf("+x");
			else if(a[1]==1) printf("x");
			else if(a[1]==-1) printf("-x");
			else if(a[1]!=0){
				if(a[1]>0&&count!=2) printf("+%dx",a[1]);
				
				else printf("%dx",a[1]);
			}
		
		
		
			if(a[0]>0&&count!=3) printf("+%d",a[0]);
			else if(a[0]>0) printf("%d",a[0]);
			else if(a[0]<0) printf("%d",a[0]);
		
	
		
		ans:
			if(count==1)
			{
				
				printf("0");
			}
		printf("\n");
		
	}
}