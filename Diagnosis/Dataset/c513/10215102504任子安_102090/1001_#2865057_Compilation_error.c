#include<stdio.h>
#include<math.h>
#define MAX 100100

char a[MAX];
char str[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
	int a,n,x,k,flag,i,j;
	scanf("%d",&a);
	while(scanf("%d %d",&n,&x)!=EOF){
		flag=0;
		if(n<0)
		{
			flag=1;
			n=-n;
		}
		i=0;
		while(n)
		{
			k=n%x;
			a[i]=str[k];
			n/=x;
			i++;
		}
		if(flag)
		{
			printf("-");
		}
		for(j=i-1;j>=0;j--)
		{
			printf("%c",a[j]);
		}
		printf("\n");
	}
	return 0;
}