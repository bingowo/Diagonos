#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//maya历
char* m[]=
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};


//定义日期结构体
typedef struct date
{
    int day;
    char month[7];
    int year;
}Date;

//月份对应函数
int monthToid(char* month)
{
    for(int i=0;;i++)
        if(!strcmp(month,m[i]))return i;//返回月份编号i
}

//比较函数
int cmp(const void *_a,const void *_b)
{
    Date a=*(Date *)_a;
    Date b=*(Date *)_b;
    if(a.year!=b.year)
        return a.year>b.year?1:-1;
    else if(monthToid(a.month)!=monthToid(b.month))
        return monthToid(a.month)>monthToid(b.month)?1:-1;
    else
        return a.day>b.day?1:-1;
}

//主函数
int main()
{
    int T;
    scanf("%d",&T);
    for(int Case=0;Case<T;Case++)
    {
        int N;
        scanf("%d",&N);
        Date DATE[N];
        for(int j=0;j<N;j++)
            scanf("%d.%s %d",&DATE[j].day,DATE[j].month,&DATE[j].year);
        qsort(DATE,N,sizeof(Date),cmp);
        printf("case #%d:\n",Case);
        for(int i=0;i<N;i++)
            printf("%d. %s %d\n",DATE[i].day,DATE[i].month,DATE[i].year);
    }
    return 0;
}
