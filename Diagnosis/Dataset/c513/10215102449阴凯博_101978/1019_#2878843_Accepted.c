#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int number;
    int score;
    int win;
    int lose;
}TEAM;

int cmp(const void* a,const void*b)
{
    TEAM* pa=(TEAM*)a;
    TEAM* pb=(TEAM*)b;
    if (pa->score>pb->score) return -1;
    else if (pa->score<pb->score) return 1;
    else if (pa->score==pb->score)
    {
        if (pa->win>pb->win) return -1;
        else if (pa->win<pb->win) return 1;
        else if (pa->win==pb->win)
        {
            if (pa->lose>pb->lose) return 1;
            else if (pa->lose<pb->lose) return -1;
            else if (pa->lose==pb->lose) return(pa->number>pb->number?1:-1);
        }
    }

}


int main()
{
    int n,m;

    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0) break;
        else
        {
            int j;
            TEAM* arr=(TEAM*)malloc(n*sizeof(TEAM));
            for (j=0;j<n;j++) arr[j].number=j+1;
            for (j=0;j<n;j++) arr[j].score=0;
            for (j=0;j<n;j++) arr[j].win=0;
            for (j=0;j<n;j++) arr[j].lose=0;
            for (int i=0;i<m;i++)
            {
                int a,b,c;
                scanf("%d%d%d",&a,&b,&c);
                if (c==1)
                {
                    arr[a-1].score=arr[a-1].score+3;
                    arr[b-1].score=arr[b-1].score-1;
                    arr[a-1].win=arr[a-1].win+1;
                    arr[b-1].lose=arr[b-1].lose+1;
                }
                if (c==-1)
                {
                    arr[b-1].score=arr[b-1].score+3;
                    arr[a-1].score=arr[a-1].score-1;
                    arr[b-1].win=arr[b-1].win+1;
                    arr[a-1].lose=arr[a-1].lose+1;
                }
                if (c==0)
                {
                    arr[a-1].score=arr[a-1].score+1;
                    arr[b-1].score=arr[b-1].score+1;
                }
            }
            qsort(arr,n,sizeof(TEAM),cmp);
            for (j=0;j<n;j++)
                printf("%d%c",arr[j].number,j==(n-1)?'\n':' ');
        }
    }
    return 0;
}