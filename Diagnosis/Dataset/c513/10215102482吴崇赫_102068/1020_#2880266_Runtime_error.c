#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 105

typedef struct{
    char time1[15];
    char time2[10];
    char name[65];
    int size;
}file;

int cmp_n(const void* a,const void* b)
{
    file* fa=(file*)a; file* fb=(file*)b;
    return strcmp(fa->name,fb->name);
}

int cmp_t(const void* a,const void* b)
{
    file* fa=(file*)a; file* fb=(file*)b;
    if(strcmp(fa->time1,fb->time1)!=0)return strcmp(fa->time1,fb->time1);
    else if(strcmp(fa->time2,fb->time2)!=0)return strcmp(fa->time2,fb->time2);
    else return strcmp(fa->name,fb->name);
}

int cmp_s(const void* a,const void* b)
{
    file* fa=(file*)a; file* fb=(file*)b;
    if(fa->size!=fb->size)return fa->size>fb->size?1:-1;
    else return strcmp(fa->name,fb->name);
}

int main()
{
    while(1){
        int file_num;
        scanf("%d\n",&file_num);
        if(!file_num)break;
        file f[N];char test[15];
        /*for(int i=0;i<N;++i){
            f[i].name[65]={'\0'};
            f[i].time1[15]={'\0'};
            f[i].size=0;
            f[i].time2[10]={'\0'};
        }*/
        for(int i=0;i<file_num;++i){
            scanf("%s%s%d%s",f[i].time1,f[i].time2,&f[i].size,f[i].name);
        }
        gets(test);
        if(strcmp(test,"LIST /NAME")==0)qsort(f,file_num,sizeof(f[0]),cmp_n);
        else if(strcmp(test,"LIST /SIZE")==0)qsort(f,file_num,sizeof(f[0]),cmp_s);
        else qsort(f,file_num,sizeof(f[0]),cmp_t);
        for(int k=0;k<file_num;++k){
            printf("%s %s %16d %s",f[k].time1,f[k].time2,f[k].size,f[k].name);
            if(k<file_num-1)printf("\n");
        }
    }
    return 0;
}

