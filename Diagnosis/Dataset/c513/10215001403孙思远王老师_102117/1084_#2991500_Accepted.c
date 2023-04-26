#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int n,i,j,s[10]={2};
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            for(j=0;j<10;j++)
                s[j]*=2;
            for(j=0;j<10;j++)
            {
                if(s[j]>9)
                {
                    s[j+1]+=s[j]/10;
                    s[j]%=10;
                }
            }
        }
        for(i=9;i>=0;i--)
        {
            if(s[i]!=0)
                break;
        }
        if(n==0)
            s[0]=1;
        for(;i>=0;i--)
            printf("%d",s[i]);
        printf("\n");
    }
    return 0;
}
