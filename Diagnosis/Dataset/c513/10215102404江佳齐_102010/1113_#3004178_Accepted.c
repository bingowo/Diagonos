#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,n;
    scanf("%d %d",&k,&n);
    int s[k][100];
    int i,j,m;
    for(i=0;i<k;i++)
    {
        for(j=0;j<100;j++)
            s[i][j]=0;
    }
    s[1][0]=1;
    if(n==1) printf("0\n");
    else if(n==2) printf("1\n");
    else
    {
        for(i=2;i<n;i++)
        {
            int sum=0,carry=0;
            for(j=0;j<100;j++)
            {
                sum=0;
                for(m=0;m<k;m++)
                    sum+=s[m][j];
                sum+=carry;
                s[i%k][j]=sum%10;
                carry=sum/10;
            }
        }
        int x;
        for(x=99;s[(n-1)%k][x]==0;x--);
        for(;x>=0;x--)
            printf("%d",s[(n-1)%k][x]);
    }
    return 0;
}
