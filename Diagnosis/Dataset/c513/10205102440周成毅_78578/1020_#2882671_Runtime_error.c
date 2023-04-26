#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct file {
    char date[11];
    char time[6];
    int size;
    char name[30];
} F;

int cmpTime(const void *a, const void *b) {
    F* x1;F* x2;
    x1=(F*)a;
    x2=(F*)b;
    if (strcmp(x1->date, x2->date) != 0)
        return strcmp(x1->date, x2->date);
    else if (strcmp(x1->time, x2->time) != 0)
        return strcmp(x1->time, x2->time);
    else
        return strcmp(x1->name, x2->name);
}

int cmpSize(const void *a, const void *b){
    F* x1;F* x2;
    x1=(F*)a;
    x2=(F*)b;
    if(x1->size!=x2->size){
        return x1->size-x2->size;
    } else{
        return strcmp(x1->name, x2->name);
    }
}

int cmpName(const void *a, const void *b){
    F* x1;F* x2;
    x1=(F*)a;
    x2=(F*)b;
    return strcmp(x1->name, x2->name);
}

F fileList[101];

int main() {
    int num = -1;
    char command[5];
    while (num) {
        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
            scanf("%s %s %d %s", fileList[i].date, fileList[i].time, &fileList[i].size, fileList[i].name);
        }
        scanf("%s", command);
        scanf("%s", command);
        if(command[1]=='N')
            qsort(fileList, num,sizeof(fileList),cmpName);
        else if(command[1]=='T')
            qsort(fileList, num,sizeof(fileList),cmpTime);
        else if(command[1]=='S')
            qsort(fileList, num,sizeof(fileList),cmpSize);
        for(int i=0;i<num;i++){
            printf("%s %s",fileList[i].date,fileList[i].time);
            printf("%17d ",fileList[i].size);
            printf("%s\n",fileList[i].name);
        }
        printf("\n");
    }
    return 0;
}
