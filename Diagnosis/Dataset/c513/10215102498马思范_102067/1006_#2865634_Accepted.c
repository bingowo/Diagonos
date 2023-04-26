#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int a;
    int i=0;
    scanf("%d",&a);
    char s[50];
    for(int j=0;j<a;j++)
    {
        long long int m=0;
        scanf("%s",s);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='1')
            {
                m=m+pow(3,strlen(s)-i-1);
            }
            else if(s[i]=='0')
            {
            }
            else if(s[i]=='-')
            {
                m=m-pow(3,strlen(s)-i-1);
            }
        }
        printf("case #%d:",j);
        printf("\n");
        printf("%lld",m);
        printf("\n");
    }
    return 0;
}
