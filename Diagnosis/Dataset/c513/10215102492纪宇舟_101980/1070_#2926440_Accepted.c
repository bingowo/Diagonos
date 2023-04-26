#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
long long f1[32],f0[32];//以1或0结尾的方案数 
int main()
{
	int x;
	memset(f1,0,sizeof(f1));
	memset(f0,0,sizeof(f0));
	f1[1]=f0[1]=1;
	for(int i=2;i<=31;i++)
	{
		f0[i]=f0[i-1]+f1[i-1];
		f1[i]=f1[i-1]+(f0[i-1]-f1[i-2]);
	}
	while(scanf("%d",&x)&&x!=-1)
	printf("%lld\n",f1[x]+f0[x]); 
	return 0;
}