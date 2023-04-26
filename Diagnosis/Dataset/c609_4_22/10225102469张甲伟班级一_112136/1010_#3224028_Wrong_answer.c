#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int N,R;
char n[1000000];
int ans[1000000],tmp;
int A,B,i; 
char table[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void solve(int n,int m)
{
	if(n==0)
	{
		ans[i++]=0;
		return ;
	}
	int r=n%m;
	if(r<0)
	{
		r=r-m;
		ans[i++]=r;
		solve(n/m+1,m);
	}
	else
	{
		ans[i++]=r;
		solve(n/m,m);
	}
	return ;
} 
int main()
{
		scanf("%d",&N);
		scanf("%d",&R);
		solve(N,R);
		for(int k=i-1;k>=0;k--)
		{
			//printf("%d",ans[k]);
			printf("%c",table[ans[k]]);
		}
	return 0;
 } 