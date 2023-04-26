#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {int day;char month[10];int year;} P;
int change(P *a1)
{
    char S[20][10]={"0","pop", "no","zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
    for (int i=1;i<20;i++)
    {
        if (strcmp(a1->month,S[i])==0) return i;
    }
}
int cmp(const void *a,const void *b)
{
    P *a1=(P*)a,*b1=(P*)b;
    if (a1->year!=b1->year) return a1->year-b1->year;
    else
    {
        if (change(a1)!=change(b1)) return change(a1)-change(b1);
        else return a1->day-b1->day;
    }
}
int main()
{
    int T;
    scanf ("%d",&T);
    for (int i=0;i<T;i++)
    {
        int N;
        scanf("%d",&N);
        P s[10001];
        for (int j=0;j<N;j++)
        {
            scanf("%d",&s[j].day);
            getchar();getchar();
            scanf("%s %d",s[j].month,&s[j].year);
        }
        qsort(s,N,sizeof(s[0]),cmp);
        printf ("case #%d:\n",i);
        for (int j=0;j<N;j++)
        {
            printf("%d. %s %d\n",s[j].day,s[j].month,s[j].year);
        }
    }
    return 0;
}
