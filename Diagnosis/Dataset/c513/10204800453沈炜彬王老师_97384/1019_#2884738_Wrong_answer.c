#include <stdio.h>
#include <stdlib.h>

int cmp(void* num1,void* num2);

int teams;

int
main()
{
    int matchs;

    while(scanf("%d",&teams))
    {
        scanf("%d",&matchs);

        if (teams==0&&matchs==0)    break;
        int* pdata=(int*)malloc(teams*sizeof(int)*4);
        for(int i=0;i<teams;i++) *(pdata+teams*3+i)= i+1;
        for(int i=0;i<teams*3;i++) *(pdata+i) = 0;
        //printf("%d ",matchs);
        //for(int i=0;i<teams*4;i++) printf("%d ",*(pdata+i));
        for(int i=0;i<matchs;i++)
        {
            int ta;
            int tb;
            int res;
            scanf("%d%d%d",&ta,&tb,&res);
            switch(res)
            {
                case(1):
                *(pdata+teams*0+ta-1) += 3;
                *(pdata+teams*0+tb-1) -= 1;
                *(pdata+teams*1+ta-1) += 1;
                *(pdata+teams*2+tb-1) += 1;
                break;

                case(-1):
                *(pdata+teams*0+ta-1) -= 1;
                *(pdata+teams*0+tb-1) += 3;
                *(pdata+teams*2+ta-1) += 1;
                *(pdata+teams*1+tb-1) += 1;
                break;

                case(0):
                *(pdata+teams*0+ta-1) += 1;
                *(pdata+teams*0+tb-1) += 1;
                break;
            }
        }

        //for(int i=0;i<teams*4;i++) printf("%d ",*(pdata+i));
        //printf("\n");
        qsort(pdata+3*teams,teams,sizeof(int),cmp);
        for (int i=0;i<teams;i++)
        {
            printf("%d ",*(pdata+3*teams+i));
        }
        free(pdata);
    }

    return 0;
}


int
cmp(void* num1,void* num2)
{
    int number1 = *((int*)num1);
    int number2 = *((int*)num2);
    //printf("%d %d\n",number1,number2);

    int lose1 = *((int*)num1-teams*1);
    int lose2 = *((int*)num2-teams*1);
    //printf("%d %d\n",lose1,lose2);
    int win1 = *((int*)num1-teams*2);
    int win2 = *((int*)num2-teams*2);
    //printf("%d %d\n",win1,win2);
    int score1 = *((int*)num1-teams*3);
    int score2 = *((int*)num2-teams*3);
    //printf("%d %d\n",score1,score2);
    //printf("\n");
    if (score1<score2) return 1;
    else if (score1==score2)
    {
        if (win1<win2) return 1;
        else if (win1==win2)
        {
            if (lose1>lose2) return 1;
            else if (lose1==lose2)
            {
                if (number1>number2) return 1;
            }
        }
    }
    return -1;
}
