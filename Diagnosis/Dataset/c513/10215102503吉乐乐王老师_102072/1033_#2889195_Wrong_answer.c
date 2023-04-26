#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char s[10];
    int t;
}mayaorder;
mayaorder m[20]={{"",0},
    {"pop",1},{"no",2},{"zip",3},{"zota",4},
    {"tzec",5},{"xul",6},{"yoxkin",7},{"mol",8},
    {"chen",9},{"yax",10},{"zac",11},{"ch",12},
    {"mac",13},{"kankin",14},{"muan",15},{"pax",16},
    {"koyab",17},{"cumhu",18},{"uayet",19}
};
typedef struct{
    char mouth[10];
    int year;
    int day;
}maya;
int trans(maya a){
    for(int i=1;i<20;i++){
        if(strcmp(a.mouth,m[i].s)==0){
            return m[i].t;
        }
    }
}
int cmp(const void *a,const void*b){
    maya x=*(maya*)a;
    maya y=*(maya *)b;
    if(x.year==y.year){
        if(strcmp(x.mouth,y.mouth)==0)return x.day>y.day?1:-1;
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
            printf("%d. %s %d\n",a[i].day,a[i].mouth,a[i].year);
        }
    }
}