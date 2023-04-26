#include <stdio.h>
int func(int* L)
{
    int res=0;
    int temp[8];
    for(int k=0;k<8;k++)
    {
        for(int i=k;i<k+8;i++)
        {
            res=res*2+L[i];
        }
        temp[k]=res;
        res=0;
        L[k+8]=L[k];
    }
    int min=temp[0];
    for(int i=0;i<8;i++)
    {
        min=min<temp[i]?min:temp[i];
    }
    return min;
}
int main()
{
    int x=0,y=0;
    scanf("%d %d",&x,&y);
    int L[100][100];
    int RES[98][98];
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            scanf("%d",&L[i][j]);
        }
    }
    for(int i=1;i<x-1;i++)
    {
        for(int j=1;j<y-1;j++)
        {
            int NL[16];
            NL[0]=L[i-1][j-1]>=L[i][j]?1:0;
            NL[1]=L[i-1][j]>=L[i][j]?1:0;
            NL[2]=L[i-1][j+1]>=L[i][j]?1:0;
            NL[3]=L[i][j+1]>=L[i][j]?1:0;
            NL[4]=L[i+1][j+1]>=L[i][j]?1:0;
            NL[5]=L[i+1][j]>=L[i][j]?1:0;
            NL[6]=L[i+1][j-1]>=L[i][j]?1:0;
            NL[7]=L[i][j-1]>=L[i][j]?1:0;
            RES[i-1][j-1]= func(NL);
        }
    }
    for(int i=0;i<x-2;i++)
    {
        for(int j=0;j<y-2;j++)
        {
            printf("%d%c",RES[i][j],j==y-3?'\n':' ');
        }
    }
    return 0;
}