#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct RECORD{
    int val;
    int y;
    int d;
    char m[7];
};
int month2idx(char* m);

int cmp(const void*a,const void *b){
    return ((struct RECORD*)a)->val - ((struct RECORD*)b)->val;
}

int main()
{
    int T;
    scanf("%d", &T);
    int cnt = 0;
    while (cnt<T){
        int N;
        scanf("%d", &N);
        struct RECORD a[100];
        for(int i = 0;i < N;i++){
            a[i].val = 0;
            //输入日月年
            scanf("%d. %s %d\n",&a[i].d,a[i].m,&a[i].y);
            //若日的权值为1，则月的权值>=20，年的权值>=19*月的权值
            a[i].val = (a[i].y)*1000 + (month2idx(a[i].m))*20 + a[i].d;
        }
        qsort(a,N,sizeof(a[0].val),cmp);
        printf("case #%d\n",cnt);
        for(int i = 0;i < N;i++){
            printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
        }
        cnt++;
    }  
}
int month2idx(char* m){
    int i;//1-19月份数组，为静态字符串数组
    static char*month[] = {
        "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
        "yax","zac","ceh","mac","kankin","muan","pax","koyab",
        "cumhu","uayet"};
        for(int i = 0;i<18;i++){
            if(!strcmp(m,month[i])) return i;
        }
}