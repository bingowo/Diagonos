#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n = 1, m = 1; //有多组测试数据，scanf需在循环内执行
    int team[10], score[10] = {0};
    int i, j, temp_score , temp_team , temp_win , temp_lose;
    int a[200], b[200], c[200];  //分别记录每场比赛的ab两队和结果
    int win[10] = {0}, lose[10] = {0}; //分别记录对应球队的胜负情况
    while( n != 0 || m != 0)//m=n=0时跳出循环
    {
        scanf("%d %d",&n,&m);
        if( n == 0 && m == 0)
            break;
        for( i = 1 ; i <= n ; i++)//对每支队伍赋初值
            team[i] = i;
        for( j = 1; j <= m ; j++)//遍历每次比赛
        {
            scanf("%d%d%d",&a[j],&b[j],&c[j]);
            if( c[j] == 1 )//分别考虑不同结果
            {
                score[a[j]] += 3;
                score[b[j]] --;
                win[a[j]] ++;
                lose[b[j]] ++;
            }
            else if( c[j] == -1)
            {
                score[b[j]] += 3;
                score[a[j]] --;
                win[b[j]] ++;
                lose[a[j]] ++;
            }
            else if( c[j] == 0)
            {
                score[b[j]] ++;
                score[a[j]] ++;
            }

            //首先根据分数从高到低排序
            for( j = 1 ; j <= n - 1 ; j++)
            {
                for( i = 1 ; i < n - j ; i++)
                {
                    if( score[i] < score[i+1] )
                    {
                        temp_score = score[i];    score[i] = score[i+1];    score[i+1] = temp_score;
                        temp_team = team[i];   team[i] = team[i+1];  team[i+1] = temp_team;//同时交换队伍编号、胜场数、负场数
                        temp_win = win[i];  win[i] = win[i+1];  win[i+1] = temp_win;
                        temp_lose = lose[i];    lose[i] = lose[i+1];    lose[i+1] = temp_lose;
                    }
                }
            }

            //其次根据胜场数排序
            for( j = 1 ; j <= n - 1 ; j++)
            {
                for( i = 1 ; i < n - j ; i++)
                {
                    if( score[i] == score[i+1] && win[i] < win[i+1])
                    {
                        temp_score = score[i];    score[i] = score[i+1];    score[i+1] = temp_score;
                        temp_team = team[i];   team[i] = team[i+1];  team[i+1] = temp_team;//同时交换队伍编号、胜场数、负场数
                        temp_win = win[i];  win[i] = win[i+1];  win[i+1] = temp_win;
                        temp_lose = lose[i];    lose[i] = lose[i+1];    lose[i+1] = temp_lose;
                    }
                }
            }

            //再根据负场数排序
            for( j = 1 ; j <= n - 1 ; j++)
            {
                for( i = 1 ; i < n - j ; i++)
                {
                    if( score[i] == score[i+1] && win[i] == win[i+1] && lose[i] > lose[i+1] )
                    {
                        temp_score = score[i];    score[i] = score[i+1];    score[i+1] = temp_score;
                        temp_team = team[i];   team[i] = team[i+1];  team[i+1] = temp_team;//同时交换队伍编号、胜场数、负场数
                        temp_win = win[i];  win[i] = win[i+1];  win[i+1] = temp_win;
                        temp_lose = lose[i];    lose[i] = lose[i+1];    lose[i+1] = temp_lose;
                    }
                }
            }

            //最后根据编号排序
            for( j = 1 ; j <= n - 1 ; j++)
            {
                for( i = 1 ; i < n - j ; i++)
                {
                    if( score[i] == score[i+1] && win[i] == win[i+1] && lose[i] == lose[i+1] && team[i] > team[i+1])
                    {
                        temp_score = score[i];    score[i] = score[i+1];    score[i+1] = temp_score;
                        temp_team = team[i];   team[i] = team[i+1];  team[i+1] = temp_team;//同时交换队伍编号、胜场数、负场数
                        temp_win = win[i];  win[i] = win[i+1];  win[i+1] = temp_win;
                        temp_lose = lose[i];    lose[i] = lose[i+1];    lose[i+1] = temp_lose;
                    }
                }
            }
        }
        //输出
        for( i = 1 ; i <= n ; i++)
            printf("%d ",team[i]);
        printf("\n");
    }
    return 0;
}
