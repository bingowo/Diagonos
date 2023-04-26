#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100001

unsigned int getnumber(char*s,int p)
{
    int len=strlen(s);
    unsigned int ans=0;
    for(int i=p+2;i<len && (isdigit(s[i]) || (s[i]>='a' && s[i]<='f'));i++)
        ans=ans*16+(isdigit(s[i])?s[i]-'0':s[i]-'a'+10);
    return ans;
}

int main()
{
    char s[max];
    scanf("%s",s);
    int len=strlen(s),flag=0,i=0;
    while(i<len)
    {
        if(s[i]=='0' && s[i+1]=='x' && (isdigit(s[i+2]) || (s[i+2]>='a' && s[i+2]<='f')))
        {
            flag=1;
            printf("%u ",getnumber(s,i));
        }
        i++;
    }
    if(flag==0) printf("-1");
    printf("\n");

    return 0;
}
