#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[5];

void solve(char *str)
{
    if(!strlen(str))return;
    else if(str[0]=='I'){
        a[str[3]-'A']=atoi(str+6);
    }
    else if(str[0]=='M'&&str[1]=='O'){
        a[str[4]-'A']=a[str[7]-'A'];
    }
    else if(str[0]=='A'){
        a[str[4]-'A']+=a[str[7]-'A'];
    }
    else if(str[0]=='S'){
        a[str[4]-'A']-=a[str[7]-'A'];
    }
    else if(str[0]=='M'&str[1]=='U'){
        a[str[4]-'A']*=a[str[7]-'A'];
    }
    else if(str[0]=='D'){
        a[str[4]-'A']/=a[str[7]-'A'];
    }
    else printf("%d\n",a[str[4]-'A']);
}

int main()
{
    char str[50];
    while(gets(str))
    {
        solve(str);
    }
    return 0;
}