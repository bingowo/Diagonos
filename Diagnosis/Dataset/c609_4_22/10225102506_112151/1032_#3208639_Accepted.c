#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cnt=1,cn;
    int i,len;
    char s[50];
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len-1;i++){
        cn=1;
        if(s[i]==s[i+1])
            cn=1;
        else{
            while(s[i+cn]!=s[i+cn-1] && (i+cn<=len-1)){
                cn++;
            }
        }
        if(cn>cnt)
            cnt=cn;
    }
    printf("%d",cnt);
    return 0;
}
