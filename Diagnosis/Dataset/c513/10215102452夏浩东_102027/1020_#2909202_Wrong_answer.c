#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef struct{
    int time[5];
    int space;
    char s[129];
}File;
int cmp1(const void *a,const void *b)
{
    File *A=(File*)a;
    File *B=(File*)b;
    for(int i=0;i<5;i++)
    {
        if(A->time[i] > B->time[i]) return 1;
        else if(A->time[i] < B->time[i]) return -1;
    }
    return 0;
}
int cmp2(const void *a,const void *b)
{
    File *A=(File*)a;
    File *B=(File*)b;
    if(A->space > B->space) return 1;
    else return -1;
}
int cmp3(const void *a,const void *b)
{
    File *A=(File*)a;
    File *B=(File*)b;
    if(strcmp(A->s,B->s) > 0)return 1;
    else return -1;
}
int main()
{
    int j=0;
    int num=-1;
    while(1)
	{
		scanf("%d",&num);
        if(num==0) break;
        if(j==1) printf("\n");
        File *L =(File*)malloc(num*sizeof(File));
        for(int i=0;i<num;i++)
        {
            scanf("%d-%d-%d %d:%d",&L[i].time[0],&L[i].time[1],&L[i].time[2],&L[i].time[3],&L[i].time[4]);
            scanf("%d %s",&L[i].space,L[i].s);
        }
        char c;
        for(int k=0;k<7;k++)
        {
            c=getchar();
        }
        char order[5];
        scanf("%s",order);
        if(order[1]=='T') qsort(L,num,sizeof(File),cmp1);
        else if(order[1]=='S') qsort(L,num,sizeof(File),cmp2);
        else qsort(L,num,sizeof(File),cmp3);
        for(int i=0;i<num;i++)
        {
            printf("%04d-%02d-%02d %02d:%02d %16d %s\n",L[i].time[0],L[i].time[1],L[i].time[2],L[i].time[3],L[i].time[4],L[i].space,L[i].s);
        }
        j=1;
        free(L);
    }
    return 0;
}