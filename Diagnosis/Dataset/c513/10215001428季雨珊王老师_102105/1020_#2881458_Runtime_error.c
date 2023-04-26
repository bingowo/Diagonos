#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
struct file{
    char date[11];
    char time[6];
    int size;
    char name[100];
}*a;

int timecmp(const void *a,const void *b){
    struct file *xx=(struct file *)a;
    struct file *yy=(struct file *)b;
    if((xx->date)!=(yy->date))
        return (strcmp(xx->date,yy->date)>0?1:-1);
    else return(strcmp(xx->time,yy->time)>0?1:-1);
}
int namecmp(const void *a,const void *b){
    struct file *xx=(struct file *)a;
    struct file *yy=(struct file *)b;
    return (strcmp(xx->name,yy->name)>0?1:-1);
}
int sizecmp(const void *a,const void *b){
    return (*(int *)a-*(int *)b);
}

int main(){
    int n;
    do{
        scanf("%d",&n);
        a=(struct file*)malloc(sizeof(struct file)*n);
        for(int i=0;i<n;i++){
            scanf("%s",a[i].date);
            scanf("%s",a[i].time);
            scanf("%d",&a[i].size);
            scanf("%s",a[i].name);
        }
        char list[5];
        scanf("%s",list);
        if(strcmp(list,"NAME")==0){
            qsort(a,n,sizeof(a[0]),namecmp);
        }
        else if(strcmp(list,"SIZE")==0){
            qsort(a,n,sizeof(a[0]),sizecmp);
        }
        else if(strcmp(list,"TIME")==0){
            qsort(a,n,sizeof(a[0]),timecmp);
        }
        for(int i=0;i<n;i++){
            printf("%s %s %16d %s",a[i].date,a[i].time,a[i].size,a[i].name);
            printf("\n");
        }
        printf("\n");
    }while(n);
    return 0;
}
