#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct R
{
    int day;
    int year;
    char mon[10];
    int m;
};
static char *ML[]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", 
	"mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
int cmp(const void *a,const void *b)
{
    struct R *A=(struct R*)a;
    struct R *B=(struct R*)b;
    if(A->year > B->year) return 1;
    else if(A->year < B->year) return -1;
    else
    {
        if(A->m > B->m) return 1;
        else if(A->m < B->m) return -1;
        else
        {
            if(A->day > B->day) return 1;
            else return -1;
        }
    }
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        int num=0;
        scanf("%d",&num);
        struct R* L=(struct R*)malloc(num*sizeof(struct R));
        for(int k=0;k<num;k++) scanf("%d.%s %d",&L[k].day,L[k].mon,&L[k].year);
        for(int j=0;j<num;j++)
        {
        	for(int k=0;k<19;k++)
        	{
            	if(strcmp(L[j].mon,ML[k])==0) L[j].m=k;
        	}
		}
        qsort(L,num,sizeof(struct R),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<num;k++) 
        {
            printf("%d. %s %d\n",L[k].day,L[k].mon,L[k].year);
        }
        free(L);
    }
    return 0;
}