#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Field{
    int date[3][10];
    int time[2][5];
    int size;
    char name[150];
}field;
int cmp_name(const void *a,const void *b);
int cmp_size(const void *a,const void *b);
int cmp_time(const void *a,const void *b);
int main()
{
    int T,j;
    char list[10],c[150],b;
    while(scanf("%d",&T)!=0&&T!=0){
        field a[T];
        for(j=0;j<T;j++){
            scanf("%d-%d-%d",&a[j].date[0],&a[j].date[1],&a[j].date[2]);
            getchar(); //处理空格
            scanf("%d：%d",&a[j].time[0],&a[j].time[1]);
            while(b=getchar()&&strcmp(b,' ')==0);
            scanf("%d",&a[j].size);
            getchar(); //处理空格
            scanf("%s",&a[j].name);
        }
        scanf("%s",&list);
        if(strcmp(list,"LIST /NAME")==0){
            qsort(a,T,sizeof(a[0]),cmp_name);
        }else if(strcmp(list,"LIST /SIZE")==0){
            qsort(a,T,sizeof(a[0]),cmp_size);
        }else if(strcmp(list,"LIST /TIME")==0){
            qsort(a,T,sizeof(a[0]),cmp_time);
        }
        for(j=0;j<T;j++){
            printf("%d-%d-%d ",a[j].date[0],a[j].date[1],a[j].date[2]);
            printf("%d：%d",a[j].time[0],a[j].time[1]);
            printf("%16d ",a[j].size);
            scanf("%s\n",a[j].name);
        }
        printf("\n");
    }
    return 0;
}

int cmp_name(const void *a,const void *b)
{
    field A = *(field *)a;
    field B = *(field *)b;
    return strcmp(A.name,B.name);
}
int cmp_size(const void *a,const void *b)
{
    field A = *(field *)a;
    field B = *(field *)b;
    return A.size-B.size;
}
int cmp_time(const void *a,const void *b)
{
    field A = *(field *)a;
    field B = *(field *)b;
    if(A.date[0]!=B.date[0]){
        return A.date[0]-B.date[0];
    }else if(A.date[1]!=B.date[1]){
        return A.date[1]-B.date[1];
    }else if(A.date[2]!=B.date[2]){
        return A.date[2]-B.date[2];
    }
}


