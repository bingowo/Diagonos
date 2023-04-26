#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int z= 0;z<n;z++)
    {
        printf("case #%d:\n",z);
        int res[2000];
        int last[2000];
        memset(res,0,sizeof(res));
        memset(last,0,sizeof(last));
        int up,down;
        scanf("%d%d",&up,&down);
        int cnt =0;
        last[0] = up;
        int same[2]={-1,-1};
        while(up!=0)
        {
            while(up<down)
            {
                up*=10;
                cnt++;
            }
            res[cnt] = up/down;
            up = up%down;
            last[cnt] = up;
            int i;
            for( i =0;i<cnt;i++)
            {
                if(last[i]==up)
                {
                    same[0] = i+1;
                    same[1] = cnt;
                break;
                }
                else if(last[i]==up*10)
                {
                     same[0] = i+1;
                    same[1] = cnt+1;
                    break;
                }
            }
            if(i!=cnt)break;
         }
            printf("0.");
            if(same[0]!=-1)
            {

                for(int q=1;q<=cnt;q++)
                {
                    printf("%d",res[q]);
                }
                printf("\n");
                printf("%d-%d",same[0],same[1]);
            }
            else
            {
                 for(int q=1;q<=cnt;q++)
                {
                    printf("%d",res[q]);
                }
            }
            if(z!=n-1)printf("\n");
    }
    return 0;
}
