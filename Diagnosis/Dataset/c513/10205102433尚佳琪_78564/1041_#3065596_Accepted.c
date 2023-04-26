#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int ans=1,temp=1;
    for(int i=0;i<len-1;i++)
    {
        for(int j=i;j<len-1;j++)
        {
            if(s[j]!=s[j+1])temp++;
            else
            {
                ans=ans>temp?ans:temp;
                temp=1;
                break;
            }
        }
        ans=ans>temp?ans:temp;
        temp=1;
    }
    printf("%d",ans);
}
