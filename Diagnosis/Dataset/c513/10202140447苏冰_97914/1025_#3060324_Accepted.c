#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct SSS
{
    char str[25];
    int num;
}sss;
int cmp(const void*_a,const void*_b)
{
    sss* a=(sss*)_a;
    sss* b=(sss*)_b;
    if(a->num != b->num)
    {
        return b->num - a->num;
    }
    else return strcmp(a->str,b->str);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        int n;
        scanf("%d",&n);
        sss s[n];
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i].str);
            char x[25];
            strcpy(x,s[i].str);
            int a[30]={0};
            for(int j=0;j<strlen(x);j++)
            {
                a[x[j]-'A']=1;
            }
            int cnt=0;
            for(int j=0;j<30;j++)
            {
                if(a[j]==1) cnt++;
            }
            s[i].num=cnt;
        }
        qsort(s,n,sizeof(sss),cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<n;i++)
        {
            printf("%s\n",s[i].str);
        }
    }
    return 0;
}
