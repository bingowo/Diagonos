#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef long long LL;
int ans=0,end=0;
char path[50]="00000000000000000000000000000000000000000000000000";
LL desx,desy;
LL pas[45]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296,8589934592,17179869184,34359738368,68719476736,137438953472,274877906944,549755813888,1099511627776};
LL ABS(LL x)
{
	if(x<0)return -x;
	return x;
}
void DFS(int step,LL posx,LL posy)
{
	if(end)return;
	if(step==ans)
	{
		if(posx==desx&&posy==desy)
		{
			end=1;
			for(int i=step;i>=1;i--)printf("%c",path[i]);
		}
		return;
	}
	if(posx-pas[step]>=-1e12)
	{
		path[step+1]='W';DFS(step+1,posx-pas[step],posy);
	}
	if(posy-pas[step]>=-1e12)
	{
		path[step+1]='S';DFS(step+1,posx,posy-pas[step]);
	}
	if(posx+pas[step]<=1e12)
	{
		path[step+1]='E';DFS(step+1,posx+pas[step],posy);
	}
	if(posy+pas[step]<=1e12)
	{
		path[step+1]='N';DFS(step+1,posx,posy+pas[step]);
	}
}
int main()
{
	scanf("%lld%lld",&desx,&desy);
	LL lap=ABS(desx)+ABS(desy);
	if(desx==0&&desy==0)
	{
		printf("0");return 0;
	}
	if((lap&1)==0)
	{
		printf("-1");return 0;
	}
	while(lap>=1)
	{
		++ans;lap>>=1;
	}
	printf("%d\n",ans);
	DFS(0,0,0);
	return 0;
}