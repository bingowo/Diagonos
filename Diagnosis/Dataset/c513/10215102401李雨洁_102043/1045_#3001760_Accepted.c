#include <stdio.h>
#include <stdlib.h>
#define N 100000

typedef struct
{
    char c;
    int cnt;
} PAIR;

int stat(char*s,PAIR*r)
{
    int rcnt=0,cnt=0; char prev;
    for (prev=*s++;*s;cnt++,prev=*s++)
    {
        if (*s!=prev)
        {
            r[rcnt].c = prev;
            r[rcnt++].cnt = cnt;
            cnt = 0;
        }
    }
    r[rcnt].c = prev;
    r[rcnt++].cnt = cnt;
    return rcnt;
}
int allSameLength_Char(PAIR (*f)[100],int n,int *fn)
{
    for(int i = 1; i < n; i++)
    {
        if(fn[i] != fn[0])
            return 0;
    }
    for(int i = 0; i < fn[0]; i++)
    {
         for(int j = 1; j < n; j++)
            if(f[j][i].c != f[0][i].c)
                return 0;
    }
    return 1;
}

int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n;
    scanf("%d",&n);
    PAIR f[N][100];
    int fn[N],a[N];
    char s[101];
    for(int i = 0; i < n; i++)
    {
        scanf("%s",s);
        fn[i] = stat((s,s),f[i]);
    }
    int d,ans = 0;
    if(allSameLength_Char(f,n,fn))
    {
        for(int i = 0; i < fn[0]; i++)
        {
            for(int j = 0; j < n; j++)
                a[j] = f[j][i].cnt;
            qsort(a,n,sizeof(a[0]),cmp);
            for(int j = 0; j < n; j++)
            {
                ans += abs(a[j]-a[n / 2]);
            }
        }
        printf("%d\n",ans);
    }
    else
        printf("-1\n");
    return 0;
}




