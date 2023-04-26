#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long ans[51]; 
void cou(int k)
{
	ans[k]=ans[k-1]+ans[k-2]+ans[k-3]+ans[k-4];
	return;
}
int main()
{
	ans[1]=1;
	ans[2]=2;
	ans[3]=4;
	ans[4]=8;
	for(int i=5;i<51;i++) cou(i);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int m;
		scanf("%d",&m);
	//	int cnt=cou(m);	
		printf("case #%d: \n",i);
        printf("%lld\n",ans[m]);
	}
    return 0;
}
