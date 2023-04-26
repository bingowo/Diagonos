#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* table[19]={"pop","no","zip","zotz","tzec","xul", "yoxkin", "mol", "chen", "yax", "zac","ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

typedef struct
{
	int day; int month; int year;
}maya;

int cmp (const void *a,const void *b)
{
	maya m = *(maya*)a, n = *(maya*)b;
	
	if(m.year == n.year)
	{
		if(m.month == n.month)
			return m.day - n.day;
		else
			return m.month - n.month;
	}
	else
		return m.year - n.year;
}

int main()
{
	int T;
	scanf("%d",&T);
	
	for(int i=0;i<T;i++)
	{
		int N;
		scanf("%d",&N);
		maya *p = (maya *)calloc(N,sizeof(maya));
		
		for(int i=0;i<N;i++)
		{
			char temp[10]={0};
			scanf("%d. %s %d",&p[i].day,temp,&p[i].year);
			
			for(int j=0;j<19;j++)
			{
				if(strcmp(table[j],temp) == 0)
				{
					p[i].month = j;
					break;
				}
					
			}
		}
		qsort(p,N,sizeof(maya),cmp);
		
		printf("case #%d:\n",i);		
		for(int i=0;i<N;i++)
		{
			printf("%d. %s %d\n",p[i].day,table[p[i].month],p[i].year);
		}
	}
	
	return 0;
}