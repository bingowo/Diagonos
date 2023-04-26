#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,t;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int x,j,count1=0,count2=0,flag=0;
        printf("case #%d:\n",t);
        scanf("%d",&x);
        j=1;
        j=j<<31;
        while((x|j)!=x)j=j>>1;
        while(j>0)
        {
            j=j>>1;
            if((x|j)==x&&flag==0)
            {
                count2++;
                flag=1;
                continue;
            }
            else if((x|j)!=x&&flag==1)
            {
                count2++;
                flag=0;
                continue;
            }
            else
            {
                count1=count1>count2?count1:count2;
                count2=1;
            }
        }
        printf("%d",count1);
    }
    return 0;
}
