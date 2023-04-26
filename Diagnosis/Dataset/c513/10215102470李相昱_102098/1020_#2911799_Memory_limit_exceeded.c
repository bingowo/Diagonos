#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int year;
    char month[3];
    char day[3];
    char hour[3];
    char min[3];
    int size;
    char name[64];
}file;
int cmpname(const void *p1,const void *p2){
    file *a=(file *)p1;
    file *b=(file *)p2;
    return strcmp(a->name,b->name);
}
int cmpsize(const void *p1,const void *p2){
    file *a=(file *)p1;
    file *b=(file *)p2;
    if(a->size==b->size){
        return a->size-b->size;
    } else{
        return strcmp(a->name,b->name);
    }

}
int cmptime(const void *p1,const void *p2){
    file *a=(file *)p1;
    file *b=(file *)p2;
    if(a->year!=b->year){
        return a->year -b->year;
    }else if(atoi(a->month) != atoi(b->month)){
        return atoi(a->month) - atoi(b->month);
    }else if(atoi(a->day) != atoi(b->day)){
        return atoi(a->day) - atoi(b->day);
    }else if(atoi(a->hour) != atoi(b->hour)){
        return atoi(a->hour) - atoi(b->hour);
    }else if(atoi(a->min) != atoi(b->min)){
        return atoi(a->min) - atoi(b->min);
    }else return strcmp(a->name,b->name);
}
int main() {
    int n;
    char s[5];
    scanf("%d", &n);
    while (n!=0){
        file a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d-%s-%s %s:%s%d %s",&a[i].year,
                  a[i].month,a[i].day,a[i].hour,a[i].min,&a[i].size,a[i].name);
            
        }
        scanf("LIST /%s",s);
        if(s[0]=='N'){
            qsort(a,n, sizeof(a[0]),cmpname);
        }else if(s[0]=='S'){
            qsort(a,n, sizeof(a[0]),cmpsize);
        }else{
            qsort(a,n, sizeof(a[0]),cmptime);
        }
        for(int j=0;j<n;j++){
            printf("%d-%s-%s %s:%s %16d %s\n", a[j].year, a[j].month,
                   a[j].day, a[j].hour, a[j].min, a[j].size,a[j].name);
        }
        scanf("%d",&n);
        if(n!=0){
            printf("\n");
        }
    }
    return 0;
}
