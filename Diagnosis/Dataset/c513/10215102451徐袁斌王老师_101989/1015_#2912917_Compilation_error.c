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
	int t,a[10][25]={0},b[10][25]={0},c[2]={0},m=0,n=0,max=0,ans[27]={0};
	char x[100];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		a[10][25]={0},b[10][25]={0},c[2]={0},m=0,n=0,max=0,ans[27]={0};
		scanf("%s",x);
		int j=0;
		while(x[j]!='\0')
		{
			if(x[j]!=',') {a[i][m]=x[j]-48;m++;}
			j++;
		}
		scanf("%s",x);j=0;
		while(x[j]!='\0')
		{
			if(x[j]!=',') {b[i][n]=x[j]-48;n++;}
			j++;
		}
		m--;n--;
		if(m>n) max=m;
		else max=n;
		for(int k=0;k<=max+1;k++)
		{
			if(n<0) b[i][n]=0;
			if(m<0) a[i][m]=0;
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
		printf("%d",ans[k+1]);
		printf("\n");
	}
	return 0;
	
	
 } 