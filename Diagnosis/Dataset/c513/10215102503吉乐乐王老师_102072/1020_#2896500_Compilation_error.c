#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char dem[20];
typedef struct 
{
    char date[50];
    char time[50];
    int size;
    char name[128];
}file;
int cmp(const void *a,const void *b){
    file x=*(file*)a;
    file y=*(file*)b;
    if(strcmp("/NAME",dem)==0)return strcmp(x.name,y.name);
    if(strcmp("/TIME",dem)==0){
        if((strcmp(x.time,y.time)==0)&&(strcmp(x.date,y.date)==0))return strcmp(x.name,y.name);
        if(strcmp(x.date,y.date)==0)return strcmp(x.time,y.time);
        return strcmp(x.date,y.date);
    }
    if(strcmp("/SIZE",dem)==0){
        if(x.size==y.size)return strcmp(x.name,y.name);
        return x.size-y.size;
    }
}
int main(){
    int n;
    while(scanf("%d",&n)&&n!=0){
        file *a=(file*)malloc(sizeof(file)*n);
        for(int i=0;i<n;i++){
            scanf("%s%s%d%s",a[i].date,a[i].time,&a[i].size,a[i].name);
            getchar();
        }
        char temp[20];
        scanf("%s%s",,temp,dem);
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++){
            printf("%s %s %16d %s\n",a[i].date,a[i].time,a[i].size,a[i].name);
        }
        printf("\n");
    }
}