#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define outer 0//外层状态
#define paren 1//小括号状态
#define brack 2//中括号状态
#define brace 3//大括号状态
#define filled_brack 4//表示中括号已经填充过
#define filled_brace 5//表示大括号已经填充过4

int judge(char *str){//注意："[]"和”{}“是不合法的括号对
    int len=strlen(str),states[101],top=0;
    states[top]=outer;
    for(int i=0;i<len;i++){
        int state=states[top];
        char ch=str[i];
        if(state==outer){
            if(ch=='('){states[++top]=paren;continue;}
            if(ch=='['){states[++top]=brack;continue;}
            if(ch=='{'){states[++top]=brace;continue;}
            else return 0;
        }
        if(state==paren){
            if(ch=='{'){states[++top]=brace;continue;}
            if(ch==')'){top--;
                if(states[top]==outer)continue;
                states[top]=filled_brack;
                continue;}
            else return 0;
        }
        if(state==brack||state==filled_brack){
            if(ch=='('){states[++top]=paren;continue;}
            if(ch==']'){
                if(state==brack)return 0;
                top--;
                if(states[top]==outer)continue;
                states[top]=filled_brace;
                continue;}
            else return 0;
        }
        if(state==brace||state==filled_brace){
            if(ch=='['){states[++top]=brack;continue;}
            if(ch=='}'){
                if(state==brace)return 0;
                top--;continue;}
            else return 0;
        }
    }
    return states[top]==outer;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char str[101]={0};
        scanf("%s",str);
        printf(judge(str)?"Yes\n":"No\n");
    }
    return 0;
}