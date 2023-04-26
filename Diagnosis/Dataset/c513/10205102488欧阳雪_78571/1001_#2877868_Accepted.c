#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	for(int i;i<T;i++)
	{
	    int N,R,j=0,a=0;
		scanf("%d%d",&N,&R);
		if(N<0)
		{
			N=-N;
			a=-1;
		}
		int ans[100]={0};
		while(N/R>0)
		{
			ans[j]=N%R;
			N=N/R;
			j++;
		}
		ans[j]=N;
		if(a==-1)printf("-");
		while(j>=0)
		{
			if(ans[j]>=10){
				printf("%c",ans[j]+55);
			}
			else printf("%d",ans[j]);
			j=j-1;
		}
		printf("\n");
	}
	return 0;
 } 