#include<stdio.h>
#include<math.h>
#include<string.h>
int f(int a,int b,int k)
{
	int sushu[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
	if(a+b<sushu[k]) return 0;
	else return 1;
}
int g(int a,int b,int k)
{
	int sushu[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
	if(a+b<sushu[k]) return a+b;
	else return a+b-sushu[k];
}
int main()
{
	int t,a[10][25],b[10][25],c[2],i=0,m=0,n=0,max=0,sum[10][26];
	char x=0,y=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		x=getchar();
		while(x!=' ')
		{
			if(x!=',') {a[i][m]=x-48;m++;}
			x=getchar();
		}
		x=getchar();
		while(x!='\r')
		{
			if(x!=',') {b[i][n]=x-48;n++;}
			x=getchar();			
		}
		if(m>n) max=m;
		else max=n;
		for(int k=0;k<max;k++)
		{
			if(n<0) b[i][n]=0;
			if(m<0) a[i][m]=0;
			c[0]=f(a[i][m],b[i][n],k);
			c[1]=g(a[i][m],b[i][n],k);			
			if(c[0]==1) a[i][m-1]=a[i][m-1]+1;
			sum[i][max-k]=c[1];
			m--;n--;
		}
	}
	for(int i=0;i<t;i++)
	{
		printf("case #%d:\n",i);
		int k=0;
		while(sum[i][k]!='\0')
		{
			printf("%d",sum[i][k]);
			if(sum[i][k+1]!='\0') printf(",");
		}
		printf("\n");
	}
	
	
	
	

	
	return 0;
	
	
 } 