#include <stdio.h>
#include <stdlib.h>


typedef struct{
int row;
int col;
int len;
int wid;
int n;
}pon;
int main()
{

    int t;
    scanf("%d",&t);
    for(int i =0;i<t;i++)
    {
        pon po;
        memset(&po,0,sizeof(po));
        int k,n,r,c;
        int mid[20][20];
        memset(mid,0,sizeof(mid));
        int p1,p2;
        scanf("%d%d%d%d",&r,&c,&n,&k);
        for(int i1 =0;i1 < n;i1++)
        {
            scanf("%d%d",&p1,&p2);
            mid[p1-1][p2-1]=1;
        }
        n=0;
        for(po.col = 0;po.col<c;po.col++)
        {
            for(po.row = 0;po.row<r;po.row++)
            {

                for(po.len = 1;po.len<=c-po.col;po.len++)
                {   po.n =0 ;
                    for(po.wid = 1;po.wid <= r-po.row;po.wid++)
                    {
                        for(int q=po.col;q<po.col+po.len;q++)
                        {if(mid[po.row+po.wid-1][q])po.n++;}
                        if((po.n)>=k)n++;
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%d%c",n,(i==t-1)?0:'\n');
    }

    return 0;
}
