#include <stdio.h>
#include <stdlib.h>

struct data
{
    int day;
    char mon[100];
    int year;
};

int jdmon(char daymon[])
{
        int mid;
        if(daymon[0]=='p'&&daymon[1]=='o')  mid=0;
        if(daymon[0]=='n'&&daymon[1]=='o')  mid=1;
        if(daymon[0]=='z'&&daymon[1]=='i')  mid=2;
        if(daymon[0]=='z'&&daymon[1]=='o')  mid=3;
        if(daymon[0]=='t'&&daymon[1]=='z')  mid=4;
        if(daymon[0]=='x'&&daymon[1]=='u')  mid=5;
        if(daymon[0]=='y'&&daymon[1]=='o')  mid=6;
        if(daymon[0]=='m'&&daymon[1]=='o')  mid=7;
        if(daymon[0]=='c'&&daymon[1]=='h')  mid=8;
        if(daymon[0]=='y'&&daymon[1]=='a')  mid=9;
        if(daymon[0]=='z'&&daymon[1]=='a')  mid=10;
        if(daymon[0]=='c'&&daymon[1]=='e')  mid=11;
        if(daymon[0]=='m'&&daymon[1]=='a')  mid=12;
        if(daymon[0]=='k'&&daymon[1]=='a')  mid=13;
        if(daymon[0]=='m'&&daymon[1]=='u')  mid=14;
        if(daymon[0]=='p'&&daymon[1]=='a')  mid=15;
        if(daymon[0]=='k'&&daymon[1]=='o')  mid=16;
        if(daymon[0]=='c'&&daymon[1]=='u')  mid=17;
        if(daymon[0]=='u'&&daymon[1]=='a')  mid=18;
        return mid;
}

int cmp(const void* a,const void* b)
{
    struct data d1,d2;int t;
    d1=*((struct data*)a),d2=*((struct data*)b);
    if(d1.year!=d2.year) t=d1.year-d2.year;
    else t=jdmon(d1.mon)-jdmon(d2.mon);
    if(t==0) t=d1.day-d2.day;
    return t;
}

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        int n,j;
        scanf("%d",&n);
        struct data time[20000];
        for(j=0;j<n;j++)
        {
            scanf("%d",&time[j].day);
            getchar();
            scanf("%s",time[j].mon);
            scanf("%d",&time[j].year);
        }
        qsort(time,n,sizeof(time[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<n;j++)
            printf("%d. %s %d\n",time[j].day,time[j].mon,time[j].year);
    }
    return 0;
}
