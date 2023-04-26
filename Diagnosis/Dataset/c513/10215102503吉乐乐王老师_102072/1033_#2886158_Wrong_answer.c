#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char mouth[10];
    int year;
    int day;
}maya;
int isleap(int year){
    if(year%4==0&&year%400!=0)return 1;
    return 0;
}
int trans(maya a){
    if(strcmp(a.mouth,"uayet")==0){
        if(isleap(a.year))return 5;
        return 4;
    }
    return 19;
}
int cmp(const void *a,const void*b){
    maya x=*(maya*)a;
    maya y=*(maya *)b;
    if(x.year==y.year){
        if(x.mouth==y.mouth)return x.day>y.day?1:-1;
        return trans(x)>trans(y)?1:-1;
    }
    return x.year>y.year?1:-1;
}
int main(){
    int t;
    scanf("%d\n",&t);int idx=0;
    while(t--){
        int n;scanf("%d\n",&n);
        maya* a=(maya*)malloc(sizeof(maya)*n);
        for(int i=0;i<n;i++){
            scanf("%d. %s %d",&a[i].day,&a[i].mouth,&a[i].year);
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",idx++);
        for(int i=0;i<n;i++){
            printf("%d. %s%d\n",a[i].day,a[i].mouth,a[i].year);
        }
    }
}