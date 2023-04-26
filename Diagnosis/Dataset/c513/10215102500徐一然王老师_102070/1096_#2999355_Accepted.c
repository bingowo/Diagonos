#include <stdio.h>

int main()
{
    int count,n;
    scanf("%d\n",&count);
    while(count--)
    {
        scanf("%d\n",&n);
        int dic[100001][2];
        int i=0,flag=0;
        while(n--)
        {
            scanf("%d %d",&dic[i][0],&dic[i][1]);i++;
        }
        for(int j=0;j<i;j++)
        {
            if(dic[j][0]==dic[j][1]){continue;}
            for(int k=j+1;k<i;k++)
            {
                if(dic[j][0]==dic[k][1])
                {
                    flag=flag+2;
                }
                else if(dic[j][1]==dic[k][0])
                {
                    flag=flag+2;
                }
                if(flag>=2)break;
            }
            if(flag>=2)break;
        }

        for(int j=0;j<i;j++)
        {
            if(dic[j][0]==dic[j][1]){continue;}
            for(int k=j+1;k<i;k++)
            {
                if(dic[j][0]==dic[k][0]&&dic[j][1]!=dic[k][1])
                {
                    flag+=2;//printf("%d %d\n",dic[j][0],dic[k][0]);
                }
            }
        }
        if(flag<=1)printf("Lucky dxw!\n");
            else printf("Poor dxw!\n");
    }
}
