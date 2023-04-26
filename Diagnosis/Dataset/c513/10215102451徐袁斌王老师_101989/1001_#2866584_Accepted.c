#include<stdio.h>
int main()
{
	int t,n,r;
	scanf("%d",&t);
	int a[100][100];
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&n,&r);
		int j=2;
		a[i][0]=0;
		if(n<0){a[i][1]='-';n=-n;}
		else{a[i][1]='+';}
		while(n!=0)
		{
			a[i][j]=n%r;
			j++;
			n=n/r;
		}
		a[i][0]=j-1;
	}
	for(int i=0;i<t;i++)
	{
		if(a[i][1]=='-'){printf("-");}
		for(int m=a[i][0];m>1;m--)
		{
		if(a[i][m]<10){printf("%d",a[i][m]);}
		else{printf("%c",'A'+a[i][m]-10);}
		}
		printf("\n");
	}
	return 0;
	
	
 } 