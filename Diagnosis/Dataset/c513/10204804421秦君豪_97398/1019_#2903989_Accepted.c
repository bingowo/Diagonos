#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
#include<stdlib.h>
 typedef struct x
{
    int score;
    int wingame;
    int losegame;
    int num;
}team;
int cmp(const void* a,const void* b)
{
    team *a1=(team*)a;
    team *b1=(team*)b;
    if((a1->score)!=(b1->score)) return ((a1->score)>(b1->score))?-1:1;
    else if((a1->wingame)!=(b1->wingame)) return ((a1->wingame)>(b1->wingame))?-1:1;
    else if((a1->losegame)!=(b1->losegame)) return ((a1->losegame)>(b1->losegame))?1:-1;
    else return ((a1->num)>(b1->num))?1:-1;  
}


int main()
{
    int T,i,j,n;
    int a,b,c=0;
    long long int m;
    scanf("%d%d",&n,&m);
    while ((n!=0)||(m!=0))
    {
        team t[n];
        for(i=0;i<n;i++) 
        {
            t[i].num=i+1;
            t[i].score=0;
            t[i].wingame=0;
            t[i].losegame=0;
        }
//        printf("c=%d",c);
        for(i=0;i<m;i++)
        {
        	
            scanf("%d %d %d",&a,&b,&c);
            if(c==1) 
            {
                t[a-1].wingame++;
                t[b-1].losegame++;
                t[a-1].score+=3;
                t[b-1].score-=1;
            }
            if(c==0)
            {
                t[a-1].score++;
                t[b-1].score++;
            }
            if(c==(-1))
            {
            	t[a-1].score--;
            	t[b-1].score+=3;
                t[a-1].losegame++;
                t[b-1].wingame++;
            }
        }
        qsort(t,n,sizeof(t[0]),cmp);
        for (i=0;i<n;i++)
        {
            printf("%d%c",t[i].num,i==n-1?'\n':' ');
        }
        scanf("%d%d",&n,&m);
    }
    system("pause");
    return 0;
}
