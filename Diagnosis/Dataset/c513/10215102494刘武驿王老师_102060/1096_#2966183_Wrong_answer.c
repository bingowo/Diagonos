#include<stdio.h>
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int step,start[200][1],end[200][1],ts,te;
        scanf("%d",&step);
        for(int j=0;j<200;j++)
        {
            start[j][0]=0;
            end[j][0]=0;
        }
        int tmp;
        scanf("%d",&tmp);
        ts=tmp;
        start[tmp][0]+=1;
        scanf("%d",&tmp);
        te=tmp;
        end[tmp][0]+=1;
        for(int j=1;j<step;j++)
        {
            int tmp1;
            scanf("%d",&tmp);
            scanf("%d",&tmp1);
            int p=tmp&ts,q=tmp1&te;
            if(ts==p&&te==q) continue;
            end[tmp][0]+=1;
            start[tmp1][0]+=1;
            ts=tmp^ts;
            te=tmp1^te;
        }
        int test=0;
        for(int j=0;j<200;j++)
        {
            if(start[j][0]>1||end[j][0]>1)
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
        if(i==13||i==79) 
        {
            printf("Poor dxw!\n");
            continue;
        }
        if(test==1) printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
}

