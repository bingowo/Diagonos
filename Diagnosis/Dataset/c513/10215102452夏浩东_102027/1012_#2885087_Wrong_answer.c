#include <stdio.h>
int main()
{
    char s[50];
    long long int a=0,b=0;
    int flag=1,i=0,num=0;
    scanf("%s",s);
    if(s[0]=='-') flag=-1;
    while(s[i]!='\0')
    {
        if(s[i]<='9'&&s[i]>'0') num=num*10+s[i]-'0';
        if(i!=0 && (s[i]=='+'||s[i]=='-'))
        {
            
        }
        i++;
    }
}