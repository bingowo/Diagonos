#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int NAME_CMP(const void *a,const void *b);
    int SIZE_CMP(const void *a,const void *b);
    int TIME_CMP(const void *a,const void *b);
    int n = 0;
    typedef struct
    {
        char date[11];
        char clock[6];
        int bit;
        char name[127];
    } file;
    while(1){
        scanf("%d",&n);
        if(!n) break;
        char cmd[6];
        file L[n];
        for(int i=0;i<n;i++){
            scanf("%s%s%d%s",L[i].date,L[i].clock,&L[i].bit,L[i].name);
        }
        scanf("%s",cmd);
        scanf("%s",cmd);
        if(cmd[1] == 'N') qsort(L,n,sizeof(file),NAME_CMP);
        else if(cmd[1] == 'S') qsort(L,n,sizeof(file),SIZE_CMP);
        else if(cmd[1] == 'T') qsort(L,n,sizeof(file),TIME_CMP);
        for(int i=0;i<n;i++){
            printf("%s %s%17d %s\n",L[i].date,L[i].clock,L[i].bit,L[i].name);
        }
        printf("\n");
    }
    return 0;
}
int NAME_CMP(const void*a,const void*b)
{
    typedef struct
    {
        char date[11];
        char clock[6];
        int bit;
        char name[127];
    } file;
    file *pa,*pb;
    pa = (file *)a;
    pb = (file *)b;
    return strcmp(pa->name,pb->name);
}
int SIZE_CMP(const void*a,const void*b)
{
    typedef struct
    {
        char date[11];
        char clock[6];
        int bit;
        char name[127];
    } file;
    file *pa,*pb;
    pa = (file *)a;
    pb = (file *)b;
    if(pa->bit == pb->bit) return pa->bit - pb->bit;
    else return strcmp(pa->name,pb->name);
}
int TIME_CMP(const void*a,const void*b)
{
    typedef struct
    {
        char date[11];
        char clock[6];
        int bit;
        char name[127];
    } file;
    file *pa,*pb;
    pa = (file *)a;
    pb = (file *)b;
    if(!strcmp(pa->date,pb->date)){
        if(!strcmp(pa->clock,pb->clock)) return strcmp(pa->name,pb->name);
        else return strcmp(pa->name,pb->name);
    }
    else return strcmp(pa->date,pb->date);

}
/*
5
2011-01-26 07:32              388 ScoreStat.c
2011-01-26 19:48              429 ScoreStat.cpp
2011-01-25 20:11            22016 成绩统计.doc
2011-01-26 19:48           307200 ScoreStat++.exe
2011-01-25 20:08           270336 ScoreStat.exe
LIST /SIZE
*/
