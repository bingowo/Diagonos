#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[101]={0},t[101]={0};
        scanf("%s",s);
        int top=0,sign=0,curent=0;
        t[0]=s[0];
        for(int k=1;k<strlen(s);k++)
        {
            if(t[top]=='(') curent=1;
            else if(t[top]=='[') curent=2;
            else if(t[top]=='{') curent=3;
            else curent=0;

            t[++top]=s[k];
            if(t[top]=='('&&(curent==1||curent==3)){break;}
            else if(t[top]=='['&&(curent==2||curent==1)){break;}
            else if(t[top]=='{'&&(curent==3||curent==2)){break;}

            if(curent==1&&t[top]==')') top-=2;
            else if(curent==2&&t[top]==']') top-=2;
            else if(curent==3&&t[top]=='}') top-=2;

            if(top<-1) {break;}
        }
        if(top==-1) sign=1;
        if(sign) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}