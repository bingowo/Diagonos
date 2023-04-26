#include <stdio.h>
#include <string.h>
#define N 500
int input(int *a)
{
	char s[N+1];
	scanf("%s",s);
	int len=strlen(s)-1,i,j=0;
	for(i=len;i>=0;i--) a[j++]=s[i]-'0';
	return len;
}
void m(int *a,int *b,int pa)
{
	int i=0,t=0;
	while(i<=pa)
	{
		a[i]-=t;
		if(a[i]<b[i])
		{
			a[i]+=10;
			t=1;
		}
		else t=0;
		b[i]=a[i]-b[i];
		i++;
		
	}
}
int main()
{
	while(1)
	{
		int a[N]={0},b[N]={0},pa,pb,t=1;
		pa=input(a);pb=input(b);
	//	printf("%d %d\n",a[0],b[0]);
		m(a,b,pa);
	//	printf("%d\n",b[0]);
		int k=pa;
		for(k;b[k]==0;k--);
		for(k;k>=0;k--) printf("%d",b[k]);
		printf("\n");
	}
	return 0;
}