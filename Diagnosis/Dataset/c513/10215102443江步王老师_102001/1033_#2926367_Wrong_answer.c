#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef struct Adate
{
    char d[50];
    int year;
    int month;
    int day;
}date;

char *m[19]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};

int cmp(const void *_a, const void *_b);
void read_data(date *a);
int main()
{
    int T,N;
    int i,j;
    scanf("%d",&T);
    for (i=0;i<T;i++)
    {
        scanf("%d",&N);
        date *a = (date *)malloc(sizeof(date)*N);
        for (j=0;j<N;j++)
        {
            gets(a[j].d);
            //printf("%s",a[j].d);
            //getchar();
            read_data(&a[j]);//将当前日期的信息读入a[j]

        }
        
        qsort(a,N,sizeof(date),cmp);
        
        printf("case #%d:\n",i);
        for (j=0;j<N;j++)
        {
            printf("%s\n",a[j].d);
        }
        free(a);
    }
    return 0;
}

void read_data(date *a)
{
    char *p=(*a).d;
    while (*p)
    {
        int i=0;
        int num=0;
        char s[50];
        while (isdigit(*p))
        {
            num=num*10+*p-'0';
            p++;
        }
        if (*p =='.'){
            (*a).day=num;
            num=0;
        }

        while (!isalpha(*p))
        {
            p++;
        }

        while (isalpha(*p))
        {
            s[i++]=*p;
            p++;
        }
        s[i]='\0';

        for (i=0;i<19;i++){
            if (strcmp(m[i],s) == 0)
            {
                (*a).month=i;
            }
        }

        while (!isdigit(*p))
        {
            p++;
        }

        while (isdigit(*p) && (*p)!='\0')
        {
            num=num*10+(*p)-'0';
            p++;
        }

        (*a).year=num;
        
    }
    return;
}

int cmp(const void *_a, const void *_b)
{
    date *a = (date *)_a;
    date *b = (date *)_b;
    if ((*b).year < (*a).year)
    {
        return 1;
    }
    else if ((*b).year == (*a).year && (*b).month < (*a).month)
    {
        return 1;
    }
    else if ((*b).year == (*a).year && (*b).month == (*a).month && (*b).day < (*a).day)
    {
        return 1;
    }
    return -1;
}