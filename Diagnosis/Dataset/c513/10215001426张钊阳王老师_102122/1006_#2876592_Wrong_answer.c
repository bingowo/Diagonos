
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int m,i=0,j,count;
    long long int sum;
    scanf("%d",&m);
    for(j=0;j<m;j++)
    {
        sum=0;
        char k[30];
        count=0;
        scanf("%s",k);
        while(k[i]!='\0')
        {
            count++;
            i++;
        }
        for(i=0;i<count;i++)
        {
            if(k[i]=='-') sum=sum-pow(3,count-i-1);
            if(k[i]=='0')  continue;
            if(k[i]=='1') sum=sum+pow(3,count-i-1);
        }
        printf("case #%d:\n",j);
        printf("%lld\n",sum);
    }
    return 0;
}
