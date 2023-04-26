#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int T,N;
typedef struct { 
	int val;
	int y; 
	int d;   
	char m[10]; 
} RECORD;
RECORD record[100001];
int findval(char* m)
{   
	static char *month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};    
    for (int i=0; ;i++)     
        if (!strcmp(m,month[i])) 
		return i;  
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
    	scanf("%d",&N);
    	for (int j=0;j<N;j++)
 	{
      	scanf("%d",&record[j].d);
      	char c=getchar();
      	c=getchar();
      	scanf("%s",record[j].m);
      	c=getchar();
      	scanf("%d",&record[j].y);
      	record[j].val=record[j].y*365+findval(record[j].m)*20+record[j].d;
	}
    	qsort(record,N,sizeof(record[0]),cmp);
    	printf("case #%d:\n",i);
		for (int j=0;j<N;j++) 
     		printf("%d. %s %d\n",record[j].d,record[j].m,record[j].y);
	}
	return 0;
}