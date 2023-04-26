#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char date[11];
    char time[6];
    int size;
    char name[128];
}File;

int cmpName(const void *a,const void *b)
{
    File *m,*n;
    m=(File *)a;
    n=(File *)b;
    return strcmp(m->name,n->name);
}
int cmpSize(const void *a,const void *b)
{
    File *m,*n;
    m=(File *)a;
    n=(File *)b;
    if (m->size!=n->size) {
        return m->size-n->size;
    } else return strcmp(m->name,n->name);
}

int cmpTime(const void *a,const void *b)
{
    File *m,*n;
    m=(File *)a;
    n=(File *)b;
    if (strcmp(m->date,n->date)!=0) {
        return strcmp(m->date,n->date);
    }
    else if (strcmp(m->time,n->time)!=0){
        return strcmp(m->time,n->time);
    } else{
        return strcmp(m->name,n->name);
    }
}

int main(void)
{
    int n;
    scanf("%d",&n);
    while (n!=0){
        File files[n];
        char instruction[5],temp[5];
        for (int i = 0; i < n; ++i) {
            scanf("%s %s %d %s",files[i].date,files[i].time,&files[i].size,files[i].name);
        }
        scanf("%s %s",temp,instruction);
        if (strcmp(instruction,"/NAME")==0){
            qsort(files,n, sizeof(File),cmpName);
        } 
        else if(strcmp(instruction,"/SIZE")==0){
            qsort(files,n, sizeof(File),cmpSize);
        } 
        else if (strcmp(instruction,"/TIME")==0){
            qsort(files,n, sizeof(File),cmpTime);
        }
        for (int i = 0; i < n; ++i) {
            printf("%s %s %16d %s\n",files[i].date,files[i].time,files[i].size,files[i].name);
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}