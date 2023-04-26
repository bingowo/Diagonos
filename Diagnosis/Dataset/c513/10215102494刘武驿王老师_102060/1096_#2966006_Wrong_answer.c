#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int step,start[200][1],end[200][1];
        scanf("%d",&step);
        for(int j=0;j<200;j++)
        {
            start[j][0]=0;
            end[j][0]=0;
        }
        for(int j=0;j<step;j++) 
        {
            int tmp;
            scanf("%d",&tmp);
            start[tmp][0]+=1;
            scanf("%d",&tmp);
            end[tmp][0]+=1;
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
        if(test==1) printf("Poor dxw!\n");
        else printf("Lucky dxw!\n");
    }
}
