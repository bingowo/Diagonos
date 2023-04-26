#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int q;
        scanf("%d",&q);
        int flag1=q%2;
        int flag2;
        int ans=1;
        int temp=1;
        while(q/2>0)
        {
            q=q/2;
            flag2=q%2;
            if(flag2!=flag1)
            {
                temp++;
                if(temp>ans)
                {
                    ans=temp;
                }
                flag1=flag2;

            }
            else
            {
                temp=1;
                flag1=flag2;
            }
        }
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}
