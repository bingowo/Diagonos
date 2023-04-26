#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* MONTH[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

struct T{
    int day;
    int month;
    int year;
};

int getmonth(char* s[])
{
    char *p;
    for(int i=0;i<19;i++)
    {
        p=*(MONTH+i);
        if(strcmp(s,p)==0)
        {
            return i;
        }
    }
    return -1;
}

int cmp(const void* a,const void* b)
{
    struct T* p1=(struct T*)a;
    struct T* p2=(struct T*)b;
    if(p1->year>p2->year)
    {
        return 1;
    }
    else if(p1->year<p2->year)
    {
        return -1;
    }
    else{
        if(p1->month>p2->month)
        {
            return 1;
        }
        else if(p1->month<p2->month)
        {
            return -1;
        }
        else{
            return p1->day-p2->day;
        }

    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        struct T data[N];
        for(int j=0;j<N;j++)
        {
            scanf("%d",&data[j].day);
            getchar();
            getchar();
            char *s[7];
            scanf("%s",s);
            data[j].month=getmonth(s);
            scanf("%d",&data[j].year);
        }
        qsort(data,N,sizeof(data[0]),cmp);
        for(int j=0;j<N;j++)
        {
            printf("%d. %s %d\n",data[j].day,MONTH[data[j].month],data[j].year);
        }
    }

}
