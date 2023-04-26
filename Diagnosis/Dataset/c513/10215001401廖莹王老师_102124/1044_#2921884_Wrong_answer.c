#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    long long  a;
}result;
int main()
{
    char s[100000];
    result number[10000];
    scanf("%s",s);
    int i,r=-1;
    for(i=0;s[i];i++)
    {
        if(s[i]=='0' && s[i+1] && s[i+1]=='x')
        {
            number[i].a=0;
             if( (s[i+2]>='0' && s[i+2]<='9' && s[i+2]) ||(s[i+2]>='a' && s[i+2]<='f' && s[i+2]) )r++;
            for(i=i+2;s[i];i++)
            {
                if(s[i]>='0' && s[i]<='9'){number[r].a=number[r].a*16+(s[i]-'0');}
                else if(s[i]>='a' && s[i]<='f'){number[r].a=number[r].a*16+(s[i]-'a'+10);}
                else break;
            }
        }

    }
    if(r==-1)printf("%d",r);
    else {for(i=0;i<r+1;i++)printf("%lld ",number[i].a);}
    return 0;
}
