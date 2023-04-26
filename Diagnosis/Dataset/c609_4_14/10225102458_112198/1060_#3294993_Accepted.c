#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char s[110],ss[240];
    int count=0,cnt=0;
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        while(s[count]==s[i]&&count<len){count++;}
        if(s[count]>s[i])ss[cnt++]=s[i];
        ss[cnt++]=s[i];
    }
    ss[cnt]='\0';
    printf("%s\n",ss);
    return 0;
}
