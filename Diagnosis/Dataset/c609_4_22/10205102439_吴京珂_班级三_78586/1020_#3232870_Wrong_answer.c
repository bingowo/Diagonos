#include <stdio.h>
#include <stdlib.h>

typedef struct RECORD
{
    int x;
    char m[31];
} node;

int cmp(const void* a,const void* b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    return p1.x - p2.x;
}

int main()
{
    node s[100];
    int i=0;
    while(scanf("%s",s[i].m)!=EOF)
    {
        i++;
        int len,flag = 0;
        len = strlen(s[i].m);

        for (int j=0; j<len; j++)
            if (s[i].m[j]>='0'&&s[i].m[j]<='9')
            {
                s[i].x=10*s[i].x+s[i].m[j]-48;
                flag=1;
            }
        if (flag==0) s[i].x=-1;

    }
    qsort(s,i,sizeof(s[0]),cmp);

    for (int j=0; j<i-1; j++)
    {
        printf("%s ",s[j].m);
    }
    printf("%s\n", s[i-1].m);
    return 0;
}
