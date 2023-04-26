#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Teams
{
    int num;
    int score;
    int win;
    int lose;
}team;
int inc(const void *a, const void *b)
{
	if((* (team *)a).score != ( * (team *)b).score)
	    return ( * (team * )a).score < ( * (team * )b).score ? 1 : -1;
	else if ((* (team *)a).win!=(* (team *)b).win)
        return (* (team * )a).win < ( * (team * )b).win ? 1 : -1;
    else if((* (team *)a).lose!=(* (team *)b).lose)
        return (* (team * )a).lose > ( * (team * )b).lose ? 1 : -1;
    else 
        return (* (team *)a).num>(* (team *)b).num ? 1:-1;
 }
int main()
{
    int m,n;
    int inc(const void *a, const void *b);
    while(1)
    {
        int a,b,c;
        scanf("%d %d",&m,&n);
        if(!(m==0&&n==0))
        {
            team t[m+1];
            for(int i=1;i<m+1;i++)
            {  
                t[i].num=i;
                t[i].score=0;
                t[i].win=0;
                t[i].lose=0;
            }
            for(int j=0;j<n;j++)
            {
                scanf("%d %d %d",&a,&b,&c);
                if(c==1)
                {
                    t[a].score+=3;
                    t[a].win++;
                    t[b].score-=1;
                    t[b].lose++;
                }
                else if(c==-1)
                {
                    t[b].score+=3;
                    t[b].win++;
                    t[a].score-=1;
                    t[a].lose++;
                }
                else 
                {
                    t[a].score+=1;
                    t[b].score+=1;
                }

            }
        qsort(t+1,m,sizeof(team), inc);
        for(int k=1;k<m+1;k++)
            printf("%d ",t[k].num);
        printf("\n");
        }
        else 
            break;
    }
    return 0;
}