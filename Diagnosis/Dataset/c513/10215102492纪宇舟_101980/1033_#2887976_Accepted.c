#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{
	int day,month,year;
	char s_day[4],s_month[10];
}NUM;
int cmp(const void* a,const void* b)
{
	NUM x=*(NUM*)a;NUM y=*(NUM*)b;
	if(x.year<y.year)return -1;
	else if(x.year==y.year)
	{
		if(x.month<y.month)return -1;
		else if(x.month==y.month)
		{
			if(x.day<y.day)return -1;
			return 1;
		}
		else return 1;
	}
	else return 1;
}
int main()
{
	int ct=0,T;scanf("%d\n",&T);
	NUM a[10001];
	while(T--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s%s%d",a[i].s_day,a[i].s_month,&a[i].year);
			a[i].day=atoi(a[i].s_day);
			if(a[i].s_month[0]=='p')
			{
				if(a[i].s_month[1]=='o')a[i].month=1;
				else a[i].month=16;
			}
			else if(a[i].s_month[0]=='n')a[i].month=2;
			else if(a[i].s_month[0]=='z')
			{
				if(a[i].s_month[1]=='i')a[i].month=3;
				else if(a[i].s_month[1]=='o')a[i].month=4;
				else a[i].month=11;
			}
			else if(a[i].s_month[0]=='t')a[i].month=5;
			else if(a[i].s_month[0]=='x')a[i].month=6;
			else if(a[i].s_month[0]=='y')
			{
				if(a[i].s_month[1]=='o')a[i].month=7;
				else a[i].month=10;
			}
			else if(a[i].s_month[0]=='m')
			{
				if(a[i].s_month[1]=='o')a[i].month=8;
				else if(a[i].s_month[1]=='a')a[i].month=13;
				else a[i].month=15;
			}
			else if(a[i].s_month[0]=='c')
			{
				if(a[i].s_month[1]=='h')a[i].month=9;
				else if(a[i].s_month[1]=='e')a[i].month=12;
				else a[i].month=18;
			}
			else if(a[i].s_month[0]=='k')
			{
				if(a[i].s_month[1]=='a')a[i].month=14;
				else a[i].month=17;
			}
			else if(a[i].s_month[0]=='p')a[i].month=16;
			else a[i].month=19;
		}
		qsort(a+1,n,sizeof(NUM),cmp);
		printf("case #%d:\n",ct++);
		for(int i=1;i<=n;i++)
		printf("%s %s %d\n",a[i].s_day,a[i].s_month,a[i].year);
	}
	return 0;
}