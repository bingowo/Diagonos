#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
char a[10],b[10];
int process()
{
	int n=strlen(a);
	for(int i=0;i<n;i++)
	b[n-i-1]=a[i];
	for(int i=0;i<n;i++)
	if(a[i]!=b[i])return 1;
	return 0;
}
int main()
{
	int x,cnt=0;scanf("%d",&x);
	itoa(x,a,10);
	while(process())
	{
		++cnt;
		x=atoi(a)+atoi(b);
		itoa(x,a,10);
	}
	printf("%d %d",cnt,atoi(a));
	return 0;
} 