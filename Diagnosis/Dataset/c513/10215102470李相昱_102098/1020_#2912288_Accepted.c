#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char date [11];
    char time[6];
    int size;
    char name[128];
}file;
int cmpname(const void *p1,const void *p2){
    file *a=(file *)p1;
    file *b=(file *)p2;
    return strcmp(a->name,b->name);
}
int cmpsize(const void *p1,const void *p2){
    file *a=(file *)p1;
    file *b=(file *)p2;
    if(a->size!=b->size){
        return a->size-b->size;
    } else{
        return strcmp(a->name,b->name);
    }

}
int cmptime(const void *p1,const void *p2){
    file *a=(file *)p1;
    file *b=(file *)p2;
    if(strcmp(a->date,b->date)!=0){
        return strcmp(a->date,b->date);
    } else if(strcmp(a->time,b->time)!=0){
        return strcmp(a->time,b->time);
    }else{
        return strcmp(a->name,b->name);
    }

}
int main() {
    int n;

    scanf("%d", &n);
    while (n!=0){
        file a[n];
        char s[5],L[5];
        for (int i = 0; i < n; i++) {
            scanf("%s %s %d %s",a[i].date,a[i].time,&a[i].size,a[i].name);

        }
        scanf("%s /%s",L,s);
        if(strcmp(s,"NAME")==0){
            qsort(a,n, sizeof(a[0]),cmpname);
        }else if(strcmp(s,"SIZE")==0){
            qsort(a,n, sizeof(a[0]),cmpsize);
        }else if(strcmp(s, "TIME") == 0){
            qsort(a,n, sizeof(a[0]),cmptime);
        }
        for(int j=0;j<n;j++){
            printf("%s %s %16d %s\n",a[j].date,a[j].time,a[j].size,a[j].name);
        }

        printf("\n");
        scanf("%d",&n);

    }
    return 0;
}
