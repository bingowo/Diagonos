#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{
	int sig;
	char num[21];
}NUM;
int cmp(const void* a,const void* b)
{
	NUM x=*(NUM*)a;NUM y=*(NUM*)b;
	if(x.num[0]>y.num[0])return -1;
	else if(x.num[0]==y.num[0])
	{
		if(x.sig!=y.sig)return x.sig;
		int l1=strlen(x.num),l2=strlen(y.num);
		if(x.sig==1)
		{
			if(l1<l2)return -1;
			else if(l1==l2)return strcmp(x.num,y.num);
			else return 1;
		}
		if(l2<l1)return -1;
		else if(l1==l2)return strcmp(y.num,x.num);
		else return 1;
	}
	else return 1;
}
int main()
{
	char ipt[21];NUM a[10001];
	int ct=0,T;scanf("%d\n",&T);
	while(T--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",ipt);
			if(ipt[0]=='-')
			{
				a[i].sig=-1;
				strcpy(a[i].num,ipt+1);
			}
			else
			{
				a[i].sig=1;
				strcpy(a[i].num,ipt);
			}
		}
		qsort(a+1,n,sizeof(NUM),cmp);
		printf("case #%d:\n",ct++);
		for(int i=1;i<=n;i++)
		{
			if(a[i].sig==-1)printf("-");
			printf("%s",a[i].num);
			if(i!=n)printf(" ");
		}printf("\n");
	}
	return 0;
}