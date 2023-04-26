#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char *s1;
    char *s2;
}YJ;
int cmp(const void *a,const void *b)
{
    YJ *A= (YJ*)a;
    YJ *B= (YJ*)b;
    int res =strcmp(A->s2,B->s2);
    if(res==0) res=strcmp(B->s1,A->s1);
    return res;
}
int main()
{
    int num=0;
    scanf("%d",&num);
    YJ *L=(YJ*)malloc(num*sizeof(YJ));
    for(int i=0;i<num;i++)
	{
		char *p1=(char*)malloc(10000*sizeof(char));
		char *p2=(char*)malloc(10000*sizeof(char));
		scanf("%s@%s\n",p1,p2);
		L[i].s1=p1;
		L[i].s2=p2;
	}
    qsort(L,num,sizeof(YJ),cmp);
    int i=0;
    for(i=0;i<num-1;i++)
    {
    	printf("%s@%s\n",L[i].s1,L[i].s2);
    	free(L[i].s1);
    	free(L[i].s2);
	}
	printf("%s@%s",L[i].s1,L[i].s2);
	free(L[i].s1);
	free(L[i].s2);
	free(L);
    return 0;
}