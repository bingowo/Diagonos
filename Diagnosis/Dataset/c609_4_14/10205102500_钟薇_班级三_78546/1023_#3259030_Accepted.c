#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义结构体类型
typedef struct {
    int val; //表示日期“大小”的值
    int y; //年
    int d; //日
    char m[6]; //玛雅历的月份
} RECORD;

//月份转数字
int month2idx(char* m) 
{ 
    int i;
    //1-19月份数组，为静态字符串数组
    char* month[] =
    {
        "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
        "yax","zac","ceh","mac","kankin","muan","pax","koyab",
        "cumhu","uayet"
    };
    //顺序比较月份字符串，相同则返回编号i
    for (i=0;;i++) if (!strcmp(m,month[i])) return i; 
}

//定义比较函数
int cmp(const void* a,const void* b)
{ return ((RECORD*)a)->val - ((RECORD*)b)->val; }

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        RECORD a[10000];

        //计算日期大小        
        int i;
        for (i=0;i<N;i++) 
        {
            //输入日月年
            scanf("%d.%s %d\n", &a[i].d, &a[i].m, &a[i].y);
            //若日的权值为1，则月的权值>=20，年的权值>=19*月的权值，这样保证年、月、日的优先级加权和得到日期大小
            a[i].val = a[i].y*1000+month2idx(a[i].m)*20+a[i].d;
        }
        qsort(a,N,sizeof(a[0]),cmp);

        //输出
        for (i=0;i<N;i++)
            printf("%d. %s %d\n",a[i].d,a[i].m,a[i].y);
    }
    return 0;
}