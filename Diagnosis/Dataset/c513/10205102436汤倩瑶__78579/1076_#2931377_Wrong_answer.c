#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    char s[105];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        int l=strlen(s);
        char stack[105]={0};
        int cnt=0;
        int flag=0;
        for(int j=0;(j<l)&&(flag==0);j++)
        {
           if(s[j]=='{'||s[j]=='['||s[j]=='('){stack[cnt++]=s[j];}
           if(s[j]==')'&&stack[cnt-1]=='('){
            if(cnt>=2&&stack[cnt-2]=='['){cnt--;}
            else if(cnt==1){cnt--;}
            else flag=1;
           }
           if(s[j]==']'&&stack[cnt-1]=='['){
            if(cnt>=2&&stack[cnt-2]=='{'){cnt--;}
            else if(cnt==1){cnt--;}
            else flag=1;
           }
           if(s[j]=='}'&&stack[cnt-1]=='{'){
            if(cnt>=2&&stack[cnt-2]=='('){cnt--;}
            else if(cnt==1){cnt--;}
            else flag=1;
           }

           }
        if(cnt==0&&flag==0)printf("Yes\n");
        else printf("No\n");
    }
}
