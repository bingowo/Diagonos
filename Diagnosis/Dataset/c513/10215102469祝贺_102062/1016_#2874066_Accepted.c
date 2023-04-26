#include<stdio.h>
char t[25]={"0123456789ABCDEFGHIJK"};
void solve(int num,int r)
{
	int out=0;
	if(num==0)return;
	if(num>0)
	{
		out=num%r;
		solve(num/r,r);
	}
	else if(num<0)
	{
		if(num%r==0)
		{
			out=0;
			solve(num/r,r);
		}
		else
		{
			int temp=num/r+1;
		out=num-temp*r;
		solve(temp,r);
		}
	}
	printf("%c",t[out]);
}
int main()
{
	int num,r;scanf("%d%d",&num,&r);
	//确保余数是正数且小于abs（num）
	solve(num,r);
	if(num==0)printf("0");
	//printf("%d\n",8/-3);
	return 0;
} 