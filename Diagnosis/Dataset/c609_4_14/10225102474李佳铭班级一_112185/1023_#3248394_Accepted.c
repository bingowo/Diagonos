#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char *cal[] = {"pop", "no", "zip", "zotz",
    "tzec", "xul", "yoxkin", "mol",
    "chen","yax", "zac", "ceh","mac","kankin",
     "muan","pax","koyab","cumhu","uayet"
};

typedef struct
{
    int day;
    char month[12];
    int year;
}time;

int number(char*a)
{
    int i = 0;
    for(i = 0; i < 19;i++)
    {
        if(strcmp(a,cal[i]) == 0)
            break;
    }
    return i;
}

int cmp(const void*a,const void*b)
{
    time A = *(time*)a;
    time B = *(time*)b;
    if(A.year != B.year)
    {
        return A.year > B.year;
    }
    else
    {
        if(strcmp(A.month,B.month) != 0)
        {
            return number(A.month) > number(B.month);
        }
        else
        {
            return A.day > B.day;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++)
    {
        int a;
        scanf("%d",&a);
        time* s = (time*)malloc(sizeof(time)*a);
        time* p = s;
        char c;
        c = getchar();
        for(int j = 0;j < a;j++)
        {
            p->day = 0;
            p->year = 0;
            while((c = getchar()) != '.')
            {
                p->day = p->day*10 + (c - '0');
            }
            c = getchar();
            int x = 0;
            while((c = getchar()) != ' ')
            {
               p->month[x++] = c;
            }
            p->month[x] = '\0';
            while((c = getchar()) != '\n')
            {
                p->year = p->year*10 + (c - '0');
            }
            p++;

        }
        qsort(s,a,sizeof(s[0]),cmp);
        p = s;
        printf("case #%d:\n",i);
        for(int j = 0;j < a;j++)
        {
            printf("%d. %s %d\n",p->day,p->month,p->year);
            p++;
        }
        free(s);

    }

}
