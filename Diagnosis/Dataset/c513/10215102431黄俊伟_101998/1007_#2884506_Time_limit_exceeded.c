#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int T,n,i,ans,temp=0,j=0;
    char bin[33];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        while(n!=0)
        {
            bin[j++]=n%2;
            n/=2;
        }
        j--;
        while(j>=1)
        {
            if(bin[j]!=bin[j-1])
                temp++;
            else
                temp=0;
            if(temp>ans)
                ans=temp;
        }
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}
