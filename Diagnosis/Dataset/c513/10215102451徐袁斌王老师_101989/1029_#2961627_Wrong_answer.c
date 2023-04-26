#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	char* A=(char*)a;
	char* B=(char*)b;
	if((*A>='A')&&(*A<='Z')&&(*B>='A')&&(*B<='Z'))
	{
		if(*A>*B) return 1;
		else return -1;
	}
	else return -1;
}
int main()
{
	int t,d;
	char x[300];
	scanf("%d",&t);
	getchar();
	for(int i=0;i<t;i++)
	{
		gets(x);d=strlen(x);
		char*p=x;
		qsort(p,d,sizeof(char),cmp);
		printf("case #%d:\n",i);
		for(int j=0;j<d;j++) printf("%c",x[j]);
		printf("\n");
	}
}