#include <stdio.h>
#include <stdlib.h>
#define len 1000

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int a,n;
        scanf("%d %d",&a,&n);
        int num[len]={0};
        num[len-1]=1;
        int j,h;
        for (j=0;j<n;j++)
        {
            for (h=len-1;h>=0;h--)
                num[h]*=a;
            for (h=len-1;h>=0;h--)
                if (num[h]>=10)
                {
                    num[h-1]+=num[h]/10;
                    num[h]=num[h]%10;
                }
        }

        int start;
        for (j=0;j<len;j++)
            if (num[j]==0 && num[j+1]!=0)
            {
                start=j+1;
                break;
            }
        for (j=start;j<len;j++)
            printf("%d",num[j]);
        printf("\n");
    }
    return 0;
}
