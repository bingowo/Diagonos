#include <stdio.h>
#include <string.h>
#include <math.h>
int main() 
{
    int n,len,sum,i,j=0;
    char str[1000];
    scanf("%d",&n);
    while(n--)
    {
        sum = 0;
        scanf("%s",str);
        len = strlen(str);
        for(i = 0;i < len;i++)
        {
            if(str[i]=='-')
            sum=sum*3-1;
            if(str[i]=='1')
            sum=sum*3+1;
            if(str[i]=='0')
            sum=sum*3;
        }
        printf("case #%d:\n",j);
        printf("%d\n",sum);
        j++;
    }
    return 0;
}