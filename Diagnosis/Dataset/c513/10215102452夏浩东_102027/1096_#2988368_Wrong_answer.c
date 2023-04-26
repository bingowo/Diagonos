#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int k=0;k<cnt;k++)
    {
        int num=0;
        scanf("%d",&num);
        int L[100][2];
        for(int i=0;i<num;i++)
        {
            scanf("%d %d",&L[i][0],&L[i][1]);
        }
        int res=1;
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(L[i][0]==L[j][0] || L[i][0]==L[j][1] || L[i][1]==L[j][0]){res=0;break;}
            }
            if(res==0) break;
        }
        if(res==1) printf("Lucky dxw!\n");
        else printf("Poor dwx!\n");
    }
    return 0;
}