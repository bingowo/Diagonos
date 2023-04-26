#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int state=0;
int da,zhong,xiao=0;
int check_state(char x)
{
   if(state==1){
        if(x=='['||x=='}');
   else return 1;}
   if(state==2){
        if(x=='('||x==']');
   else return 1;}
   if(state==3){
        if(x=='{'||x==')');
   else return 1;}
   return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    char s[105];
    while(n--)
    {
        state=0;
        da=0;
        zhong=0;
        xiao=0;
        scanf("%s",s);
        int len=strlen(s);
        int pre_state;
        int flag=1;
        for(int i=0;i<len;i++)
        {
            if(check_state(s[i]))
                {
                    flag=0;
                    break;
                }
            if (s[i]=='{')
                {state=1;da++;}
            else if(s[i]=='[')
                {state=2;zhong++;}
            else if(s[i]=='(')
                {state=3;xiao++;}
            else if (s[i]=='}')
                {state=0;da--;}
            else if(s[i]==']')
                {state=1;zhong--;}
            else if(s[i]==')')
                {state=2;xiao--;}

        }
        printf("%d %d %d ",da,zhong,xiao);
        if(s[len-1]!='}'&&s[len-1]!=']'&&s[len-1]!=')')
            flag=0;
        if (flag&&(!da)&&(!zhong)&&(!xiao))
            printf("Yes\n");
        else
        printf("No\n");
    }
}