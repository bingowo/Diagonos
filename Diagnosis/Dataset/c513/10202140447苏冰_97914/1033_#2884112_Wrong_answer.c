#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct SSS
{
    int year;
    char day[25];
    char mon[15];
    int mondig;
}stu;
int cmp(const void*_a,const void*_b)
{
    stu* a=(stu*)_a;
    stu* b=(stu*)_b;
    if((a->year)!=(b->year)) return((a->year)-(b->year));
    else if((a->mondig)!=(b->mondig)) return ((a->mondig)-(b->mondig));
    else return (strcmp(a->day,b->day));
}
char x[20][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
int main()
{
    int T,n;
    scanf("%d",&T);
    stu s[10010];
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%s",s[j].day);
            scanf("%s",s[j].mon);
            scanf("%d",&s[j].year);
            for(int k=0;k<19;k++)
            {
                if(strcmp(s[j].mon,x[k])==0)
                {
                    s[j].mondig=k;break;
                }
            }
        }
        qsort(s,n,sizeof(stu),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            printf("%s %s %d\n",s[j].day,s[j].mon,s[j].year);
        }
    }
    return 0;
}
