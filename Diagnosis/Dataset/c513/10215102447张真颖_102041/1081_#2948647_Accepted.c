#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int a=0,n=0;
        scanf("%d%d",&a,&n);
        int arr[95]={1},carry=0,cnt=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<cnt;j++)
            {
                int tmp=arr[j]*a+carry;
                arr[j]=tmp%10;
                carry=tmp/10;
            }
            if(carry)
            {
                arr[cnt]=carry;
                carry=0;
                cnt++;
            }

        }
        printf("case #%d:\n",i);
        for(int i=cnt-1;i>=0;i--)
            printf("%d",arr[i]);
        printf("\n");
    }
    return 0;
}