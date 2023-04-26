#include <stdio.h>
#include <stdlib.h>

int main()
{
    int W,H,D;
    char c;
    scanf("%d %d %d %c",&W,&H,&D,&c);
    int s[500][500];
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
            scanf("%d",&s[i][j]);
    }
    int d=D%360;
    if(d==0)
    {
        printf("%d %d\n",W,H);
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
                printf("%d ",s[i][j]);
            printf("\n");
        }
    }
    else if(d==90)
    {
        if(c=='R')
        {
            printf("%d %d\n",H,W);
            for(int i=0;i<W;i++)
            {
                for(int j=H-1;j>=0;j--)
                    printf("%d ",s[j][i]);
                printf("\n");
            }
        }
        else if(c=='L')
        {
            printf("%d %d\n",H,W);
            for(int i=W-1;i>=0;i--)
            {
                for(int j=0;j<H;j++)
                    printf("%d ",s[j][i]);
                printf("\n");
            }
        }
    }
    else if(d==180)
    {
        printf("%d %d\n",W,H);
        for(int i=H-1;i>=0;i--)
        {
            for(int j=W-1;j>=0;j--)
                printf("%d ",s[i][j]);
            printf("\n");
        }
    }
    else
    {
        if(c=='L')
        {
            printf("%d %d\n",H,W);
            for(int i=0;i<W;i++)
            {
                for(int j=H-1;j>=0;j--)
                    printf("%d ",s[j][i]);
                printf("\n");
            }
        }
        else if(c=='R')
        {
            printf("%d %d\n",H,W);
            for(int i=W-1;i>=0;i--)
            {
                for(int j=0;j<H;j++)
                    printf("%d ",s[j][i]);
                printf("\n");
            }
        }
    }
}
