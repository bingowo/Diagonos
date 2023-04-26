#include<stdio.h>

cmp(const void* a,const void* b);
month2idx(char* m);
typedef struct {
	int val; //表示日期“大小”的值
	int y; //年
	int d; //日
	char m[7]; //玛雅历的月份
} RECORD;
int main()
{
	int T;
	scanf("%d",&T);
	int j=0;
	for(j;j<T;j++)
	{
		int i=0,N;
		scanf("%d\n",&N);
		RECORD a[N];
		for (i;i<N;i++) 
		{
	//输入日月年
			scanf("%d.%s %d\n", &a[i].d, &a[i].m, &a[i].y);
			// 若日的权值为1，则月的权值>=20，年的权值
			//>=19*月的权值，这样保证年、月、日的优先级
			//加权和得到日期大小
			a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
		}
		qsort(a, N, sizeof(RECORD), cmp);
		printf("case #%d:\n",j);
		i=0;
		for (i;i<N;i++)
			printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
	}
}

int month2idx(char* m)
{ 	int i;
	//1-19月份数组，为静态字符串数组
	static char* month[] =
	{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
	
	
	//顺序比较月份字符串，相同则返回编号i
	for (i=0;;i++) if (!strcmp(m,month[i])) return i;
}

int cmp(const void* a,const void* b)
{ return
((RECORD*)a)->val - ((RECORD*)b)->val; }

