#include<stdio.h>
typedef struct{int dis;char dir;} col;
int choose(int a,int b)
{
	if(a<b)return 0;
	else return 1;
}
int main()
{
	int M,N,i,j,tmp;scanf("%d %d\n",&M,&N);
	col a[201][201];
	for(i=0;i<M;++i)
		for(j=0;j<N;++j)
			scanf("%d",&a[i][j].dis);
	for(i=0;i<M;++i)
		for(j=0;j<N;++j)
		{
			if(i+j)
			{
				if(i==0)
				{
					a[i][j].dis+=a[i][j-1].dis;
					a[i][j].dir='R';
				}
				else if(j==0)
				{
					a[i][j].dis+=a[i-1][j].dis;
					a[i][j].dir='D';
				}
				else
				{
					tmp=choose(a[i-1][j].dis,a[i][j-1].dis);
					if(!tmp)
					{
						a[i][j].dis+=a[i-1][j].dis;
						a[i][j].dir='D';
					}
					else
					{
						a[i][j].dis+=a[i][j-1].dis;
						a[i][j].dir='R';
					}
				}
			}
		}
	char b[40000];int cnt=0;
	i=M-1;j=N-1;
	while(i+j)
	{
		b[cnt++]=a[i][j].dir;
		if(a[i][j].dir=='R')j--;
		else i--;
	}
	printf("%d\n",a[M-1][N-1]);
	for(i=cnt-1;i>=0;i--)printf("%c",b[i]);
	return 0;
}