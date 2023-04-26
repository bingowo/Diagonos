#include <stdio.h>
#include <stdlib.h>

typedef struct {
int val; //表示日期“大小”的值
int y; //年
int d; //日
char m[7]; //玛雅历的月份
} RECORD;

int month2idx(char* m)
{ int i;
//1-19月份数组，为静态字符串数组
static char* month[] =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
//顺序比较月份字符串，相同则返回编号i
for (i=0;;i++) if (!strcmp(m,month[i])) return i;

int main()
{
    int i;
    int a[100];
    int N=12;
    for (i=0;i<N;i++) {
//输入日月年
        scanf("%d.%s %d\n", &a[i].d, &a[i].m, &a[i].y);
// 若日的权值为1，则月的权值>=20，年的权值
//>=19*月的权值，这样保证年、月、日的优先级
//加权和得到日期大小
        a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
}
    int cmp(const void* a,const void* b)
{   return ((RECORD*)a)->val - ((RECORD*)b)->val; }
    qsort(a, N, sizeof(RECORD), cmp);
    for (i=0;i<N;i++)
        printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
        return 0;

}