#include <stdio.h>
#include <stdlib.h>

typedef struct RECORD
{
    int a;
    int y;
    int d;
    char m[7];
}node;

int month(char* m)
{
    int i;
    static char* month[] =
    {
        "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"
    };
    for (i=0;i<20; i++) if (strcmp(m,month[i])==0) return i;
}

int cmp(const void* a,const void* b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    return p1.a - p2.a;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        node s[n];
        for (int j=0; j<n; j++)
        {
            scanf("%d. %s %d",&s[j].d,&s[j].m,&s[j].y);
            s[j].a=s[j].y*1000+month(s[j].m)*20+s[j].d;
        }
        qsort(s,n,sizeof(s[0]),cmp);

        for (int j=0; j<n; j++)
        {
            //printf("%d\n",s[j].a);
            printf("%d. %s %d\n",s[j].d,s[j].m,s[j].y);
        }

    }

    return 0;
}
