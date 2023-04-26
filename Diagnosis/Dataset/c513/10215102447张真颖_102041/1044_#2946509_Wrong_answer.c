#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[100001]={0};
int main()
{
    scanf("%s",s);
    int sign=0,sign2=0;
    long long r=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='0'&&s[i+1]=='x')
        {
            sign=1;
            i+=2;
            if(sign2)
                printf("%lld ",r),r=0;
            sign2=1;
        }
        else if(i==strlen(s)-1&&sign)
        {
            if(s[i]>='0'&&s[i]<='9') r=r*16+s[i]-'0';
            else if(s[i]>='a'&&s[i]<='f')
                r=r*16+s[i]-'a'+10;
            printf("%lld\n",r);
        }
        if(sign==1)
        {
            if(s[i]>='0'&&s[i]<='9')
                r=r*16+s[i]-'0';
            else if(s[i]>='a'&&s[i]<='f')
                r=r*16+s[i]-'a'+10;
        }
    }
    if(sign==0) printf("-1");
    return 0;
}
