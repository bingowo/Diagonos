#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long ans[74]; 
void cou(int k)
{
	ans[k]=ans[k-1]+ans[k-2]+ans[k-3];
	return;
}
int main()
{
	ans[0]=0;
	ans[1]=1;
	ans[2]=1;
	ans[3]=2;
	
	for(int i=4;i<75;i++) cou(i);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int m;
		scanf("%d",&m);
		//int cnt=cou(m);	
		printf("case #%d: \n",i);
        printf("%lld\n",ans[m]);
	}
    return 0;
}
