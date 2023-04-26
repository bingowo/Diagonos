#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char name[126];
    int size;
    char date[10];
    char time[5];
}FILES;


int cmpName(const void *a, const void *b){
    FILES *A = (FILES*)a ,*B= (FILES*)b;

    int i = 0;
    while(A->name && B->name){
        if(A->name[i] > B->name[i]) return 1;
        if(A->name[i] < B->name[i]) return -1;
        i++;
    }
    if(A->name) return 1;
    if(B->name) return -1;
    return 0;
}


int cmpSize(const void *a, const void *b){
    FILES *A = (FILES*)a ,*B= (FILES*)b;

    if(A->size > B->size) return 1;
    if(A->size < B->size) return -1;

    int i = 0;
    while(A->name && B->name){
        if(A->name[i] > B->name[i]) return 1;
        if(A->name[i] < B->name[i]) return -1;
        i++;
    }
    if(A->name) return 1;
    if(B->name) return -1;

    return 0;
}


int cmpTime(const void *a, const void *b){
    FILES *A = (FILES*)a ,*B= (FILES*)b;

    for(int i = 0; i < 10; i++){
        if(A->date[i] > B->date[i]) return 1;
        if(A->date[i] < B->date[i]) return -1;
    }

    for(int i = 0; i < 5; i++){
        if(A->time[i] > B->time[i]) return 1;
        if(A->time[i] < B->time[i]) return -1;
    }

    int i = 0;
    while(A->name && B->name){
        if(A->name[i] > B->name[i]) return 1;
        if(A->name[i] < B->name[i]) return -1;
        i++;
    }
    if(A->name) return 1;
    if(B->name) return -1;

    return 0;
}


int main()
{
    int n,flag = 0;
    while(scanf("%d",&n) && n != 0){

        char command[10];
        FILES * file = (FILES*)malloc(n*sizeof(FILES));
        for(int i = 0; i < n; i++){
            scanf("%10s %s %d %s",file[i].date,file[i].time,
                  &file[i].size,file[i].name);
        }
        scanf("%*s%s",command);


        FILES * p = file;
        switch(command[1]){
        case'N':
            qsort(p,n,sizeof(FILES),cmpName); break;
        case'S': ;
            qsort(p,n,sizeof(FILES),cmpSize); break;
        case'T': ;
            qsort(p,n,sizeof(FILES),cmpTime); break;}


        if(flag != 0) printf("\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
                printf("%c",file[i].date[j]);
            }
            printf(" %s %16d %s\n",file[i].time,file[i].size,
                   file[i].name);
        }


        free(file);
        flag = 1;
    }
    return 0;
}
