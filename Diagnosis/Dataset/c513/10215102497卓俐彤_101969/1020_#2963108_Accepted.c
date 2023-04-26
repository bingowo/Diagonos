#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file{
    char data[11];
    char time[6];
    int size;
    char name[64];
};

int cmpName(const void*a,const void*b){
    struct file d1,d2;
    d1=*((struct file*)a);
    d2=*((struct file*)b);
    return strcmp(d1.name,d2.name);
}

int cmpSize(const void*a,const void*b){
    struct file d1,d2;
    d1=*((struct file*)a);
    d2=*((struct file*)b);
    if(d1.size==d2.size)return strcmp(d1.name,d2.name);
    else return d1.size-d2.size;
}

int cmpTime(const void*a,const void*b){
    struct file d1,d2;
    d1=*((struct file*)a);
    d2=*((struct file*)b);
    if(strcmp(d1.data,d2.data)==0){
        if(strcmp(d1.time,d2.time)==0){
            return strcmp(d1.name,d2.name);
        }
        else return strcmp(d1.time,d2.time);
    }
    else return strcmp(d1.data,d2.data);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T){
        struct file files[T];
        char list[5],opt[5];
        for(int t=0;t<T;t++)
            scanf("%s %s %d %s",files[t].data,files[t].time,
                  &files[t].size,files[t].name);
        scanf("%s %s",list,opt);
        if(strcmp(opt,"/NAME")==0){
            qsort(files, T, sizeof(files[0]), cmpName);
        }
        else if(strcmp(opt,"/SIZE")==0){
            qsort(files, T, sizeof(files[0]), cmpSize);
        }
        else if(strcmp(opt,"/TIME")==0){
            qsort(files, T, sizeof(files[0]), cmpTime);
        }
        for(int t=0;t<T;t++){
            printf("%s %s %16d %s\n",files[t].data,files[t].time,
                   files[t].size,files[t].name);
        }
        printf("\n");
        scanf("%d",&T);
    }
    return 0;
}
