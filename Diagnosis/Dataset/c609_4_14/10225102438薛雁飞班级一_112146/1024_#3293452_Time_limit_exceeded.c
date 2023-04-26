#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char date[20];
    char time[10];
    long long int size;
    char name[65];
}file;
int cmpn(const void* a,const void* b)
{
    file f1,f2;
    f1=*((file*)a);f2=*((file*)b);
    return strcmp(f1.name,f2.name);
}
int cmpt(const void* a,const void* b)
{
    file f1,f2;
    f1=*((file*)a);f2=*((file*)b);
    if(strcmp(f1.date,f2.date)==0){
        if(strcmp(f1.time,f2.time)==0)
            return strcmp(f1.name,f2.name);
        else return(strcmp(f1.time,f2.time));
    }
    else return(strcmp(f1.time,f2.time));
}
int cmps(const void* a,const void* b)
{
    file f1,f2;
    f1=*((file*)a);f2=*((file*)b);
    if(f1.size==f2.size)return strcmp(f1.name,f2.name);
    else return(f1.size-f2.size);
}
int main()
{
    int n;
    do{
        scanf("%d",&n);
        file *a;
        char order[5];
        a=(file*)malloc(n*sizeof(file));
        for(int i=0;i<n;i++){
            scanf("%s %s %d %s",a[i].date,a[i].time,&a[i].size,a[i].name);
        }
        scanf("LIST /%s",order);
        if(order[0]=='N')qsort(a,n,sizeof(a[0]),cmpn);
        else if(order[0]=='S')qsort(a,n,sizeof(a[0]),cmps);
        else qsort(a,n,sizeof(a[0]),cmpt);
        for(int i=0;i<n;i++){
            printf("%s %s %d %s",a[i].date,a[i].time,a[i].size,a[i].name);
            printf("\n");
        }
            
    }while(n);
    return 0;
}
