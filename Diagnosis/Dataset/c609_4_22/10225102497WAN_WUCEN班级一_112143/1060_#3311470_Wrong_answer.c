#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(int pos,char*t);

int main()
{
    char s[101],ans[203]={'a'},t[203];
    scanf("%s",s);
    int len=strlen(s);
    strcpy(t,s);
    for(int i=0;i<len;i++)
    {
        int lent=0;
        lent=strlen(t);
        insert(lent-len+i,t);
        if(strcmp(ans,t)>0)
            strcpy(ans,t);
        else
            strcpy(t,ans);
    }
    printf("%s",ans);
}

void insert(int pos,char*t)
{
    for(int i=strlen(t)+1;i>pos;i--)
        t[i]=t[i-1];
}
