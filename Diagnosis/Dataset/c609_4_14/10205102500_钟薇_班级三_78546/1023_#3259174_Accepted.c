#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int val;    //日期换算数字，比较方便
    int d;
    int y;
    char m[6];
}RECORD;

/*
    定义结构体变量：
    typedef struct{
        ……
    }RENAME;
*/

int trans(char *m)
{
    int i;
    char *month[19]=
    {
        "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
        "yax","zac","ceh","mac","kankin","muan","pax","koyab",
        "cumhu","uayet"
    };
    for(i=0;i<19;i++)   
        if(!strcmp(m,month[i]))     return i;   
    /*
        strcmp函数：比较两个字符串大小，一个字符一个字符比较，按照ASCII码
        s1>s2，返回大于0
        s1=s2，返回0
        s1<s2，返回小于0
    */
}

int cmp(const void *a, const void *b)
{
    return ((RECORD*)a)->val - ((RECORD*)b)->val;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        RECORD day[10000];
        for(int j=0;j<N;j++)
        {
            scanf("%d. %s %d",&day[j].d,&day[j].m,&day[j].y);
            int num=trans(day[j].m);
            day[j].val=500*day[j].y+20*num+day[j].d;    //将日期转换为数字
        }
        qsort(day,N,sizeof(day[0]),cmp);

        printf("case #%d:\n",i);
        for(int j=0;j<N;j++)
            printf("%d. %s %d\n",day[j].d,day[j].m,day[j].y);
    }
    return 0;
}