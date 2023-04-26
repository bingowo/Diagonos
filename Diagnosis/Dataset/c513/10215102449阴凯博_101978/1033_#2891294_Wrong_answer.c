#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[19][7]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab"
,"cumhu","uayet"};

typedef struct
{
    int day;
    char month[7];
    int year;
} DATE;


int find(char* s1)
{
    int n;
    for (n=0;n<19;n++)
    {
        if (strcmp(s1,s[n])==0)
            break;
    }
    return n;
}

int cmp(const void* a,const void* b)
{
    DATE* pa=(DATE*)a; DATE* pb=(DATE*)b;
    int m,n; m=find(pa->month); n=find(pb->month);
    if (pa->year>pb->year) return 1;
    if (pa->year<pb->year) return -1;
    if (pa->year==pb->year)
    {
        if (m>n) return 1;
        if (m<n) return -1;
        if (m==n)
        {
            return (pa->day>pb->day)?1:-1;
        }
    }

}



int main()
{
    int T,N;
    scanf("%d",&T);
    int j,k;
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&N);
        DATE* arr=(DATE*)malloc(N*sizeof(DATE));
        for (j=0;j<N;j++)
        {
            scanf("%d. %s %d",&arr[j].day,arr[j].month,&arr[j].year);
            printf("%d\n",find(arr[j].month));
        }
        qsort(arr,N,sizeof(DATE),cmp);
        for (j=0;j<N;j++)
            printf("%d. %s %d\n",arr[j].day,arr[j].month,arr[j].year);
        free(arr);


    }

    return 0;
}
