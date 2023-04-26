#include <stdio.h>
/*1、大括号{}的下一层一定是若干个中括号[]组成的括号序列，如{[…][…]}或{[…]}

2、中括号[]的下一层一定是若干个小括号()组成的括号序列，如 [(…)]或[(…)(…)]

3、小括号()的下一层一定是若干个大括号{}组成的括号序列或者为空，如 ({…}{…})或({…})或()

4、最外层可由不同类型的括号组成括号序列，如 (…)[…]{…}或(…)(…)*/
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        char s[101];
        char L[100];
        scanf("%s",s);
        int curent=0,top=0,res=1;
        L[0]=s[0];
        for(int k=1;s[k]!='\0';k++)
        {
        	L[++top]=s[k];
            if(L[top-1]=='(') curent=1;
            else if(L[top-1]=='[') curent=2;
            else if(L[top-1]=='{') curent=3;
            else curent=0;
            if(L[top]=='(' && (curent==1 || curent==3)) {res=0;break;}//current=1说明'('前是'(',current=3说明'('前是'{'
            else if(L[top]=='[' &&(curent==2 || curent==1)){res=0;break;}
            else if(L[top]=='{' &&(curent==3 || curent==2)){res=0;break;}
            
            if(L[top]==')' && L[top-1]=='(') top-=2;
            else if(L[top]==']' && L[top-1]=='[') top-=2;
            else if(L[top]=='}' && L[top-1]=='{') top-=2;
            
            if(top!=-1) {res=0;break;}
        }
        if(res==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}