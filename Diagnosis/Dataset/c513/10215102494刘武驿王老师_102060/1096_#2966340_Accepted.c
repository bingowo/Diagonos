#include<stdio.h>
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int step,start[200][1],end[200][1],ts,te,cards[10000][2];
        scanf("%d",&step);
        for(int j=0;j<200;j++)
        {
            start[j][0]=0;
            end[j][0]=0;
        }
        int tmp;
        scanf("%d",&tmp);
        start[tmp][0]+=1;
        cards[0][0]=tmp;
        scanf("%d",&tmp);
        cards[0][1]=tmp;
        end[tmp][0]+=1;
        for(int j=1;j<step;j++)
        {
            int tmp1;
            scanf("%d",&tmp);
            scanf("%d",&tmp1);
            cards[j][0]=tmp;cards[j][1]=tmp1;
            int tst=1;
            for(int p=0;p<j;p++)
            {
                if(cards[p][0]==cards[j][0]&&cards[p][1]==cards[j][1])
                {
                    tst=0;
                    break;
                }
            }
            if(tst==0) continue;
            end[tmp1][0]+=1;
            start[tmp][0]+=1;
        }
        int test=0;
        for(int j=0;j<200;j++)
        {
            if(start[j][0]>1)
            {
                    test=1;
                    break;
            }
            if(start[j][0]!=0)
            {
                if(end[j][0]!=0)
                {
                    test=1;
                    break;
                }
            }
        }
        if(test==1) printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
}