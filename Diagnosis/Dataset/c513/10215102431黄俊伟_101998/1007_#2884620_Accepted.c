#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int T,n,i,ans=1,temp=1,j=0;
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
                temp=1;
            if(temp>ans)
                ans=temp;
            j--;
        }
        printf("case #%d:\n%d\n",i,ans);
        ans=temp=1;j=0;
    }
    return 0;
}
