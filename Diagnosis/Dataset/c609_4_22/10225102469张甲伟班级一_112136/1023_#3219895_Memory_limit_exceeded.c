#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int T,N;
char month[19][20]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
typedef struct { 
	int val;
	int y; 
	int d;   
	char m[10]; 
} RECORD;
RECORD record[10001];
int findval(char* m)
{       
    for (int i=0; ;i++)     
        if (!strcmp(m,month[i])) 
		return i;   //返回月份编号i  
}

int cmp(const void *e1,const void *e2)
{
    return ((RECORD*)e1)->val-((RECORD*)e2)->val;
}
int main()
{
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
    	for (i=0;i<N;i++)
 	{
      	scanf("%d.%s %d",&record[i].d,record[i].m,&record[i].y);
      	record[i].val=record[i].y*365+findval(record[i].m)*20+record[i].d;
	}
    	qsort(record,N,sizeof(record[0]),cmp);
    	printf("case #%d\n",i);
		for (int j=0;j<N;j++) 
     		printf("%d. %s %d\n",record[i].d,record[i].m,record[i].y);
	}
	return 0;
}