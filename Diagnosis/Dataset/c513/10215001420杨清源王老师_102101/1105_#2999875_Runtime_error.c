#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int Image[100][100],a,b,col,row;
    scanf("%d %d",&a,&b);
    for(row=1; row<=b; row++)
    {
        for(col=1; col<=a; col++)
            scanf("%d ",&Image[row][col]);
    }
    for(row=2; row<b; row++)
    {
        for(col=2; col<a; col++)
        {
            int b[8]= {0};
            int thres=Image[row][col];
            b[0]=Image[row-1][col-1]>=thres?1:0;
            b[1]=Image[row-1][col]>=thres?1:0;
            b[2]=Image[row-1][col+1]>=thres?1:0;
            b[3]=Image[row][col+1]>=thres?1:0;
            b[4]=Image[row+1][col+1]>=thres?1:0;
            b[5]=Image[row+1][col]>=thres?1:0;
            b[6]=Image[row+1][col-1]>=thres?1:0;
            b[7]=Image[row][col-1]>=thres?1:0;
            int min_val=255;
            int d;
            for(int shift=0; shift<=7; shift++)
            {
                d=0;
                for(int k=0; k<8; k++)
                    d=d*2+b[(k+shift)%8];
                if(d<min_val)
                    min_val=d;
            }
            printf("%d ",min_val);
        }
        printf("\n");
    }
    return 0;
}
