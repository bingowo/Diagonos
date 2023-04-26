#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct STU{
    unsigned char name[70];
    int store;
    char day[20];
    char time[10];
}stu;

int cmp_name(const void* a, const void* b){
    stu* c=(stu*)a;
    stu* d=(stu*)b;
    return (strcmp(c->name,d->name));
}

int cmp_size(const void* a, const void* b){
    stu* c=(stu*)a;
    stu* d=(stu*)b;
    if(c->store == d->store) return (strcmp(c->name,d->name));
    else return (c->store - d->store);
}

int cmp_time(const void* a,const void* b){
    stu* c=(stu*)a;
    stu* d=(stu*)b;
    if(strcmp(c->day,d->day) != 0) return strcmp(c->day,d->day);
    else{
        if(strcmp(c->time,d->time) != 0) return strcmp(c->time,d->time);
        else return (strcmp(c->name,d->name));
    }
}

int main() {
    int n;
    stu s[100];
    while (scanf("%d",&n) != EOF && n!=0){
        for(int i=0;i<n;i++){
            scanf("%s %s %d %s\n",s[i].day,s[i].time,&s[i].store,s[i].name);
        }
        char order[15];
        gets(order);
        if(strstr(order,"LIST /NAME") != NULL) qsort(s,n,sizeof(stu),cmp_name);
        else if(strstr(order,"LIST /SIZE") != NULL) qsort(s,n,sizeof(stu),cmp_size);
        else if(strstr(order,"LIST /TIME") != NULL) qsort(s,n,sizeof(stu),cmp_time);
        for(int i=0;i<n;i++){
            printf("%s %s %16d %s\n",s[i].day,s[i].time,s[i].store,s[i].name);
        }
        printf("\n");
    }
    return 0;
}
