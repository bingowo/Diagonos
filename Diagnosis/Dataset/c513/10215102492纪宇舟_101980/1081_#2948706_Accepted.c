#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int ans[100005];
int main()
{
	int a,n,cnt;
	int ct=0,T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&n);cnt=1;
		printf("case #%d:\n",ct++);
		if(n==0){printf("1\n");continue;}
		ans[1]=a;
		while(--n>0)
		{
			int carry=0;
			for(int i=1;i<=cnt;i++)
			{
				ans[i]=ans[i]*a+carry;
				carry=ans[i]/10;
				ans[i]%=10;
			}
			if(carry!=0)ans[++cnt]=carry;
		}
		for(int i=cnt;i>=1;i--)printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}