#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    int* s1=(int*)p1;
    int* s2=(int*)p2;
    if (s1[0]!=s2[0])
        return s2[0]-s1[0];
    else
    {
        if (s1[1]!=s2[1])
            return s2[1]-s1[1];
        else
        {
            if(s1[2]!=s2[1])
                return s1[2]-s2[2];
            else
                return *s1-*s2;
        }
    }
    return 0;
}


int main()
{
    int n,m;
    int score[][3]={{0},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10}};  //[0]记录总积分，[1]记录胜场，[2]记录负场
    int battle[3];
    scanf("%d %d",&n,&m);getchar();
    if (n==0&&m==0)
    {
        system("pause");
        return 0;
    }
    else
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",battle[0],battle[1],battle[2]);getchar();
            switch (battle[2])
            {
            case 1:
                score[battle[0]][0]+=3;
                score[battle[0]][1]+=1;
                score[battle[1]][0]-=1;
                score[battle[1]][2]+=1;
                break;
            case -1:
                score[battle[1]][0]+=3;
                score[battle[1]][1]+=1;
                score[battle[0]][0]-=1;
                score[battle[0]][2]+=1;
                break;
            default:
                score[battle[0]][0]+=1;
                score[battle[1]][0]+=1;
                break;
            }
        }
    qsort(score,11,sizeof(score[0]),cmp);
    for(int i=0;i<10;i++)
    {
        if((score[i][1]!=0)||(score[i][2]!=0))
        (i!=9)?printf("%d ",score[i]):printf("\n");
    }
    system("pause");
    return 0;
}