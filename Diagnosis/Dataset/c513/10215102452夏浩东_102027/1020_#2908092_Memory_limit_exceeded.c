#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef struct{
    int time[5];
    int space;
    char s[128];
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
    int num=-1;
    while(num!=0){
        if(num!=-1) printf("\n");
        char order[5];
        scanf("%d",&num);
        File *L =(File*)malloc(num*sizeof(File));
        for(int i=0;i<num;i++)
        {
            scanf("%d-%d-%d %d:%d",&L[i].time[0],&L[i].time[1],&L[i].time[2],&L[i].time[3],&L[i].time[4]);
            scanf("%d %s",&L[i].space,L[i].s);
        }
        scanf("List /%s",order);
        if(order[0]=='T') qsort(L,num,sizeof(File),cmp1);
        else if(order[0]=='S') qsort(L,num,sizeof(File),cmp2);
        else qsort(L,num,sizeof(File),cmp3);
        for(int i=0;i<num;i++)
        {
            printf("%d-%d-%d %d:%d",L[i].time[0],L[i].time[1],L[i].time[2],L[i].time[3],L[i].time[4]);
            printf("%+16d %s\n",L[i].space,L[i].s);
        }
    }
    return 0;
}