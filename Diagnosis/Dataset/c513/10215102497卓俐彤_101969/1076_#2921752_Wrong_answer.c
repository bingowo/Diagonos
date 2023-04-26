#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int flag=0;
        char s[101];
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='('){
                if(s[i+1]!=')'&&s[i+1]!='{')break;
            }else if(s[i]=='['){
                if(s[i+1]!=']'&&s[i+1]!='(')break;
            }else if(s[i]=='{'){
                if(s[i+1]!='}'&&s[i+1]!='[')break;
            }else if(s[i]==')'){
                if(s[i-1]!='}'&&s[i-1]!='(')break;
            }else if(s[i]==']'){
                if(s[i-1]!=')'&&s[i-1]!='[')break;
            }else if(s[i]=='}'){
                if(s[i-1]!=']'&&s[i-1]!='{')break;
            }
            if(i==strlen(s)-1)flag=1;
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

