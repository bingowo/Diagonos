#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct an
{
    char res[16];
    long long num;
};

typedef struct an ans;

void solve(ans* p)
{
    int s[128];
    int cnt=0;
    for(int i=0;i<128;i++)
        s[i]=-1;
    int l=strlen(p->res);
    for(int i=0;i<l;i++)
    {
        if(s[p->res[i]]==-1)
        {
            if(cnt==0)
            {
                s[p->res[i]]=1;
                cnt++;
            }
            else if(cnt==1)
            {
                s[p->res[i]]=0;
                cnt++;
            }
            else
            {
                s[p->res[i]]=cnt;
                cnt++;
            }
        }
    }
    if(cnt==1)
        cnt=2;
    p->num=0;
    for(int i=0;i<l;i++)
    {
        p->num=p->num*cnt+s[p->res[i]];
    }
}

int cmp(const void* a,const void* b)
{
    ans m=*(ans*)a;
    ans n=*(ans*)b;
    if(m.num==n.num)
    {
        return strcmp(m.res,n.res);
    }
    else
    {
        if(m.num<n.num)
            return -1;
        else
            return 1;
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    ans hash[N];
    for(int i=0;i<N;i++)
    {
        scanf("%s",hash[i].res);
        solve(&hash[i]);
    }
    qsort(hash,N,sizeof(hash[0]),cmp);
    for(int i=0;i<N;i++)
    {
        printf("%s\n",hash[i].res);
    }
    return 0;
}
