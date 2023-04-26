#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char s[10001];
    scanf("%s",s);
    int flag=0;
    unsigned int ans=0;
    for(int i=0;i<strlen(s)-1;)
    {
        if(s[i]=='0'&& s[i+1]=='x')
        {
            i+=2;
            flag=1;
            while(s[i]>='0' && s[i]<='9')
            {
                ans=ans*16+s[i]-'0';
                i++;
            }
            while(s[i]>='a' && s[i]<='f')
            {
                ans=ans*16+s[i]-'a'+10;
                i++;
            }
            printf("%u ",ans);
            ans=0;
        }
        else
        {
            i++;
        }
    }
    if(flag==0) printf("-1\n");
    return 0;
}
