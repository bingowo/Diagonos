#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
}

int cmp(const void* a,const void* b)
{ return
((RECORD*)a)->val - ((RECORD*)b)->val; }
//排序：



int main()
{
    int t,i,N;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        struct stu {
        int val; //表示日期“大小”的值
        int y; //年
        int d; //日
        char m[7]; //玛雅历的月份
    } a[1000];
        scanf("%d",&N);
        printf("case #%d:\n",i);
    //在输入数据的同时计算日期的大小数值：
        for (i=0;i<N;i++)
        {

            scanf("%d.%s %d\n", &a[i].d, a[i].m, &a[i].y);
// 若日的权值为1，则月的权值>=20，年的权值
//>=19*月的权值，这样保证年、月、日的优先级
//加权和得到日期大小
            a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
        }
        qsort(a, N, sizeof(RECORD), cmp);
        for (i=0;i<N;i++)
        printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
    }
}
