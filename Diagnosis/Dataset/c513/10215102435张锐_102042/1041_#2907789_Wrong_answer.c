#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int num=1;int temp=0;
    for(int i=0;i<len-1;i++)
    {
        if(s[i]!=s[i+1]&&temp==0) {temp++;}
        if(s[i]!=s[i+1]&&i==len-2) temp++;
        if(temp>num) num=temp;
        else if(s[i]==s[i+1])
        {
            if(temp>num) num=temp;
            temp=0;
        }
    }
    printf("%d",num);
}