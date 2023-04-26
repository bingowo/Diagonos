#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int win;
    int lose;
    int num;
    int sc;
}Gm;

int cmp(const void*a,const void*b)
{
    Gm*a1=(Gm*)a;
    Gm*b1=(Gm*)b;
    if(a1->sc!=b1->sc) return b1->sc-a1->sc;
    else
    {
        if(a1->win!=b1->win) return b1->win-a1->win;
        else if(a1->lose!=b1->lose) return a1->lose-b1->lose;
        else return a1->num-b1->num;
    }
}

int main()
{
    int m,n;
    int a,b,c;
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(m==0&&n==0) break;
        else
        {
            Gm gm[m];
            for(int i=0;i<m;++i)
            {
                gm[i].win=0;
                gm[i].lose=0;
                gm[i].num=i+1;
                gm[i].sc=0;
            }
            for(int i=0;i<n;++i)
            {
                scanf("%d%d%d",&a,&b,&c);
                if(c==1)
                {
                    gm[a-1].sc+=3;
                    gm[b-1].sc--;
                    gm[a-1].win++;
                    gm[b-1].lose++;
                }
                else if(c==-1)
                {
                    gm[a-1].sc--;
                    gm[b-1].sc+=3;
                    gm[a-1].lose++;
                    gm[b-1].win++;
                }
                else
                {
                    gm[a-1].sc++;
                    gm[b-1].sc++;
                }
            }
            qsort(gm,m,sizeof(gm[0]),cmp);
            int j=0;
            for(;j<m-1;++j)
            {
                printf("%d ",gm[j].num);
            }
            printf("%d\n",gm[j].num);
        }
    }
    return 0;
}
