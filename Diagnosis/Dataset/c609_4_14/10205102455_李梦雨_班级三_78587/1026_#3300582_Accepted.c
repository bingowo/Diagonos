#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[21];
    int type;
}str;

int cmp(const void *a,const void *b)
{
    str c=*(str*)a;
    str d=*(str*)b;
    if(c.type!=d.type)
        return d.type-c.type;
    else return strcmp(c.s,d.s);
}

int main()
{
    int t;
    scanf("%d\n",&t);
    for(int k=0;k<t;k++)
    {
        printf("case #%d:\n",k);
        int n;
        str a[101];
        scanf("%d\n",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",a[i].s);
            a[i].type=0;
            int dict[26]={0};
            for(int j=0;j<strlen(a[i].s);j++)
            {
                int m=a[i].s[j]-'A';
                if(dict[m]==0)
                {
                    dict[m]=1;
                    a[i].type++;
                }
            }
        }
        qsort(a,n,sizeof(a[0]),cmp);
        for(int i=0;i<n;i++)
            printf("%s\n",a[i].s);
    }
    return 0;
}