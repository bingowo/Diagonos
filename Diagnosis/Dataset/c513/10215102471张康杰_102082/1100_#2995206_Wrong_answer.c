#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char move[101];
    scanf("%s",&move);
    int T,i,len;
    len = strlen(move);
    int point[len + 1][2],move_x,move_y;
    point[0][0] = 0,point[0][1] = 0;
    for(i = 1;i < len + 1;i++)
    {
        if(move[i - 1] == 'L')
        {
            point[i][0] = point[i - 1][0] - 1;
            point[i][1] = point[i - 1][1];
            move_x--;
        }
        else if(move[i - 1] == 'R')
        {
            point[i][0] = point[i - 1][0] + 1;
            point[i][1] = point[i - 1][1];
            move_x++;
        }
        else if(move[i - 1] == 'U')
        {
            point[i][0] = point[i - 1][0];
            point[i][1] = point[i - 1][1] + 1;
            move_y++;
        }
        else if(move[i - 1] == 'D')
        {
            point[i][0] = point[i - 1][0];
            point[i][1] = point[i - 1][1] - 1;
            move_y--;
        }
    }
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int a,b,j,flag = 0;
        scanf("%d %d",&a,&b);
        for(j = 0;j < len + 1;j++)
        {
            if(point[j][0] == a && point[j][1] == b)
            {
                flag = 1;
                break;
            }
        }
        for(j = 0;j < len + 1;j++)
        {
            int remain_x,remain_y;
            if(move_x != 0)
                remain_x = (a - point[j][0]) % move_x;
            else
                remain_x = a;
            if(move_y != 0)
                remain_y = (b - point[j][1]) % move_y;
            else
                remain_y = b;
            if(remain_x == 0 && remain_y == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}