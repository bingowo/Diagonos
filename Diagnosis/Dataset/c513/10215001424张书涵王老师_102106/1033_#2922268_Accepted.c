#include <stdio.h>
#include <stdlib.h>

struct Maya
{
    int year;
    int month;
    int day;
    char s[1000];
};

int cmp(const void*a,const void*b)
{
    struct Maya*ap=(struct Maya*)a;
    struct Maya*bp=(struct Maya*)b;
    if(ap->year!=bp->year)
        return (ap->year-bp->year);
    else
    {
        if(ap->month!=bp->month)
            return (ap->month-bp->month);
        else
            return (ap->day-bp->day);
    }
}

int main()
{
    int T;
    scanf("%d ",&T);
    int i;
    for(i=0;i<T;i++)
    {
        int N;
        scanf("%d ",&N);//N个日期
        int j,k;
        struct Maya a[10000];
        for(j=0;j<N;j++)
        {
            gets(a[j].s);
            a[j].day=0;
            for(k=0;a[j].s[k]!='.';k++)
                a[j].day=a[j].day*10+a[j].s[k]-48;
            k=k+2;
            if(a[j].s[k]=='p')
                {
                    if(a[j].s[k+1]=='o')
                    {
                        a[j].month=1;
                        k=k+4;
                    }
                    else
                    {
                        a[j].month=16;
                        k=k+4;
                    }
                }
            else
                {
                    if(a[j].s[k]=='n')
                    {
                        a[j].month=2;
                        k=k+3;
                    }
                    else
                    {
                        if(a[j].s[k]=='z')
                        {
                            if(a[j].s[k+1]=='i')
                            {
                                a[j].month=3;k=k+4;
                            }
                            else
                            {
                                if(a[j].s[k+1]=='o')
                                {
                                    a[j].month=4;k=k+5;
                                }
                                else
                                {
                                    a[j].month=11;k=k+4;
                                }
                            }
                        }
                        else
                        {
                            if(a[j].s[k]=='t')
                            {
                                a[j].month=5;k=k+5;
                            }
                            else
                            {
                                if(a[j].s[k]=='x')
                                {
                                    a[j].month=6;k=k+4;
                                }
                                else
                                {
                                    if(a[j].s[k]=='y')
                                    {
                                        if(a[j].s[k+1]=='o')
                                        {
                                            a[j].month=7;k=k+7;
                                        }
                                        else
                                        {
                                            a[j].month=10;k=k+4;
                                        }
                                    }
                                    else
                                    {
                                        if(a[j].s[k]=='m')
                                        {
                                            if(a[j].s[k+1]=='o')
                                            {
                                                a[j].month=8;k=k+4;
                                            }
                                            else
                                            {
                                                if(a[j].s[k+1]=='a')
                                                {
                                                    a[j].month=13;k=k+4;
                                                }
                                                else
                                                {
                                                    a[j].month=15;k=k+5;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if(a[j].s[k]=='c')
                                            {
                                                if(a[j].s[k+1]=='h')
                                                {
                                                    a[j].month=9;k=k+5;
                                                }
                                                else
                                                {
                                                    if(a[j].s[k+1]=='e')
                                                    {
                                                        a[j].month=12;k=k+4;
                                                    }
                                                    else
                                                    {
                                                        a[j].month=18;k=k+6;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if(a[j].s[k]=='k')
                                                {
                                                    if(a[j].s[k+1]=='a')
                                                    {
                                                        a[j].month=14;k=k+7;
                                                    }
                                                    else
                                                    {
                                                        a[j].month=17;k=k+6;
                                                    }
                                                }
                                                else
                                                {
                                                    a[j].month=19;k=k+6;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                a[j].year=0;
                for(;a[j].s[k];k++)
                    a[j].year=a[j].year*10+a[j].s[k]-'0';
            }
            qsort(a,N,sizeof(struct Maya),cmp);
            printf("case #%d:\n",i);
            for(j=0;j<N;j++)
                puts(a[j].s);
        }
}
