#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int n,a[2000],cnt=0;
        scanf("%d",&n);
        while(n>0)//转换为二进制
        {
            a[cnt]=n%2;
            n/=2;
            cnt++;
        }
        int cnt2=1;
        int max=cnt2;
        for(int j=1;j<cnt;j++)
        {
            if(a[j]!=a[j-1]) cnt2++;
            else
            {
                if(a[j]==0) cnt2=0;
                else cnt2=1;
            }
            if(max<cnt2) max=cnt2;
        }
        printf("%d\n",max);
    }
    return 0;
}