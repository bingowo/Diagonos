#include <stdio.h>
#include <stdlib.h>

struct maya{
	int year;
	int month;
	int day;
	char m[7];
};

int trans(char*m)
{
	static char*month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
	int i=0;
	for(i;;i++) if(!strcmp(m,month[i])) return i;
}

int cmp(const void*a,const void*b)
{
	struct maya *p,*q;
	p=(struct maya*)a;
	q=(struct maya*)b;
	if((p->year)!=(q->year)) return (p->year)-(q->year);
	else{
		if((p->month)!=(q->month)) return (p->month)-(q->month);
		else return (p->day)-(q->day);
	}
}
int main()
{
	int t,i=0;
	scanf("%d",&t);
	for(i;i<t;i++)
	{
		int n,j=0;
		scanf("%d",&n);
		struct maya kk[100];
		for(j;j<n;j++){
			scanf("%d. %s %d",&kk[j].day,&kk[j].m,&kk[j].year);
			kk[j].month=trans(kk[j].m);
			
		}
		qsort(kk,n,sizeof(kk[0]),cmp);
		printf("case #%d:\n",i);
		int x=0;
		for(x;x<n;x++)
		{
			printf("%d, %s %d\n",kk[x].day,kk[x].m,kk[x].year);
		}
		
		
		
	}
	return 0;
}