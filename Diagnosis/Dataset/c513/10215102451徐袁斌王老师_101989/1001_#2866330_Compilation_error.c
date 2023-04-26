#include<stdio.h>
int main()
{
	int t,n,r;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&n,&r);
		int a[i][100],j=2;
		a[i][0]=0;
		if(n<0){a[i][1]='-';n=-n;}
		else{a[i][1]='+';}
		while(n>=r)
		{
			a[i][j]=n%r;
			j++;
			n=n/r;
		}
		a[i][j]=1;
		a[i][0]=j;
	}
	for(i=0;i<t;i++)
	{
		if(a[i][1]=='-'){printf("-");}
		for(int m=a[i][0];m>1;m++)
		{
		if(a[i][m]<10){printf("%d",a[i][m]);}
		else{printf("%s",A+a[i][m]-9;)}
		}
		printf("/n");
	}
	return 0;
	
	
 } 