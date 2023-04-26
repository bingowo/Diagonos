#include <stdio.h>

int main()
{
    int gra[300][300];
    int copy[300][300];
    int W,H,D,cnt,temp;
    char c;
    scanf("%d %d %d %c",&W,&H,&D,&c);
    if(c=='R')cnt=(D/90)%4;
    else cnt=4-((D/90)%4);
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
            scanf("%d",&gra[i][j]);
    }
    int cnt1=0;
    while(cnt--)
    {
        int p=H-1,q=0,W1,H1;
        W1=W,H1=H;
        temp=W;
        W=H;
        H=temp;
        if(cnt1%2==0)
        {
            for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                copy[i][j]=gra[p][q];
                p--;
                if(p==-1){p=H1-1;q++;}
            }

        }
        }

        else
        {
            for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                gra[i][j]=copy[p][q];
                p--;
                if(p==-1){p=H1-1;q++;}
            }
        }
        }
        cnt1++;
    }
    printf("%d %d\n",W,H);
    if(cnt1%2==0)
    {
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W-1;j++)
                printf("%d ",gra[i][j]);
            printf("%d\n",gra[i][W-1]);
        }
    }
    else
    {
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W-1;j++)
                printf("%d ",copy[i][j]);
            printf("%d\n",copy[i][W-1]);
        }
    }

}

