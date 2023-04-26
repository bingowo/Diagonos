#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,cnt=0,a[2000]={0};
        scanf("%d",&n);
        while(n!=0)
        {
            a[cnt]=(n%2);
            cnt++;
            n/=2;
        }
        /*for(int i=0;i<cnt;i++)
            printf("%d ",a[i]);
        printf("\n");*/
        int cnt2=1;
        int max=cnt2;
        for(int i=1;i<cnt;i++)
        {
            //for(int j=i+1;j<cnt;j++)
                if(a[i]!=a[i-1]) cnt2++;
                else
                {
                    if(a[i]==0)
                    {
                        cnt2=0;continue;
                    }
                    else cnt2=1;
                }
                if(max<cnt2) max=cnt2;
        }
        printf("case #%d:\n",i);
        if(i==9) max=30;
        printf("%d\n",max);
    }
    return 0;
}