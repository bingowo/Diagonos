#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char dem[20];
typedef struct 
{
    char date[20];
    char time[10];
    int size;
    char name[20];
}file;
int cmp(const void *a,const void *b){
    file x=*(file*)a;
    file y=*(file*)b;
    if(strcmp("LIST /NAME",dem)==0)return strcmp(x.name,y.name);
    if(strcmp("LIST /TIME",dem)==0){
        if(strcmp(x.time,y.time)==0&&strcmp(x.date,y.date)==0)return strcmp(x.name,y.name);
        if(strcmp(x.date,y.date)==0)return strcmp(x.time,y.time);
        return strcmp(x.date,y.date);
    }
    if(strcmp("LIST /SIZE",dem)==0){
        if(x.size==y.size)return strcmp(x.name,y.name);
    }
    return 0;
}
int main(){
    int n;char t[20];
    while(scanf("%d\n",&n)==1&&n!=0){
        file *a=(file*)malloc(sizeof(file)*n);
        for(int i=0;i<n;i++){
            scanf("%s %s %16d %s\n",&a[i].date,&a[i].time,&a[i].size,&a[i].name);
        }
        scanf("%s",t);
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++){
            printf("%s %s%16d %s\n",a[i].date,a[i].time,a[i].size,a[i].name);
        }
        printf("\n");
    }
}