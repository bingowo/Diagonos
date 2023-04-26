#include <stdio.h>
#include <stdlib.h>
struct game{
    int w,f,score,number;
};

struct game g[11];
int cmp(const void *a,const void *b)
{
    struct game *a1 = (struct game*)a,*b1 = (struct game*)b;
    if(a1->score != b1->score)
        return b1->score - a1->score;
    else
    {
        if(a1->w != b1->w)
            return b1->w - a1->w;
        else
        {
            if(a1->f != b1->f)
                return a1->f - b1->f;
        }
    }
    return a1->number - b1->number;
}
int main()
{

    int n,m;
    scanf("%d%d",&n,&m);
    while(n != 0 || m!=0)
    {
        int a,b,c;
        for(int k=0;k<11;k++)
        {
            g[k].number=k+1;
            g[k].score=0;
            g[k].f=0;
            g[k].w=0;
        }
        for(int i=0;i<m;i++)
        {

            scanf("%d%d%d",&a,&b,&c);
            if(c == 1)
            {
                g[a-1].score += 3;
                g[a-1].w += 1;
                g[b-1].score -= 1;
                g[b-1].f += 1;
            }
            else if(c == -1)
            {
                g[b-1].score += 3;
                g[b-1].w += 1;
                g[a-1].score -= 1;
                g[a-1].f += 1;
            }
            else
            {
                g[a-1].score += 1;
                g[b-1].score += 1;
            }
        }
        qsort(g,n,sizeof (g[0]),cmp);
        for(int j=0;j <n;j++)
            printf("%d%c",g[j].number,(j == n-1)?'\n':' ');
        scanf("%d%d",&n,&m);
    }
    return 0;
}
