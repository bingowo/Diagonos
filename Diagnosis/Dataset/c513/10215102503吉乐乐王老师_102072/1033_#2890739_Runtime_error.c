#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char mouth[10];
    int year;
    int day;
    long int val;
}maya;
int trans(maya a){
    static char*m[]={"pop","no","zip","zota","tzec","xul","yoxkin","mol",
    "chen","yax","zac","ch","mac","kankin","muan",
    "pax","koyab","cumhu","uayet"};
    for(int i=0;;i++)
        if(strcmp(a.mouth,m[i])==0)
            return i;
}
int cmp(const void *a,const void*b){
    maya x=*(maya*)a;
    maya y=*(maya*)b;
    x.val=x.year*1000+trans(x)*20+x.day;
    y.val=y.year*1000+trans(y)*20+y.day;
    return x.val-y.val;
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
            printf("%d. %s %d\n",a[i].day,a[i].mouth,a[i].year);
        }
    }
}