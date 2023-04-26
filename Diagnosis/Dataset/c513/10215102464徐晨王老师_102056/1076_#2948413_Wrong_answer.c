#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pd(char* ss){
    for(int i=0;i<strlen(ss)-1;i++){
        if(ss[i]=='{'){
            if(ss[i+1]=='('||ss[i+1]=='{'||ss[i+1]==']'||ss[i+1]==')'){printf("No\n");return;}
            else continue;
        }
        if(ss[i]=='['){
            if(ss[i+1]=='['||ss[i+1]=='{'||ss[i+1]==')'||ss[i+1]=='}'){printf("No\n");return;}
            else continue;
        }
        if(ss[i]=='('){
            if(ss[i+1]=='('||ss[i+1]=='['||ss[i+1]=='}'||ss[i+1]==']'){printf("No\n");return;}
            else continue;
        }
    }
        for(int i=strlen(ss)-1;i>0;i--){
        if(ss[i]=='}'){
            if(ss[i-1]==')'||ss[i-1]=='}'||ss[i-1]=='['||ss[i-1]=='('){printf("No\n");return;}
            else continue;
        }
        if(ss[i]==']'){
            if(ss[i-1]==']'||ss[i-1]=='}'||ss[i+1]=='('||ss[i+1]=='{'){printf("No\n");return;}
            else continue;
        }
        if(ss[i]==')'){
            if(ss[i-1]==')'||ss[i-1]==']'||ss[i+1]=='{'||ss[i+1]=='['){printf("No\n");return;}
            else continue;
        }
    }
    printf("Yes\n");return;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[101];
        scanf("%s",s);
        int a=0,a1=0,b=0,b1=0,c=0,c1=0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='{')a=a+1;
            if(s[i]=='}')a1=a1+1;
            if(s[i]=='[')b=b+1;
            if(s[i]==']')b1=b1+1;
            if(s[i]=='(')c=c+1;
            if(s[i]==')')c1=c1+1;
        }
        if(a==a1&&b==b1&&c==c1){pd(s);}
        else printf("No\n");
        //pd(s);
    }

}
