# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);// n team number    m match number
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
    int *grade1,*grade2,*win1,*win2,*lose1,*lose2,*team1,*team2;
    int i = 0;
    grade1 = *((int **)a);
    grade2 = *((int **)b);
    win1 = grade1+1;
    win2 = grade2+1;
    lose1 = grade1+2;
    lose2 = grade2+2;
    team1 = *grade1;
    team2 = *grade2;
    if (grade1 == grade2)
    {
        if (win1 == win2)
        {
            if (lose1 == lose2)
            {
                return strcmp (team2,team1);
            }
            else
            {
                    return strcmp(lose2,lose1);
            }
        }
        else
        {
            return strcmp(win2,win1);
        }
    }
    else
    {
        return strcmp(grade2,grade1);
    }
}
