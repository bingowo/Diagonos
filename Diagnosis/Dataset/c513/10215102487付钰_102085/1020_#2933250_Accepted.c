#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char date [11];
    char time[6];
    int size;
    char name[63];
}file;

int cmp1(const void *p1,const void *p2){
    file *a=(file *)p1;
    file *b=(file *)p2;
    return strcmp(a->name,b->name);
}
int cmp2(const void *p1,const void *p2){
    file *a=(file *)p1;
    file *b=(file *)p2;
    if(a->size!=b->size){
        return a->size-b->size;
    } else{
        return strcmp(a->name,b->name);
    }

}
int cmp3(const void *p1,const void *p2){
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
int main()
{
    int n;
    scanf("%d",&n);
    while (n){
    file a[n];
    char s[5],l[5];
    for(int i=0;i<n;i++){
        scanf("%s %s %d %s",a[i].date,a[i].time,&a[i].size,a[i].name);
    }
    scanf("%s /%s",l,s);
    if(strcmp(s,"NAME")==0){
        qsort(a,n,sizeof(a[0]),cmp1);
    }
    else if(strcmp(s,"SIZE")==0){
        qsort(a,n,sizeof(a[0]),cmp2);
    }
    else if(strcmp(s,"TIME")==0){
        qsort(a,n,sizeof(a[0]),cmp3);
    }
    int j=0;
    for(j=0;j<n ;j++){
        printf("%s %s %16d %s\n",a[j].date,a[j].time,a[j].size,a[j].name);
    }
    //printf("%s %s %16d %s",a[j].date,a[j].time,a[j].size,a[j].name);

    scanf("%d",&n);
    printf("\n");
    }
    return 0;
}

