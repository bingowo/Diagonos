#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 95
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int a,n,j;
        int result[95]={0};
        result[0]=1;
        scanf("%d %d",&a,&n);
        int x,y;
        for(y=0;y<n;y++)
        {
            int carry=0;
            for(x=0;x<N;x++)
            {
                int t=result[x]*a+carry;
                result[x]=t%10;
                carry=t/10;
            }
        }
        for(j=N-1;j>0;j--)
        {
            if(result[j]!=0)
            {
                printf("%d",result[j]);
                j--;
                break;
            }
        }
        for(;j>0;j--)
        {
            printf("%d",result[j]);
        }
        printf("%d\n",result[j]);
    }
    return 0;
}

