#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int image[100][100]={0};
    int W=0,H=0;
    int row,col;
    int min_val = 255;
    int d,i;
    int b[8]={0};
    int thres = Image[row][col];
    scanf("%d%d",W,H);
    for(row=1;row<H-1;row++)
    {
        for(col=1;col<W-1;col++)
        {
            min_val=255;
            b[0] = Image[row-1][col-1]>=thres?1:0;
            b[1] = Image[row-1][col]>=thres?1:0;
            b[2] = Image[row-1][col+1]>=thres?1:0;
            b[3] = Image[row][col+1]>=thres?1:0;
            b[4] = Image[row+1][col+1]>=thres?1:0;
            b[5] = Image[row+1][col]>=thres?1:0;
            b[6] = Image[row+1][col-1]>=thres?1:0;
            b[7] = Image[row][col-1]>=thres?1:0;
            for(shift = 0;shift<=7;shift++) //左移shift
            {
                d = 0;
                for(i=0;i<8;i++)
                    d = d*2+b[(i+shift)%8];
                if(d<min_val)
                    min_val = d;
            }
            if(col==W-2)
                printf("%d",min_val);
            else
                printf("%d ",min_val);
        }
        printf("\n");
    }
    return 0;
}