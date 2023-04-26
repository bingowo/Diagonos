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
        int flag2=0;
        for(int j=0;j<l&&flag2==0;j++)
        {
            if(s[j]=='{'||s[j]=='['||s[j]=='('){stack[cnt++]=s[j];}
            else if(s[j]==')'&&stack[cnt-1]=='('&&flag==0){cnt--;flag=0;}
            else if(s[j]==']'&&stack[cnt-1]=='['&&flag==0){cnt--;flag=1;}
            else if(s[j]=='}'&&stack[cnt-1]=='{'&&flag==1){cnt--;flag=0;}
            else flag2=1;
        }
        if(cnt==0&&flag2==0)printf("Yes\n");
        else printf("No\n");


    }




}
