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
    int carry=0,f=0;
    for(int i=l-1;i>=0;i--){s[i]+=carry;if(s[i]>='9'){s[i]-=9;carry=1;for(int j=i;j<l;j++)s[j]='0';f=1;}else carry=0;}

    while(1)
    {   if(f){int sum=0;
        for(int i=0;i<l;i++)sum+=s[i]-'0';
        if(sum%9!=0)break;}
        int carry=1;
        for(int i=l-1;i>=0;i--){s[i]+=carry;if(s[i]>='9'){s[i]-=9;carry=1;}else carry=0;}
        int sum=0;
        for(int i=0;i<l;i++)sum+=s[i]-'0';
        if(sum%9!=0)break;
    }
    if(s[0]=='0')printf("%s",s+1);
    else printf("%s",s);
}
