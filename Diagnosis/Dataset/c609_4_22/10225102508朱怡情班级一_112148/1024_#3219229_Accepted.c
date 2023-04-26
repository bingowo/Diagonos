#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int flag;

typedef struct
{
    char date[11];
    char time[6];
    int size;
    char name[100];
}file;

int cmp(const void* a,const void* b)
{
    file x=*(file*)a;
    file y=*(file*)b;
    if(flag==1){
        return strcmp(x.name,y.name);
    }
    else if(flag==2){
        if(x.size!=y.size)return x.size-y.size;
        else return strcmp(x.name,y.name);
    }
    else{
        if(strcmp(x.date,y.date)!=0)return strcmp(x.date,y.date);
        else if(strcmp(x.time,y.time)!=0)return strcmp(x.time,y.time);
        else return strcmp(x.name,y.name);
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)){
        if(n==0)break;
        file a[109];
        for(int i=0;i<n;i++){
            scanf("%s%s%d%s",a[i].date,a[i].time,&a[i].size,a[i].name);
        }
        char s[6];
        scanf("%s",s);
        scanf("%s",s);
        if(s[1]=='N')flag=1;
        else if(s[1]=='S')flag=2;
        else flag=3;
        qsort(a,n,sizeof(file),cmp);
        for(int i=0;i<n;i++){
            printf("%s %s %16d %s\n",a[i].date,a[i].time,a[i].size,a[i].name);
        }
        printf("\n");
    }
    return 0;
}
