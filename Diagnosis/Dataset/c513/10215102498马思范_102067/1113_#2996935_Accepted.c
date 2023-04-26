#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    int res[k][100];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<100;j++)
            res[i][j]=0;
    }
    res[1][0]=1;
    if(n==1)
        printf("%d",0);
    else if(n==2)
        printf("%d",1);
    else
    {
        for(int i=2;i<n;i++)
        {
            int sum=0,carry=0;
            for(int j=0;j<100;j++)
            {
                sum=0;
                for(int m=0;m<k;m++)
                    sum+=res[m][j];
                sum+=carry;
                res[i%k][j]=sum%10;
                carry=sum/10;
            }
        }
        int flag;
        for(flag=99;res[(n-1)%k][flag]==0;flag--) ;
        for(;flag>=0;flag--)
            printf("%d",res[(n-1)%k][flag]);
    }
    return 0;
}
