#include<stdio.h>
#include<stdlib.h>



typedef structure
{
    int id;
    int win;
    int draw;
    int lose;
    int score;
}DATA;

int cmp(const void *a , const void *b)
{   //积分降序，win降序，lose升序，编号升序
    DATA *x = (DATA*)a;
    DATA *y = (DATA*)b;
    if(x->score != y->score)
        return (y->score - x->score);
    else
    {
        if(x->win != y->win)
            return(y->return - x->return);
        else 
        {
            if(x->lose != y->lose)
                return (x->lose - y->lose);
            else
                return (x->id - y->id);
        }
    }
}

int main()
{
    int teams,times;
    
    while(scanf("%d %d",&teams,&times) != EOF)  //进入每一组数据
    {
        if(teams == 0 && times == 0)       //00停止输入
            break;
        
        DATA PLAYER[teams]; 
    	int index,i;
        for(i=0;i<teams;i++)
        {
            PLAYER[i].win   = 0;
            PLAYER[i].draw  = 0;
            PLAYER[i].lose  = 0;
            PLAYER[i].score = 0;
            PLAYER[i].id = i+1;
        }
            
    	for(index = 0;index < times;index++)  //对每一次比赛
    	{
            int play1,play2,digit;
            scanf("%d %d %d",&play1,&play2,&digit);
            if(digit == 1)
            {
                PLAYER[play1].score += 3;
                PLAYER[play2].score += -1;
                PLAYER[play1].win++;
                PLAYER[play2].lose++;
            }
            else if(digit == -1)
            {
                PLAYER[play1].score += -1;
                PLAYER[play2].score += 3;
                PLAYER[play1].lose++;
                PLAYER[play2].win++;
            }
            else
            {
                PLAYER[play1].score++;
                PLAYER[play2].score++;
                PLAYER[play1].draw++;
                PLAYER[play2].draw++;
            }
            
    	}
        
            qsort(PLAYER , teams , sizeof(DATA) , cmp);
            int j;
        for(j=0;j<teams-1,j++)
            printf("%d ",PLAYER[j].id);
        printf("%d\n",PLAYER[teams-1]);
            
    }
    return 0;
}