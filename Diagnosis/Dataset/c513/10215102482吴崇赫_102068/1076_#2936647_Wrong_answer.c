#include<stdio.h>
#include<string.h>
#define N 105

int solve(char* s)
{
    int ans=1;
    int n=strlen(s);
    for(int i=0;i<n-1;++i){
        if(s[i]=='{'){
            if(s[i+1]=='['||s[i+1]=='}')ans=1;
            else return 0;
        }
        if(s[i]=='['){
            if(s[i+1]=='('||s[i+1]==']')ans=1;
            else return 0;
        }
        if(s[i]=='('){
            if(s[i+1]==')'||s[i+1]=='{')ans=1;
            else return 0;
        }
        if(s[i]=='}'){
            if(s[i+1]==')'||s[i+1]=='{'||s[i+1]=='['||s[i+1]=='(')ans=1;
            else return 0;
        }
        if(s[i]==']'){
            if(s[i+1]=='}'||s[i+1]=='{'||s[i+1]=='['||s[i+1]=='(')ans=1;
            else return 0;
        }
        if(s[i]==')'){
            if(s[i+1]==']'||s[i+1]=='{'||s[i+1]=='['||s[i+1]=='(')ans=1;
            else return 0;
        }
    }
    return ans;
}

int main()
{
    int T;scanf("%d\n",&T);
    while(T--){
        char s[N];
        memset(s,0,sizeof(s[0]));
        scanf("%s",s);
        if(solve(s))printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
