#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);// n team number    m match number
    extern int n,m;
    int i;
    int team[n][3]; // team[team number][grade,win,lose]
    for (i = 0; i < n; i++)
    {
        team[i][0] = 0;
        team[i][1] = 0;
        team[i][2] = 0;
    }
    int a,b,c;// ab team number c win/lose
    scanf("%d%d%d",&a,&b,&c);
    if (c == 1) // a win b lose
    {
        team[a-1][0] += 3;
        team[a-1][1] += 1;
        team[b-1][0] -= 1;
        team[b-1][2] += 1;
    }
    else if (c == 0) // a = b
    {
        team[a-1][0] += 1;
        team[b-1][0] += 1;
    }
    else // a lose b win
    {
        team[b-1][0] += 3;
        team[b-1][1] += 1;
        team[a-1][0] -= 1;
        team[a-1][2] += 1;
    }
    /*
    开始排序
    排序权重
    积分>胜场次>输场次>编号
    */
    /*
    **********************************************************************
    qsort
    **********************************************************************
    */
    return 0;
}

int *cmp (const void *a,const void *b)
{
    int *grade1,*grade2;
    int i;
    grade1 = *team[i][0];
}
