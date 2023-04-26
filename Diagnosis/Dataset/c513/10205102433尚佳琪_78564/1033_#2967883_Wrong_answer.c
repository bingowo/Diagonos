#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int m;
    int day;
    int year;
    int val;
}NODE;
int cmp(const void *a,const void *b)
{
    NODE s1=*(NODE*)a;
    NODE s2=*(NODE*)b;
    if(s1.year!=s2.year)
        return s1.year-s2.year;
    else if(s1.m!=s2.m)
        return s1.m-s2.m;
    else
        return s1.day-s2.day;
}
int main()
{
    int t;
    scanf("%d",&t);
    char maya[19][10]={"pop","no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac",
    "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
    /*static char* maya[] =
{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
*/
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        NODE a[n];
        char s1[10],s2[10];
        for(int i=0;i<n;i++)
        {
            scanf("%s %s %d",s1,s2,&a[i].year);
            for(int j=0;j<19;j++)
            {
                if(strcmp(s2,maya[j])==0)
                {
                    a[i].m=j;
                    break;
                }
            }
            a[i].day=s1[0]-'0';
            if(s1[1]!='.')
                a[i].day=a[i].day*10+s1[1];
        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int i=0;i<n;i++)
            printf("%d. %s %d\n",a[i].day,maya[a[i].m],a[i].year);
    }
    return 0;
}
