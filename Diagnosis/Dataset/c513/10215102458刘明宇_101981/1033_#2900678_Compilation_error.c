#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int val;
    int y;
    int d;
    char m[7];
}RECORD;

int cmp(const void*a,const void *b){
    return ((RECORD*)a)->val - ((RECORD*)b)->val;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T-- > 0){
        int N;
        scanf("%d", &N);
    }
    for(int i = 0;i < N;i++){
        //输入日月年
        scanf("%d. %s %d\n",&a[i].d,a[i].m,&a[i].y);
        //若日的权值为1，则月的权值>=20，年的权值>=19*月的权值
        a[i].val = a[i].y*1000 + month2idx(a[i].m)*20 + a[i].d;
    }
    qsort(a,N,sizeof(RECORD),cmp);
    for(int i = 0;i < N;i++){
        printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
    }
}

int month2idx(char* m){
    int i;//1-19月份数组，为静态字符串数组
    static char*month[] = {
        "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
        "yax","zac","ceh","mac","kankin","muan","pax","koyab",
        "cumhu","uayet"};
        for(int i = 0;;i++){
            if(!strcmp(m,month[i])) return i;
        }
    }
}