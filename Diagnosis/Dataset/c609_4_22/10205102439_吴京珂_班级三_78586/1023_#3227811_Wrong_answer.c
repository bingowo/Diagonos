#include <stdio.h>
#include <stdlib.h>

typedef struct RECORD
{
    int a;
    int y;
    int d;
    char m[7];
};

int month(char* m)
{
    int i;
    static char* month[] =
    {
        "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"
    };
    for (i=0; i<20; i++) if (strcmp(m,month[i])!=0) return i;
}

int cmp(const void* a11,const void* b11)
{
    struct RECORD *a1=(struct RECORD*)a11;
    struct RECORD *b1=(struct RECORD*)b11;
    return a1->a - b1->a;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        int n;
        scanf("%d",&n);
        struct RECORD s[n];
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
    printf("1//////\n");

    return 0;
}
