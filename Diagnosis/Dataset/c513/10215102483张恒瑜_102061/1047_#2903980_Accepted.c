#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s[510]={'\0'};
        scanf("%s",s);
        printf("case #%d:\n",t);
        int i,cnt=1;
        for(i=0;i<strlen(s)-1;i++)
        {
            if(s[i]!=s[i+1]) {printf("%d%c",cnt,s[i]);cnt=1;}
            else if(s[i]==s[i+1]) cnt++;
            if(cnt==256) {printf("%d%c",255,s[i]);cnt=1;}
        }
        printf("%d%c\n",cnt,s[i]);
    }
    return 0;
}