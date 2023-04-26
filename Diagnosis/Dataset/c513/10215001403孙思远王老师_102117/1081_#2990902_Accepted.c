#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int a,n,i,j,b1,b2;
        scanf("%d%d",&a,&n);
        int s[1000]={0};
        s[0]=a;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<1000;j++)
                s[j]*=a;
            for(j=0;j<1000;j++)
            {
                if(s[j]>=10)
                {
                    b1=s[j]/10;
                    b2=s[j]%10;
                    s[j]=b2;
                    s[j+1]+=b1;
                }
            }
        }
        if(n==0)
            s[0]=1;
        for(i=999;i>=0;i--)
        {
            if(s[i]!=0)
                break;
        }
        for(;i>=0;i--)
        {
            printf("%d",s[i]);
        }
        printf("\n");
    }
    return 0;
}
