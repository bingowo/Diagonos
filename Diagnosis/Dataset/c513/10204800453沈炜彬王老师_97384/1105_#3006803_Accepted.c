#include <stdio.h>

int
main()
{
    int w,h;
    int temp[8];
    int val=0;
    int ans;
    int bpl[101][101];
    
    scanf("%d%d",&w,&h);
    for (int i=0 ; i<h; i++)
    {
        for (int j=0; j<w; j++)
        {
            scanf("%d",&bpl[i][j]);
        }
    }


    for (int i=1; i < h-1; i++)
    {
        for (int j=1; j < w-1; j++)
        {
            val = 0;
            temp[0] = bpl[i-1][j-1]>=bpl[i][j]?1:0;
            temp[1] = bpl[i-1][j]>=bpl[i][j]?1:0;
            temp[2] = bpl[i-1][j+1]>=bpl[i][j]?1:0;
            temp[3] = bpl[i][j+1]>=bpl[i][j]?1:0;
            temp[4] = bpl[i+1][j+1]>=bpl[i][j]?1:0;
            temp[5] = bpl[i+1][j]>=bpl[i][j]?1:0;
            temp[6] = bpl[i+1][j-1]>=bpl[i][j]?1:0;
            temp[7] = bpl[i][j-1]>=bpl[i][j]?1:0;
            
            for (int k=0; k<8; k++)
            {
                val *= 2;
                val += temp[k];
            }
            ans = val;
            for (int k=0; k<7; k++)
            {
                val *= 2;
                if (val > 255)
                {
                    val -= 255;
                }
                ans = ans<val?ans:val;
            }
            printf("%d ",ans);
        }
        printf("\n");
    }
    
    return 0;
}