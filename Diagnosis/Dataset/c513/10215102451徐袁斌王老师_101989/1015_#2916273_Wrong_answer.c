#include<stdio.h>
#include<math.h>
#include<string.h>
int f(int a,int b,int c,int k)
{
	int sushu[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
	if(a+b+c<sushu[k]) return 0;
	else return 1;
}
int g(int a,int b,int c,int k)
{
	int sushu[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
	if(a+b+c<sushu[k]) return a+b+c;
	else return a+b+c-sushu[k];
}
int main()
{
	int t,a[10][25],b[10][25],c[2],m=0,n=0,max=0,ans[27]={0};
	char x[100];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		for(int l=0;l<26;l++)
		{
			a[i][l]=0;
			b[i][l]=0;
			ans[l]=0;
		}
		for(int l=0;l<100;l++)
		{
			x[l]='\0';
		}
		c[0]=0;c[1]=0;ans[25]=0;ans[26]=0;
		m=0,n=0,max=0;
		scanf("%s",x);
		int j=0;
		while(x[j]!='\0')
		{
			while(x[j]!=0&&x[j]!=',')
			{
				a[i][m]=(a[i][m])*10+x[j]-48;j++;
			}
			m++;j++;
		}
		scanf("%s",x);j=0;
		while(x[j]!='\0')
		{
			
			while(x[j]!='\0'&&x[j]!=',')
			{
				b[i][n]=(b[i][n])*10+x[j]-48;j++;
			}
			n++;j++;
		}
		m--;n--;
		if(m>n) max=m;
		else max=n;
		for(int k=0;k<=max+1;k++)
		{
			if(n==-1) 
			{
				n=0;
				b[i][0]=0;
			}
			if(m==-1) 
			{
				m=0;
				a[i][m]=0;
			}
			ans[max+1-k]=g(a[i][m],b[i][n],c[0],k);
			c[0]=f(a[i][m],b[i][n],c[0],k);
			m--;n--;
		}
		printf("case #%d:\n",i);
		int k=0;
		while(ans[k]!=-1&&k<=max)
		{
			printf("%d",ans[k]);k++;
			if(ans[k+1]!=-1) printf(",");
		}
		printf("%d",ans[max+1]);
		printf("\n");
		
	}
	return 0;
	
	
 } 