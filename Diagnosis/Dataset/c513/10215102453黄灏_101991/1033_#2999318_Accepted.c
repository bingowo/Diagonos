#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int val;//表示日期大小的数值；
    int year;
    int day;
    char month[7];//玛雅月份的名称
}record;

record maya[10001];

int month2int(char* m){//将玛雅月份名称转化为数字
    static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;;i++){
        if(!strcmp(m,month[i])) return i;//返回月份编号
    }
}

int cmp(const void* a,const void* b){
    record *c,*d;
    c = (record*)a;
    d = (record*)b;
    return c->val - d->val ;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        for(int j=0;j<N;j++){
            scanf("%d.%s %d",&maya[j].day,maya[j].month,&maya[j].year);
            maya[j].val = maya[j].year*1000+ month2int(maya[j].month)*20+maya[j].day;
        }
        qsort(maya,N,sizeof(record),cmp);
        for(int j=0;j<N;j++){
            printf("%d. %s %d\n",maya[j].day,maya[j].month,maya[j].year);
        }
    }
    return 0;
}
