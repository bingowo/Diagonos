#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int idx;
    int cnt;
    int s,f;
}node;
int cmp(const void *a,const void *b)
{
    node s1=*(node*)a;
    node s2=*(node*)b;
    if(s1.cnt!=s2.cnt)
        return s2.cnt-s1.cnt;
    else
    {
        if(s1.s!=s2.s)
            return s2.s-s1.s;
        else
        {
            if(s1.f!=s2.f)
                return s1.f-s2.f;
            else
                return s1.idx-s2.idx;
        }
    }
}
int main()
{
    int m,n;
    while(scanf("%d %d",&m,&n))
    {
        if(m==0&&n==0)
            break;
        node p[m];
        int a,b;
        int c;
        for(int i=1;i<=m;i++)
        {
            p[i-1].idx=i;
            p[i-1].cnt=0;
            p[i-1].s=0;
            p[i-1].f=0;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                p[a-1].cnt+=3;
                p[b-1].cnt-=1;
                p[a-1].s++;
                p[b-1].f++;
            }
            else if(c==-1)
            {
                p[b-1].cnt+=3;
                p[a-1].cnt-=1;
                p[b-1].s++;
                p[a-1].f++;
            }
            else if(c==0)
            {
                p[a-1].cnt+=1;
                p[b-1].cnt+=1;
            }
        }
        qsort(p,m,sizeof(p[0]),cmp);
        for(int i=0;i<m;i++)
            printf("%d ",p[i].idx);
        printf("\n");
    }
    return 0;
}
