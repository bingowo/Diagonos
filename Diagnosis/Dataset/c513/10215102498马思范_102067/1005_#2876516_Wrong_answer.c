#include <stdio.h>
#include <string.h>
void main(void)
{
    int i,len,d;
    char str[20],str1[20],str2[50]={"0.0"};
    long a=0,b=1,c;
    scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len-1;i++)
        str1[i]=str[i+2];
    len=strlen(str1);
    for(i=len-1;i>=0;i--)
    {
        a+=(str1[i]-'0')*b;
        b=b*8;
    }
    c=a%b;
    for(i=0;i<3*len;i++)
    {
        c *= 10;
        d=c/b;
        str2[2+i]=d+0x30;
        c=c%b;
    }
    str2[len*3+2]='\0';
    len=strlen(str2);
    for(i=len-1;i>2;i--)
        if(str2[i]=='0') str2[i]='\0';
        else break;
    printf("%s[8] = %s[10]\n",str,str2);
}