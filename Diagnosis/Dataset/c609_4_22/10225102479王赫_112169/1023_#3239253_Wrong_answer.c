#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Maya{
int year;
char day[5];
int mon[15];
int val;
}may;
int cmp(const void*_a,const void*_b)
{
    may* a=(may*)_a;
    may* b=(may*)_b;
    if((a->year)!=(b->year)) return ((a->year)-(b->year));
    else if((a->val)!=(b->val)) return((a->val)-(b->val));
    else return ((atof(a->day))>(atof(b->day))?1:-1);
}
char s[20][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumbu","uayet"};
int main()
{
    int T,n;
    scanf("%d",&T);
    may a[10000];
    for(int i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%s",a[j].day);
            scanf("%s",a[j].mon);
            scanf("%d",&a[j].year);
            for(int k=0;k<19;k++)
            {
                if(strcmp(a[j].mon,s[k])==0)
                {
                    a[j].val=k;break;
                }
            }

        }
        qsort(a,n,sizeof(may),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            printf("%s %s %d\n",a[j].day,a[j].mon,a[j].year);
        }
    }
    return 0;
}
