#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int num=1;int temp=1;
    for(int i=0;i<len;i++)
    {
        if(temp!=1&&i==len-1) temp++;
        else if(s[i]!=s[i+1]) {temp++;}
        else if(s[i]==s[i+1])
        {
            if(temp>num) num=temp;
            temp=1;
        }
    }
    printf("%d",num);
}