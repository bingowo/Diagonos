#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct
{
    char str[27];int cnt;
}alph;

int cmp(const void*a,const void*b)
{
    alph c=*(alph*)a;
    alph d=*(alph*)b;
    if(c.cnt!=d.cnt) return d.cnt-c.cnt;
    else return strcmp(c.str,d.str);
}

int main()
{
    int T,n,i,j,k;
    int p[128];
    alph s[107];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        scanf("%d",&n);
        for(j=0;j<n;j++) s[j].cnt=0;
        for(j=0;j<n;j++)
        {
            scanf("%s",s[j]);
            memset(p,-1,sizeof(p));
            int l=strlen(s[j].str);
            for(k=0;k<l;k++)
            {
                int val=s[j].str[k];
                if(p[val]==-1)
                {
                    s[j].cnt++;
                    p[val]=0;
                }
            }
        }
        qsort(s,n,sizeof(s[0]),cmp);
        for(j=0;j<n;j++)
            printf("%s\n",s[j].str);
    }
    return 0;
}
