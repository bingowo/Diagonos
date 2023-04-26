#include <stdio.h>
#include <stdlib.h>

int Xiaoyu(char *s){
    int i=0;
    while(s[i]){
        if(s[i]!=s[i+1]&&s[i+1])
            break;
        i++;
    }
    if(s[i]<s[i+1]) return 1;
    else return 0;
}

int main()
{
    char s[101];
    char t[202];
    int i,j;
    scanf("%s",s);
    for(i=0,j=0;s[i];i++){
        t[j++]=s[i];
        if(s[i]<s[i+1]&&s[i+1])
            t[j++]=s[i];
        if(s[i]==s[i+1]&&Xiaoyu(s+i+1)&&s[i+2])
            t[j++]=s[i];
    }
    t[j]='\0';
    for(int k=0;t[k];k++)
        printf("%c",t[k]);
    return 0;
}
