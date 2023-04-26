#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int val;//日期
    int y;//年
    int d;//日
    char m[7];//玛雅历的月
}RECORD;

int month2idx(char* m){ //将玛雅历的月份转为数字
    int i;
    //静态字符串数组
    static char* month[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(i=0;;i++) if(!strcmp(m,month[i])) return i;
}

int cmp(const void *a,const void *b){
    return ((RECORD*)a)->val-((RECORD*)b)->val;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&n);
        RECORD a[n];
        for(int k=0;k<n;k++){
            scanf("%d.%s %d\n",&a[k].d,a[k].m,&a[k].y);
            a[k].val=a[k].y*1000+month2idx(a[k].m)*20+a[k].d;//加权
        }
        qsort(a,n,sizeof(RECORD),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<n;k++){
            printf("%d. %s %d\n",a[k].d,a[k].m,a[k].y);
        }
    }
    return 0;
}
