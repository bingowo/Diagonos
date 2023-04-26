#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,T;
    scanf("%d\n",&T);
    for(t=0;t<T;t++)
    {
        printf("case #%d:\n",t);
        int m,n;
        scanf("%d%d",&m,&n);
        if((m-n)<=m/2)
            n=m-n;
        int s[50]={1},i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<50;j++)
                s[j]*=m-i;
            for(j=0;j<50;j++)
            {
                if(s[j]>9)
                {
                    s[j+1]+=s[j]/10;
                    s[j]%=10;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=49;j>0;j--)
            {
                s[j-1]+=s[j]%(i+1)*10;
                s[j]/=(i+1);
            }
            s[0]/=(i+1);
        }
        for(i=49;i>=0;i--)
        {
            if(s[i]!=0)
                break;
        }
        for(;i>=0;i--)
            printf("%d",s[i]);
        printf("\n");
    }
    return 0;
}
