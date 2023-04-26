#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct text{
    char date[15];
    char time[10];
    int size;
    char name[64];
}TEXT;
int cmpt(const void *a,const void *b){
    TEXT x=*(TEXT*)a;
    TEXT y=*(TEXT*)b;
    if(strcmp(x.date,y.date)!=0)return strcmp(x.date,y.date);
    else return strcmp(x.time,y.time);
}
int cmpn(const void *a,const void *b){
    TEXT x=*(TEXT*)a;
    TEXT y=*(TEXT*)b;
    return strcmp(x.name,y.name);
}
int cmps(const void *a,const void *b)
{
    TEXT *x=(TEXT*)a;
    TEXT *y=(TEXT*)b;
    return x->size>y->size?1:-1;
}

int main()
{
    int n;scanf("%d",&n);
    do{
        TEXT *a=NULL;
        a=(TEXT*)malloc(sizeof(TEXT)*n);
        for(int i=0;i<n;i++){
            scanf("%s",a[i].date);
            scanf("%s",a[i].time);
            scanf("%d",&a[i].size);
            scanf("%s",a[i].name);
            //printf("%s\n%s\n%d\n%s",a[i].date,a[i].time,a[i].size,a[i].name);
        }
        char order[20];
        scanf("%s",order);
        scanf("%s",order);
        if(order[1]=='T')qsort(a,n,sizeof(TEXT),cmpt);
        else if(order[1]=='N')qsort(a,n,sizeof(TEXT),cmpn);
        else if(order[1]=='S')qsort(a,n,sizeof(TEXT),cmps);
        for(int i=0;i<n;i++){
            printf("%s %s%16d %s\n",a[i].date,a[i].time,a[i].size,a[i].name);
        }
        printf("\n");
    }while(scanf("%d",&n)!=0);
    return 0;
}

