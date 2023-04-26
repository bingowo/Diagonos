#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpName(const void * a, const void * b);
int cmpSize(const void * a, const void * b);
int cmpTime(const void * a, const void * b);

struct Data{
    char day[20];
    char time[10];
    int store;
    unsigned char name[70];

};

int main()
{
    int n;
    scanf("%d",&n);
    while(n != 0){
        struct Data d[100];
        for(int i = 0; i < n; i++){
            scanf("%s %s %d %s",d[i].day,d[i].time,&d[i].store,d[i].name);
        }
        char a[15];
        getchar();
        gets(a);
        if(strcmp(a,"LIST /NAME") == 0){
           qsort(d,n,sizeof(d[0]),cmpName);
        }else if(strcmp(a,"LIST /SIZE") == 0){
            qsort(d,n,sizeof(d[0]),cmpSize);
        }else if(strcmp(a,"LIST /TIME") == 0){
            qsort(d,n,sizeof(d[0]),cmpTime);
        }
        for(int i = 0; i < n; i++){
            printf("%s %s %16d %s\n",d[i].day,d[i].time,d[i].store,d[i].name);
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}


int cmpName(const void * a, const void * b){
    struct Data d1;
    struct Data d2;
    d1 = (*(struct Data *)a);
    d2 = (*(struct Data *)b);
    return strcmp(d1.name,d2.name);
}


int cmpSize(const void * a, const void * b){
    struct Data d1;
    struct Data d2;
    d1 = (*(struct Data *)a);
    d2 = (*(struct Data *)b);
    if(strcmp(d1.name,d2.name)){
        return strcmp(d1.name,d2.name);
    }else{
        return strcmp(d1.name,d2.name);
}
    }


int cmpTime(const void * a, const void * b){
    struct Data d1;
    struct Data d2;
    d1 = (*(struct Data *)a);
    d2 = (*(struct Data *)b);
    if(strcmp(d1.day,d2.day) != 0){
        return strcmp(d1.day,d2.day);
    }else if(strcmp(d1.time,d2.time) != 0){
        return strcmp(d1.time,d2.time);
    }else{
        return strcmp(d1.name,d2.name);
    }
}
