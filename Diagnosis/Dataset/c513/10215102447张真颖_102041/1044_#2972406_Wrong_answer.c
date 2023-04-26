#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[100001]={0};
int main()
{
    scanf("%s",s);
    int i=0,state=0,sign=0;
    long long r=0;
    while(i<strlen(s))
    {
        switch(state){
        case 0:
        {
            if(s[i]=='0') state=1,i++;
            else i++;
            break;
        }
        case 1:
        {
            if(s[i]=='x') state=2,i++;
            else if(s[i]=='0') state=1,i++;
            else i++,state=0;
            break;
        }
        case 2:
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                r=r*16+s[i]-'0',i++,sign=1;
                if(i==strlen(s)) printf("%lld",r);
            }
            else if(s[i]>='a'&&s[i]<='f')
            {
                r=r*16+s[i]-'a'+10,i++,sign=1;
                if(i==strlen(s)) printf("%lld",r);
            }
            else printf("%lld%c",r,' '),r=0,i++,state=0;
            break;

        }
    }
    }
    if(sign==0) printf("-1");
    return 0;
}