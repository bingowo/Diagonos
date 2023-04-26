#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int base,n;
        char arr[1001];
        memset(arr,-1,1001);
        arr[0]=1;
        scanf("%d%d",&base,&n);
        if(!n)
        {
            printf("case #%d:\n%d\n",i,1);
            continue;
        }
        int j=0;
        for(;j<n;j++)
        {
            int t=0;
            for(;arr[t]>=0;t++)
            {
                if(arr[t]>9){arr[t+1]+=arr[t+1]<0?arr[t]/10+1:arr[t]/10;arr[t]=arr[t]%10;}
                arr[t]*=base;
                //if(arr[t]>9){arr[t+1]+=arr[t+1]<0?arr[t]/10+1:arr[t]/10;arr[t]=arr[t]%10;}
            }
        }
        for(int t=0;arr[t]>=0;t++)
        {
            if(arr[t]>9){arr[t+1]+=(arr[t+1]<0?arr[t]/10+1:arr[t]/10);arr[t]=arr[t]%10;}
        }
        printf("case #%d:\n",i);
        int k=0;
        for(;arr[k]>=0;k++);
        for(;k>0;k--)printf("%d",arr[k-1]);
        printf("\n");
    }
}
