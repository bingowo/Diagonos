#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int year,month,day,hour,min;
    int size;
    char name[65];
    char s[101];
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
    if(f1.year-f2.year==0){
        if(f1.month-f2.month==0){
            if(f1.day-f2.day==0){
                if(f1.hour-f2.hour==0){
                    if(f1.min-f2.min==0)return(strcmp(f1.name,f2.name));
                    else return(f1.min-f2.min);
                }
                else return(f1.hour-f2.hour);
            }
            else return(f1.day-f2.day);
        }
        else return(f1.month-f2.month);
    }
    else return(f1.year-f2.year);
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
        getchar();
        for(int i=0;i<n;i++){
            gets(a[i].s);
            a[i].year=atoi(a[i].s);
            a[i].month=atoi(a[i].s+5);
            a[i].day=atoi(a[i].s+8);
            a[i].hour=atoi(a[i].s+11);
            a[i].min=atoi(a[i].s+14);
            a[i].size=atoi(a[i].s+20);
            strcpy(a[i].name,a[i].s+34);
        }
        scanf("LIST /%s",order);
        if(order[0]=='N')qsort(a,n,sizeof(a[0]),cmpn);
        else if(order[0]=='S')qsort(a,n,sizeof(a[0]),cmps);
        else qsort(a,n,sizeof(a[0]),cmpt);
        for(int i=0;i<n;i++){
            printf("%s",a[i].s);
            printf("\n");
        }
        free(a);
        printf("\n");
    }while(n);
    return 0;
}
