#include <stdio.h>
#include <string.h>
#include <math.h>

int main() 
{
    int T,len,sum,num[1000],i,a = 0;
    char str[1000];
    scanf("%d",&T);
    while(n--)
    {
        sum = 0;
        scanf("%s",str);
        len = strlen(str);
        for(i = 0;i < len;i++)
        {
            if(str[i]=='-')
            num[i] = -1;
            if(str[i]=='1')
            num[i] = 1;
            if(str[i]=='0')
            num[i] = 0;
            sum = sum + num[i]*pow(3,len-1-i);
        }
        printf("case #");
        printf("%d:\n",a);
        a += 1;
        printf("%d\n",sum);
    }
    return 0;
}