#include <string.h>

int main()
{
    int T,i,flag;
    scanf("%d",&T);
    char s[105],stk[105];
    while(T--)
    {
        memset(s,0,sizeof(char));
        memset(stk,0,sizeof(char));
        flag=0;
        scanf("%s",s);
        int len=0;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='(')
            {
                //printf("%s\n",stk);
                if(stk[len-1]=='['||strlen(stk)==0)
                {
                    stk[len++]=s[i];
                }
                else{flag=1;break;}
            }
            if(s[i]=='[')
            {
                //printf("%s\n",stk);
                if(stk[len-1]=='{'||strlen(stk)==0)
                {
                    stk[len++]=s[i];
                }
                else{flag=1;break;}
            }
            if(s[i]=='{')
            {
                //printf("%s\n",stk);
                if(stk[len-1]=='('||strlen(stk)==0)
                {
                    stk[len++]=s[i];
                }
                else{flag=1;break;}
            }
            if(s[i]==')')
            {
                //printf("%s\n",stk);
                if(stk[len-1]=='(')
                {
                    stk[--len]='\0';
                }
                else{flag=1;break;}
            }
            if(s[i]==']')
            {
                //printf("%s\n",stk);
                if(stk[len-1]=='[')
                {
                    stk[--len]='\0';
                }
                else{flag=1;break;}
            }
            if(s[i]=='}')
            {
                //printf("%s\n",stk);
                if(stk[len-1]=='{')
                {
                    stk[--len]='\0';
                }
                else{flag=1;break;}
            }
        }
        if(flag==0 && strlen(stk)==0)
        {
            printf("%c%c%c\n",'Y','e','s');
        }
        else{printf("%c%c\n",'N','o');}
    }