#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int num[1005][2],len1,len2;
int main()
{
	long long x,y; 
	scanf("%lld%lld",&x,&y);
	if(x==0&&y==0)
		printf("0");
	else if((x+y)%2==0)
		printf("-1");
	else
	{
		int op1=1,op2=1;
		if(x<0)
		{
			x=-x;op1=-1;
		}
		if(y<0)
		{
			y=-y;op2=-1;
		}
		while(x)
		{
			num[++len1][0]=x%2;
			x>>=1;
		}
		while(y)
		{
			num[++len2][1]=y%2;
			y>>=1;
		}
		if(len2>len1)
			len2=len1;
		for(int i=1;i<=len1;i++){
		if(num[i][0]==1&&num[i][1]==1)
		{
			int pos=i+1;
			if(num[i-1][0]==1){ 
				num[i-1][0]=-1;
				num[i][0]=0;
				num[i+1][0]++;
				while(num[pos][0]>1) 
				{
					num[pos+1][0]+=num[pos][0]/2;
					num[pos][0]%=2;
					pos++; 
				}
				if(pos>len1 && num[pos][0]>0) 
					len1=pos; 
			}
			else if(num[i-1][1]==1)
			{
				num[i-1][1]=-1;
				num[i][1]=0;
				num[i+1][1]++;
				while(num[pos][1]>1) 
				{
					num[pos+1][1]+=num[pos][1]/2;
					num[pos][1]%=2;
					pos++;
				}
				if(pos>len1 && num[pos][1]>0) 
					len1=pos; 
			}else puts("-1"),exit(0);
		}
		else if(num[i][0]==0&&num[i][1]==0)
		{ 
			if(num[i-1][0]==1) 
			{
				num[i-1][0]=-1;
				num[i][0]=1; 
			}
			else 
			{
				num[i-1][1]=-1;
				num[i][1]=1;
			}
		}
	}
	printf("%d\n",len1);
	}
	return 0;
 }