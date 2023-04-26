#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int n,i,j,s[1000]={1};
        scanf("%d",&n);
        for(i=2;i<=n;i++)
        {
            for(j=0;j<1000;j++)
                s[j]*=i;
            for(j=0;j<1000;j++)
            {
                if(s[j]>=10)
                {
                    s[j+1]+=s[j]/10;
                    s[j]%=10;
                }
            }
        }
        int k=0;
        while(s[k]==0)k++;
        printf("%d\n",k);
    }
    return 0;
}
