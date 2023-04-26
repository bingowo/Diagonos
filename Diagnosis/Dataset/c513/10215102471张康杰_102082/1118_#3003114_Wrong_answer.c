#include <stdio.h>
#include <stdlib.h>

int main()
{
    int W,H,D,ch;
    int degree;
    scanf("%d %d %d %c",&W,&H,&D,&ch);
    degree = (D / 90) % 4;
    if(ch == 'L')
        degree = 4 - degree;
    int ar[H][W],i,j;
    for(i = 0;i < H;i++)
    {
        for(j = 0;j < W;j++)
        {
            scanf("%d",&ar[i][j]);
        }
    }    
    switch(degree)
    {
        case 0:
            printf("%d %d\n",W,H);
            for(i = 0;i < H;i++)
            {
                for(j = 0;j < W;j++)
                    printf("%d%c",ar[i][j],(j == W - 1)?'\n':' ');
            }
            break;
        case 1:
            printf("%d %d\n",H,W);
            for(j = 0;j < W;j++)
            {
                for(i = H - 1;i >= 0;i--)
                    printf("%d%c",ar[i][j],(i == H - 1)?'\n':' ');
            }
            break;
        case 2:
            printf("%d %d\n",W,H);
            for(i = H - 1;i >= 0;i--)
            {
                for(j = W - 1;j >= 0;j--)
                    printf("%d%c",ar[i][j],(j == 0)?'\n':' ');
            }
            break;
        case 3:
            printf("%d %d\n",H,W);
            for(j = W - 1;j >= 0;j--)
            {
                for(i = 0;i < H;i++)
                    printf("%d%c",ar[i][j],(i == H - 1)?'\n':' ');
            }
            break;
        case 4:
            printf("%d %d\n",W,H);
            for(i = 0;i < H;i++)
            {
                for(j = 0;j < W;j++)
                    printf("%d%c",ar[i][j],(j == W - 1)?'\n':' ');
            }
            break;

    }
    return 0;
}