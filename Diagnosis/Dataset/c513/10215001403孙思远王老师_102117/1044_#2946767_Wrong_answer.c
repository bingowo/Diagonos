#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int all;
    int x,i,len,flag;
    char s[100000];
    scanf("%s",s);
    len=strlen(s);
    for(i=1;i<len;i++)
    {
        all=0;
        if(s[i]=='x'&&s[i-1]=='0')
        {
            i++;
            flag=1;
            while((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f'))
            {
                if(s[i]>='0'&&s[i]<='9')
                    x=s[i]-'0';
                else
                    x=s[i]-'a'+10;
                all=x+all*16;
                i++;
                flag=2;
            }
            if(flag==2)
                printf("%lld ",all);
            else
                printf("0 ");
        }
    }
        if(flag==0)
            printf("-1");
    return 0;
}
