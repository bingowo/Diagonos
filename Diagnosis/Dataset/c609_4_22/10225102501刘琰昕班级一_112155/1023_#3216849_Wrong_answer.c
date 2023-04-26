#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//maya历
char m[19][7]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

//定义日期结构体
typedef struct date
{
    int day;
    char month[7];
    int year;
}Date;

//比较函数
int cmp(const void *_a,const void *_b)
{
    
}

//主函数
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        Date DATE[N];
        for(int j=0;j<N;j++)
            scanf("%d. %s %d",&DATE[j].day,DATE[j].month,&DATE[j].year);
        qsort(DATE,N,sizeof(DATE),cmp);
    }
    return 0;
}
