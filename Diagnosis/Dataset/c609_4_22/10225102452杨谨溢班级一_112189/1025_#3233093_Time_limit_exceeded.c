#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int win;
int fail;
int draw;// end in a draw
int score;
}TEAM;

int main()
{
    int n,m;
    while(scanf("%d &d"),&n,&m)
    {
        if (n == 0&m ==0)  break;
        TEAM* TT = (TEAM*)malloc((n+1)*sizeof(TEAM));
        for (int i = 0;i<n;++i)
        {
            TT[i].win = 0;
            TT[i].fail = 0;
            TT[i].draw = 0;
            TT[i].score = 0;
        }
        while(m--)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            switch (c)
            {
            case 1:{
                TT[a].win++;
                TT[b].fail++;
                break;
                }
            case -1:{
                TT[b].win++;
                TT[a].fail++;
                break;
            }
            case 0:{
                TT[b].draw++;
                TT[a].draw++;
                break;
                }
            }
        }
    }
    return 0;
}
