#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cnt;
    char s[21];
}data;

int num[26]={0};
int cmp(const void*a,const void *b)
{
    data x = *(data*) a;
    data y = *(data*) b;
    if(x.cnt!=y.cnt) return (x.cnt>y.cnt)?-1:1;
    else return strcmp(x.s,y.s);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0 ;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        data p[n];

        for (int j=0;j<n;j++)
        {
            scanf("%s",(p+j)->s);
            memset(num,0,sizeof(num));
            p[j].cnt=0;
            for (int k=0;k<strlen(p[j].s);k++)
            {
                char c = p[j].s[k];
                if(num[c-'A']==0)
                {
                    num[c-'A']++;
                    p[j].cnt++;
                }
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        for (int k=0;k<n;k++)
        {
            printf("%s\n",p[k].s);
        }
    }

    return 0;
}
