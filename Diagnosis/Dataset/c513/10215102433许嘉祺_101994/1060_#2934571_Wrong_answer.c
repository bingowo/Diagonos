#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int main()
{
    char s[101];
    gets(s);
    int len=0;
    int max=0;
    for (int i=0;i<strlen(s);i++){
        while((s[i]>'9'||s[i]<'0')&&i<strlen(s)) i++;
        while(s[i]=='0')i++;
        if (s[i]<='9'&&s[i]>='0') while(s[i]<'9'&&s[i]>'0') {len++;i++;}
        if (len>max)max=len;
        len=0;
    }
    printf("%d\n",max);
    return 0;
}
