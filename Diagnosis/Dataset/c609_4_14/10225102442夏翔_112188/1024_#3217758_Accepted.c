#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char date[11];
    char time[6];
    int size;
    char name[64];
}DOC;
int cmp_name(const void *a, const void *b){
    DOC x1=*(DOC*)a, x2=*(DOC*)b;
    return strcmp(x1.name,x2.name);
}
int cmp_size(const void *a, const void *b){
    DOC x1=*(DOC*)a, x2=*(DOC*)b;
    if(x1.size!=x2.size) return x1.size-x2.size;
    return strcmp(x1.name,x2.name);
}
int cmp_time(const void *a, const void *b){
    DOC x1=*(DOC*)a, x2=*(DOC*)b;
    if(strcmp(x1.date,x2.date)!=0) return strcmp(x1.date,x2.date);
    else if(strcmp(x1.time,x2.time)!=0)return  strcmp(x1.time,x2.time);
    return strcmp(x1.name,x2.name);
}
int main(){
    int n;
    DOC *docs;
    char list[6];
    scanf("%d", &n);
    while(n!=0){
        docs = (DOC*)malloc(sizeof(DOC)*n);
        for(int i=0; i<n; i++)
            scanf("%s%s%d%s", docs[i].date, docs[i].time, &docs[i].size, docs[i].name);
        scanf("%s", list); //把list读走
        scanf("%s", list);
        if(strcmp(list,"/NAME")==0)
            qsort(docs,n,sizeof(docs[0]),cmp_name);
        else if(strcmp(list,"/SIZE")==0)
            qsort(docs,n,sizeof(docs[0]),cmp_size);
        else 
            qsort(docs,n,sizeof(docs[0]),cmp_time);
        for(int i=0; i<n; i++)
            printf("%s %s %16d %s\n", docs[i].date, docs[i].time, docs[i].size, docs[i].name);
        printf("%c", '\n');
        free(docs);
        scanf("%d", &n);
    }
}

