#include <stdio.h>

int main()
{
    int W,H;
    int Dic[101][101];
    int two[8];
    scanf("%d %d",&W,&H);
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            scanf("%d",&Dic[i][j]);
        }
    }
    for(int i=1;i<H-1;i++)
    {
        for(int j=1;j<W-1;j++)
        {
            for(int flag=0;flag<8;flag++)
            {
                if(flag==0){if(Dic[i-1][j-1]>=Dic[i][j]) two[flag]=1;else two[flag]=0;}
                if(flag==1){if(Dic[i-1][j]>=Dic[i][j]) two[flag]=1;else two[flag]=0;}
                if(flag==2){if(Dic[i-1][j+1]>=Dic[i][j]) two[flag]=1;else two[flag]=0;}
                if(flag==3){if(Dic[i][j+1]>=Dic[i][j]) two[flag]=1;else two[flag]=0;}
                if(flag==4){if(Dic[i+1][j+1]>=Dic[i][j]) two[flag]=1;else two[flag]=0;}
                if(flag==5){if(Dic[i+1][j]>=Dic[i][j]) two[flag]=1;else two[flag]=0;}
                if(flag==6){if(Dic[i+1][j-1]>=Dic[i][j]) two[flag]=1;else two[flag]=0;}
                if(flag==7){if(Dic[i][j-1]>=Dic[i][j]) two[flag]=1;else two[flag]=0;}

            }
            int min=9999;
            for(int flag=0;flag<8;flag++)
            {   int sum=0,flag1=0;
                for(int i=flag;flag1<8;i++,flag1++){if(i>7)i=i-8;sum=sum*2+two[i];}
                if(min>sum)
                {
                    min=sum;
                }
                //printf("%d\n",sum);
            }
            if(j==W-2)
            {
                printf("%d\n",min);
            }
            else
            printf("%d ",min);
        }
    }
}
