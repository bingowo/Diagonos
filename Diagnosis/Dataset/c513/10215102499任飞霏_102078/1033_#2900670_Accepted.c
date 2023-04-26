#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int val; //日期总大小
    int y; //年
    int d; //日
    char m[7]; //玛雅月份
}record;

record a[10001];

int month2idx(char* m)
{
    static char* month[] = {"pop","no","zip","zotz","tzec",
                            "xul","yoxkin","mol","chen","yax",
                            "zac","ceh","mac","kankin","muan",
                            "pax","koyab","cumhu","uayet"};
    for(int i = 0;;i++)
        if(!strcmp(m,month[i]))return i;
}

int cmp(const void* a,const void* b)
{
    return((record*)a)->val-((record*)b)->val;
}

int main()
{
    int T;
    scanf("%d",&T);
    int j;
    for(j = 0;j < T;j++){
        int N;
        scanf("%d",&N);
        for(int i = 0;i < N;i++){
            scanf("%d.%s %d",&a[i].d,a[i].m,&a[i].y);
            a[i].val = a[i].y*1000 + month2idx(a[i].m)*20+a[i].d;
        }
        qsort(a,N,sizeof(record),cmp);
        printf("case #%d:\n",j);
        for(int i = 0;i < N;i++)
            printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
    }
    return 0;
}
