#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000001];
    scanf("%s",s);
    int num=0,temp=1;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(s[j]==s[i])
            {
                if(temp>num) num=temp;
                temp=0;
                break;
            }
            if(j==i-1&&s[j]!=s[i]) temp++;
        }
        if(temp>num) num=temp;
    }
    printf("%d",num);
}