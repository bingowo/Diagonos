#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char dem[20];
typedef struct 
{
    char date[30];
    char time[20];
    long int size;
    char name[30];
}file;
int cmp(const void *a,const void *b){
    file x=*(file*)a;
    file y=*(file*)b;
    if(strcmp("LIST /NAME",dem)==0)return strcmp(x.name,y.name);
    if(strcmp("LIST /TIME",dem)==0){
        if(strcmp(x.time,y.time)==0&&strcmp(x.date,y.date)==0)return strcmp(x.name,y.name);
        if(strcmp(x.date,y.date)==0)return strcmp(x.time,y.time);
        return strcmp(x.date,y.date);
    }
    if(strcmp("LIST /SIZE",dem)==0){
        if(x.size==y.size)return strcmp(x.name,y.name);
    }
    return 0;
}
int main(){
    int n;
    while(scanf("%d\n",&n)&&n!=0){
        file *a=(file*)malloc(sizeof(file)*n);
        for(int i=0;i<n;i++){
            char temp[20];char *p=temp;
            scanf("%s %s %16ld ",a[i].date,a[i].time,&a[i].size);
            char ch=getchar();
            while(ch!='\n'){
                *p=ch;p++;ch=getchar();
            }
            *p='\0';strcpy(a[i].name,temp);
        }
        gets(dem);
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++){
            printf("%s %s%16d %s\n",a[i].date,a[i].time,a[i].size,a[i].name);
        }
        printf("\n");
    }
}