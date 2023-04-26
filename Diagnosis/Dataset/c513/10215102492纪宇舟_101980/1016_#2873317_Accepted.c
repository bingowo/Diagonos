#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char ans[1005];
int main()
{
	int x,y,cnt=0;
	int N,R;scanf("%d%d",&N,&R);
	do
	{
		x=N%R;y=N/R;N/=R;
		//printf("%d %d %d\n",N,y,x);
		if(x<0)
		{
			x-=R;N++;
		}
		//else if(x>0)x=x+1;
		if(x>=0&&x<=9)ans[++cnt]=x+'0';
		else ans[++cnt]=x-10+'A';
		
	}while(N!=0);
	for(int i=cnt;i>=1;i--)printf("%c",ans[i]);
	return 0;
}