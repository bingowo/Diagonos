#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[50];
    scanf("%s",s);
    int len=strlen(s);int i=0;long long int a=0,b=0;
    for(;isdigit(s[i])&&i<len;i++)
    {
        a=a*10+(s[i]-'0');
    }
    if(i<len)
    {
        int c=1;
        if(s[i]=='-') c=-1;
        i++;
        if(s[i]=='i') b=1;
        for(;s[i]!='i';i++)
        {
            b=b*10+(s[i]-'0');
        }
        b=c*b;
    }
    else b=0;
    long long int qr=a,qi=b;
    int answer[4]={0};
    for(int j=3;j>=0;j--)
    {
        answer[j]=(qr+qi)%2;
        qr=b-a;qi=-a-b;a=qr;b=qi;
    }
    for(int j=0;j<4;j++)
    {
        printf("%d",answer[j]);
    }
    return 0;
}
