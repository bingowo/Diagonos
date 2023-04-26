#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char command[6];

typedef struct{
    char date[11];
    char time[6];
    int size;
    char name[80];
} File;

int cmp(const void* m, const void* n){
    File *a = (File*) m, *b = (File*) n;
    if(strcmp(command, "/SIZE") == 0){
        if(a->size != b->size) return a->size - b->size;
    }else if(strcmp(command, "/TIME") == 0){
        if(strcmp(a->date, b->date))
            return strcmp(a->date, b->date);
        else if(strcmp(a->time, b->time))
            return strcmp(a->time, b->time);
    }
    return strcmp(a->name, b->name);
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n != 0) {
        File f[100];
        for(int i=0; i<n; ++i)
            scanf("%s%s%d%s",f[i].date,f[i].time,&f[i].size,f[i].name);
        scanf("%s",command);  scanf("%s",command);
        qsort(f, n, sizeof(File), cmp);
        for(int i=0; i<n; ++i)
            printf("%s %s %16d %s\n",f[i].date,f[i].time,f[i].size,f[i].name);
        scanf("%d",&n);
        if(n) printf("\n");
    }
}
