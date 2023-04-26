#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
	int val;
    int y;
    int d;
    char m[7];
}RECORD; 


int month2idx(char* m)
{
	int i;
	static char* month[] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
	for(i=0;;i++)
	if (!strcmp(m,month[i])) return i;
}
int cmp(const void*a,const void*b)
	{
	 return ((RECORD*)a)->val-((RECORD*)b)->val;
	} 
struct stu{
	int val;
    int y;
    int d;
    char m[7];
}a[10000];	
	
	
int main()
{
	int t,N,i,k;
	scanf("%d %d",&t,&N);
	for(int j=0;j<t;j++){
	    printf("case #%d\n",j);
	    for(i=0;i<N;i++){
		scanf("%d %s %d\n",&a[i].d,a[i].m,&a[i].y);
		a[i].val = a[i].y*1000 + month2idx(a[i].m)*20 + a[i].d;
	}
	qsort(a,N,sizeof(RECORD),cmp);
	for(k=0;k<N;k++)
	printf("%d. %s %d\n",a[k].d,a[k].m,a[k].y);
	}
}