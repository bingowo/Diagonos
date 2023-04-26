#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {char number[50]; int n; int sum = 0;} student;

int cmp(const void* a,const void* b)
{
    student* c = (student*)a; student* d = (student*)b;
    if (c->sum!=d->sum) return d->sum-c->sum;
    return strcmp(c->number,d->number);
}

main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int num, que, line;
        int t, pass = 0;
        student a[501];
        scanf("%d %d %d",&num,&que,&line);
        int value[11] = {};
        for (int j=0;j<que;j++) scanf("%d",&value[j]);
        for (int j=0;j<num;j++)
        {
            scanf("%s %d",a[j].number,&a[j].n);
            while (a[j].n--)
            {
                scanf("%d",&t);
                a[j].sum += value[t-1];
            }
            if (a[j].sum>=line) pass++;
        }
        qsort(a,num,sizeof(a[0]),cmp);
        printf("case #%d:\n%d\n",i,pass);
        for (int j=0;j<pass;j++) printf("%s %d\n",a[j].number,a[j].sum);
    }
    return 0;
}