#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num,win,fail,sum;
} FC;

int cmp(const void *a1,const void *b1)//比较函数
{
    FC a=*(FC*)a1;
    FC b=*(FC*)b1;
    if(a.sum!=b.sum) return b.sum-a.sum;
    else if(a.win!=b.win)return b.win-a.win;
    else if(a.fail!=b.fail)return a.fail-b.fail;
    else return a.num-b.num;

}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)//多组输入
    {
        if(n==0&&m==0) break;
        FC *p=(FC *)malloc(sizeof(FC)*n);
        for(int i=0; i<n; i++)
        {
            p[i].sum=0;
            p[i].win=0;
            p[i].fail=0;
            p[i].num=i+1;
        }

        for(int i=0; i<m; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            if(c==1)
            {
                p[a-1].sum+=3;
                p[b-1].sum-=1;
                p[a-1].win+=1;
                p[b-1].fail+=1;
            }
            else if(c==0)
            {
                p[a-1].sum+=1;
                p[b-1].sum+=1;

            }
            else
            {
                p[a-1].sum-=1;
                p[b-1].sum+=3;
                p[b-1].win+=1;
                p[a-1].fail+=1;
            }

        }

        qsort(p,n,sizeof(p[0]),cmp);
        for(int i=0; i<n-1; i++)
        {
            printf("%d ",p[i].num);
        }
        printf("%d\n",p[n-1].num);

    }
    return 0;
}



