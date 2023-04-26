#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char s[100001];
    scanf("%s",s);
    int flag=0,sign=0;
    unsigned int ans=0;
    for(int i=0;i<strlen(s)-1;)
    {
        sign=0;
        if(s[i]=='0'&& s[i+1]=='x')
        {
            i+=2;
            while((s[i]>='0' && s[i]<='9')||(s[i]>='a' && s[i]<='f'))
            {
                if (s[i]>='0' && s[i]<='9') ans=ans*16+s[i]-'0';
                else  ans=ans*16+s[i]-'a'+10;
                i++;
                sign=1;
            }
            if(sign==1)
            {
                printf("%u ",ans);
                flag=1;
            }
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
