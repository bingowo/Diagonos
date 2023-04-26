#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef long long lli;

lli ret(char c)
{
    switch(c)
    {
        case 'I':
        return 1;
        case 'V':
        return 5;
        case 'X':
        return 10;
        case 'L':
        return 50;
        case 'C':
        return 100;
        case 'D':
        return 500;
        case 'M':
        return 1000;
    }

}

int main()
{
    char s[60];lli num[60];int index=0;lli multi=1;
    scanf("%s",s);
    for(int i=0; i<strlen(s); i++)
    {
       if(isalpha(s[i]))
       num[index++] = ret(s[i])*multi;
       else if (s[i]=='(') multi*=1000;
       else if (s[i]==')') multi/=1000;
    }
    
    lli res=0;
    for(int i=0; i<index; i++)
    {
        if(i==index-1) res+=num[i];
        else if(num[i] < num[i+1]) res-=num[i];
        else res+=num[i];
    }
    printf("%lld",res);
}