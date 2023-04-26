#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getPair(char c){
    switch(c){
    case ')':
        return '(';break;
    case ']':
        return '[';break;
    case '}':
        return '{';break;
    }
    return 0;
}

int isLeft(char c){
    if(c=='(' || c=='[' || c=='{')
        return 1;
    return 0;
}

int isValid(char* s){
    int L = strlen(s);

    char stk[101];
    memset(stk, 0, 101*sizeof(char));
    int top = 0;

    for(int i = 0;i<L;i++){
        //printf("%s\n",stk);
        if(isLeft(s[i])){
            stk[top] = s[i];
            switch(stk[top]){
            case '{':
                if (!(top==0 || stk[top-1]=='('))
                    return 0;break;
            case '[':
                if(!(top==0 || stk[top-1]=='{'))
                    return 0;break;
            case '(':
                if(!(top==0 || stk[top-1]=='['))
                    return 0;break;
            }
            top++;
        }else{
            if(stk[top-1]!=getPair(s[i])){
                return 0;
            }
            switch(s[i]){
            case ')':
                if(!(top==1 || stk[top-2]=='['))
                    return 0;break;
            case ']':
                if(!(top==1 || stk[top-2]=='{') || stk[top-1]=='[')
                    return 0;break;
            case '}':
                if(!(top==1 || stk[top-2]=='(') || stk[top-1]=='{')
                    return 0;break;
            }
            stk[top-1] = 0;
            top--;
        }
    }
    return 1;
}

int main(){
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        char s[101];
        memset(s, 0, 101*sizeof(char));
        scanf("%s",s);
        if(isValid(s)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }

    }

    return 0;
}
