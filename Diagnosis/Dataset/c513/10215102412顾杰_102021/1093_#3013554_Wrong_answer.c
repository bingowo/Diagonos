#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"

int main()
{
    char s[102];
    s[0]='0';
    scanf("%s",s+1);
    int l=strlen(s);
    while(1)
    {
        s[l-1]++;
        int carry=0;
        for(int i=l-1;i>=0;i--){s[i]+=carry;if(s[i]>='9'){s[i]-=9;carry=1;}else carry=0;}
        int sum=0;
        for(int i=0;i<l;i++)sum+=s[i]-'0';
        if(sum%9!=0)break;
    }
    if(s[0]=='0')printf("%s",s+1);
    else printf("%s",s);
}
