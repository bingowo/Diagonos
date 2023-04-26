#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int Image[100][100],a,b,i,j;
    scanf("%d %d",&a,&b);
    for(i=1; i<=b; i++)
    {
        for(j=1; j<=a; j++)
            scanf("%d ",&Image[i][j]);
    }
    for(i=2; i<b; i++)
    {
        for(j=2; j<a; j++)
        {
            int b[8]= {0};
            int thres=Image[j][i];
            b[0]=Image[j-1][i-1]>=thres?1:0;
            b[1]=Image[j-1][i]>=thres?1:0;
            b[2]=Image[j-1][i+1]>=thres?1:0;
            b[3]=Image[j][i+1]>=thres?1:0;
            b[4]=Image[j+1][i+1]>=thres?1:0;
            b[5]=Image[j+1][i]>=thres?1:0;
            b[6]=Image[j+1][i-1]>=thres?1:0;
            b[7]=Image[j][i-1]>=thres?1:0;
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
