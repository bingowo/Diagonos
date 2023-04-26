#include <stdio.h>
#include <stdlib.h>

typedef struct
    {
        int id;
        int score;
        int wins;
        int loses;
    } team;
int cmp(const void *a,const void *b)
{
    team *pa,*pb;
    pa = (team *)a;
    pb = (team *)b;
    if(pa->score != pb->score) return pb->score-pa->score;
    else{
        if(pa->wins != pb->wins) return pb->wins-pa->wins;
        else{
            if(pa->loses != pb->loses) return pa->loses-pb->loses;
            else return pa->id-pb->id;
        }
    }
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n){
        team L[n];
        for(int i=0;i<n;i++){
            L[i].id = i+1;//队伍id录入
            L[i].loses = 0;
            L[i].wins = 0;
            L[i].score = 0;
        }
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            switch(c)
            {
                case 1:L[a-1].wins++,L[a-1].score += 3,L[b-1].loses++,L[b-1].score--;break;
                case -1:L[b-1].wins++,L[b-1].score += 3,L[a-1].loses++,L[a-1].score--;break;
                case 0:L[a-1].score++,L[b-1].score++;break;
            }
        }
        //for(int i=0;i<n;i++) printf("%d %d %d %d\n",L[i].id,L[i].score,L[i].wins,L[i].loses);
        qsort(L,n,sizeof(team),cmp);
        for(int i=0;i<n;i++) printf("%d%c",L[i].id,(i == n-1)?'\n':' ');
    }
    return 0;
}
