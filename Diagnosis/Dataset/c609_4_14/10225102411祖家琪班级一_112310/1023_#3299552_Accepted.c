#include <stdio.h>
#include <stdlib.h>

int moth2val(char *s)
{
    char *table[19] = {"pop","no","zip","zotz","tzec","xul","yoxkin"
    ,"mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for(int i=0;i<19;i++){
        if(strcmp(table[i],s) == 0) return i;
    }
}
int cmp(const void *a,const void *b)
{
    typedef struct
    {
        int val;
        int day;
        char moth[9];
        int year;
    } date;
    date *pa,*pb;
    pa = (date *) a;
    pb = (date *) b;
    return pa->val-pb->val;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        typedef struct
        {
            int val;//该日期的权重
            int day;
            char moth[9];
            int year;
        } date;
        scanf("%d",&N);
        date L[10000];
        for(int j=0;j<N;j++){
            scanf("%d.%s%d",&L[j].day,L[j].moth,&L[j].year);
            L[j].val = L[j].day+moth2val(L[j].moth)*20+L[j].year*19*20;
        }
        qsort(L,N,sizeof(date),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<N;j++){
            printf("%d. %s %d\n",L[j].day,L[j].moth,L[j].year);
        }

    }
    return 0;
}
