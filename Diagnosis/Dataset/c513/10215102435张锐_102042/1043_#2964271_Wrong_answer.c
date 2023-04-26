#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void shan(char *t)
{
    int len=strlen(t);char ans[150];int p=0;
    char c;
    if(t[len-1]!=t[len-2]) c=t[len-1];
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(t[j]!=t[i])
            {
                if(j>i+1) ;
                else ans[p++]=t[i];
                i=j-1;
                break;
            }
        }
    }
    if(t[len-1]!=t[len-2]) ans[p++]=c;
    ans[p]='\0';
    strcpy(t,ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[150];
        scanf("%s",s);
        int len=strlen(s);
        for(int f=0;f<len;f++) shan(s);
        int min=strlen(s);
        for(int j=0;j<strlen(s);j++)
        {
            char temp[150];int i=0;int k;
            for(k=0;k<j;k++) temp[i++]=s[k];
            temp[i++]=s[k];
            for(;k<len;k++) temp[i++]=s[k];
            temp[i]='\0';char s1[150];
            for(int f=0;f<len;f++) shan(temp);
            int n=strlen(temp);
            if(n<min) min=n;
        }
        printf("case #%d:\n",i);
        printf("%d\n",len+1-min);
    }
    return 0;
}
