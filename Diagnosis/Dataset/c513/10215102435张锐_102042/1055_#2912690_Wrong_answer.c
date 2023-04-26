#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000001];
    scanf("%s",s);
    int num=1,temp=1,k=0,zhong=0;
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        for(int j=zhong;j<i;j++)
        {
            if(s[j]==s[i])
            {
                if(temp>num) {num=temp,k=i;}
                zhong=i-1;
                temp=1;
                break;
            }
            if(j==i-1&&s[j]!=s[i]) temp++;
        }
        if(temp>num) {num=temp;k=i;}
    }
    for(int i=k-num+1;i<=k;i++) printf("%c",s[i]);
}