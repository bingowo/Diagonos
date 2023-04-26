#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{

    char s[101];
    scanf("%s",&s);
    int ans=0,tmp=0;
    int p=0,isZero=0;
    if(isdigit(s[0])){
        tmp=1;p=1;
    }
    for(int i=1;i<strlen(s);i++){
        if(s[i]=='0' && isalpha(s[i-1])) isZero=1;
        if(isZero && s[i]!='0') isZero=0;
        if(isdigit(s[i])){
            if(isZero) continue;
            tmp++;
            if(tmp>ans) ans=tmp;
        }
        if(isalpha(s[i])){
            if(tmp>ans) ans=tmp;
            tmp=0;
        }
    }
    printf("%d",ans);

    return 0;
}
