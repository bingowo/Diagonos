#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    int day;
    char m[10];
    int month;
    int year;
}MAYA;

char mon[20][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
int cmp(const void* a, const void* b)
{
    MAYA a0=*(MAYA*)a,b0=*(MAYA*)b;
    if(a0.year==b0.year)
    {
        if(a0.month==b0.month)
        {
            return a0.day-b0.day;
        }
        return a0.month-b0.month;
    }
    return a0.year-b0.year;
}

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        int n,i;
        scanf("%d",&n);
        MAYA maya[n];
        for(i=0;i<n;i++)
        {
            scanf("%d. %s %d",&maya[i].day,&maya[i].m,&maya[i].year);
            int j;
            for(j=0;j<19;j++)
            {
                if(strcmp(maya[i].m,mon[j])==0)
                {
                    maya[i].month=j;
                    break;
                }
            }
        }
        qsort(maya,n,sizeof(maya[0]),cmp);

        printf("case #%d:\n",t);
        for(i=0;i<n;i++)
        {
            printf("%d. %s %d\n",maya[i].day,maya[i].m,maya[i].year);
        }
        t++;
    }
    return 0;
}