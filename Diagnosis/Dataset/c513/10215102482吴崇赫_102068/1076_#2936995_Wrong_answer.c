#include<stdio.h>
#include<string.h>
#define N 105

int solve(char* s)
{
    int ans=1;int cnt=0;
    int n=strlen(s);
    for(int i=0;i<n;++i){
        if(s[i]=='(')cnt++;
        if(s[i]==')')cnt--;
        if(s[i]=='[')cnt+=2;
        if(s[i]==']')cnt-=2;
        if(s[i]=='{')cnt+=3;
        if(s[i]=='}')cnt-=3;
    }
    //printf("%d\n",cnt);
    if(cnt)return 0;
    cnt=0;
    for(int i=0;i<n-1;++i){
        if(s[i]=='{'){
            cnt+=3;
            if(s[i+1]=='['||s[i+1]=='}')ans=1;
            else return 0;
            //printf("%d\n",cnt);
        }
        if(s[i]=='['){
            cnt+=2;
            if(s[i+1]=='('||s[i+1]==']')ans=1;
            else return 0;
            //printf("%d\n",cnt);
        }
        if(s[i]=='('){
            cnt+=1;
            if(s[i+1]==')'||s[i+1]=='{')ans=1;
            else return 0;
            //printf("%d\n",cnt);
        }
        if(s[i]=='}'){
            cnt-=3;
            if(cnt==0&&(s[i+1]==')'||s[i+1]=='{'||s[i+1]=='['||s[i+1]=='('))ans=1;
            else if(cnt!=0&&(s[i+1]==')'||s[i+1]=='{'))ans=1;
            else return 0;

            //printf("%d\n",cnt);
        }
        if(s[i]==']'){
            cnt-=2;
            if(cnt==0&&(s[i+1]=='}'||s[i+1]=='{'||s[i+1]=='['||s[i+1]=='('))ans=1;
            else if(cnt!=0&&(s[i+1]=='}'||s[i+1]=='['))ans=1;
            else return 0;

            //printf("%d\n",cnt);
        }
        if(s[i]==')'){
                cnt-=1;
            if(cnt==0&&(s[i+1]==']'||s[i+1]=='{'||s[i+1]=='['||s[i+1]=='('))ans=1;
            else if(cnt!=0&&(s[i+1]==']'||s[i+1]=='('))ans=1;
            else return 0;

            //printf("%d\n",cnt);
        }
    }
    //printf("%d\n",cnt);
    return ans;
}

int main()
{
    int T;scanf("%d\n",&T);
    while(T--){
        char s[N];
        memset(s,0,sizeof(s[0]));
        scanf("%s",s);
        if(solve(s))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}