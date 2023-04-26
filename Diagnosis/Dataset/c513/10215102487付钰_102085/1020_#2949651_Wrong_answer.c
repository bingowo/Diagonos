#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
    int size;
    char name[64];
    char date[20];
    char time[20];
}file;
int cmpname(const void *a,const void *b)
{
    file *p1=(file*)a;
    file *p2=(file*)b;
    return strcmp(p1->name,p2->name);
}
int cmpsize(const void *a,const void *b)
{
    file *p1=(file*)a;
    file *p2=(file*)b;
    if(p1->size!=p2->size) return p1->size-p2->size;
    else return strcmp(p1->name,p2->name);
}

int cmptime(const void *a,const void *b)
{
    file *p1=(file*)a;
    file *p2=(file*)b;
    if(p1->time != p2->time) return strcmp(p1->time,p2->time);
    else return strcmp(p1->name,p2->name);
}

int main()
{

    int n;
    scanf("%d",&n);
    while(n){
        file a[n];
        for(int i=0;i<n;i++){
            scanf("%s %s %d %s",a[i].date,a[i].time,&a[i].size,a[i].name);

        }
        char s[5],l[5];
        scanf("%s /%s",l,s);
        if(strcmp(s,"NAME")==0){
            qsort(a,n,sizeof(a[0]),cmpname);
        }
        if(strcmp(s,"SIZE")==0){
            qsort(a,n,sizeof(a[0]),cmpsize);
        }
        if(strcmp(s,"TIME")==0){
            qsort(a,n,sizeof(a[0]),cmptime);
        }
        for(int j=0;j<n;j++){
            printf("%s %s %16d %s",a[j].date,a[j].time,a[j].size,a[j].name);
            if(j!=n-1) printf("\n");
        }
        scanf("%d",&n);
        printf("\n");
    }

}
