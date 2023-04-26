#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int a;
    int i=0;
    int m=0;
    scanf("%d",&a);
    char s[100];
    for(int j=0;j<a;j++)
    {
        scanf("%s",&s);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='1')
            {
                m=m+pow(3,strlen(s)-i-1);
            }
            else if(s[i]=='0')
            {
                m=m;
            }
            else if(s[i]=='-')
            {
                m=m-pow(3,strlen(s)-i-1);
            }
        }
        printf("case #%d:",j);
        printf("\n");
        printf("%d",m);
        printf("\n");
    }
    return 0;
}