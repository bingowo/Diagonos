#include <stdio.h>

int main()
{
	int t,e;
	scanf("%d",&t);
	for(e=0;e<t;e++)
	{
		int a[9];
		int k=8,count=0;;
		for(k;k>=0;k--) scanf("%d",&a[k]);
		k=8;
		while(a[k]==0){
			count++;k--;
			if(k==-1)
			{
				goto ans;
			}
		}

		printf("case #%d:\n",e);
		if(a[k]==1) printf("x^%d",k);
		else if(a[k]==-1) printf("-x^%d",k);
		else printf("%dx^%d",a[k],k);
		k--;
		
		for(k;k>1;k--)
		{
			if(a[k]==1) printf("x^%d",k);
			else if(a[k]==-1) printf("-x^%d",k);
			else
			{
				if(a[k]>0) printf("+%dx^%d",a[k],k);
				else if(a[k]<0) printf("%dx^%d",a[k],k);
				else count++;
					
			}
			
		}
		if(a[1]==0) count++;
		else{
			if(a[1]==1) printf("+x");
			else if(a[1]==-1) printf("-x");
			else{
				if(a[1]>0) printf("+%dx",a[1]);
				else printf("%dx",a[1]);
			}
		}
		if(a[0]==0) count++;
		else{
			if(a[0]>0) printf("+%d",a[0]);
			else printf("%d",a[0]);
		}
	
		
		ans:
			if(count==9)
			{
				printf("case #%d:\n",e);
				printf("0");
			}
		printf("\n");
		
	}
}