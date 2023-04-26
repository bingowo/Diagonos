//sort\1033.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

//#define LOCAL
#define ARRLEN 10100
#define TRUE 1
#define FALSE 0
char montehlist[22][8]={"pop","no","zip",
"zotz", "tzec", "xul", "yoxkin", "mol",
"chen","yax","zac","ceh", "mac", "kankin",
 "muan", "pax", "koyab", "cumhu","uayet"};

int getmonth(char *s)
{
    int i=0;
    while(strcmp(s,montehlist[i]))
        ++i;
    return i;
}
struct mayacal{
    int year,month,day;
    long long val;
};
typedef struct mayacal maya;
maya arr[ARRLEN];
int cmp(maya*x,maya*y)
{
    return x->val-y->val;
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        int N;
        scanf("%d",&N);
        char t_month[10];
        for(int iN=0;iN<N;++iN){
            scanf("%d",&arr[iN].day);
            getchar();
            scanf("%s",t_month);
            arr[iN].month=getmonth(t_month);
            scanf("%d",&arr[iN].year);
            arr[iN].val=arr[iN].day+100*arr[iN].month+10000*arr[iN].year;
        }
        qsort(arr,N,sizeof(arr[0]),cmp);
        for(int iN=0;iN<N;++iN){
            printf("%d. %s %d\n",arr[iN].day,montehlist[arr[iN].month],arr[iN].year);
        }
    }
}
