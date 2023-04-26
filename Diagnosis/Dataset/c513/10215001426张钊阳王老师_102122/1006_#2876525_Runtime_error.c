#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int m,i,j,count=0;
    long long int sum=0;
    scanf("%d",&m);
    char k[30];
    for(int t=0;t<m;t++)
    {
        scanf("%s",k);
        while(k[i])
        {
            count++;
            i++;
        }
        for(i=0;i<count;i++)
        {
            if(k[i]=='-') sum=sum-pow(3,count-i-1);
            if(k[i]=='0')     ;
            if(k[i]=='1') sum=sum+pow(3,count-i-1);
        }
        printf("case #%d:\n",t);
        printf("%lld\n",sum);
    }
    return 0;
}

