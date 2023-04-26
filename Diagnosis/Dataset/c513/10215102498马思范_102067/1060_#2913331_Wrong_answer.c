#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[101];
    scanf("%s",s);
    int len= strlen(s);
    int num=0;
    int max=0;
    if(s[0]>='1'&&s[0]<='9')
        num++;
    for(int i=1;i<len;i++)
    {
        if(s[i]=='0'&&s[i-1]>='1'&&s[i-1]<='9')
            num++;
        else if(s[i]>='1'&&s[i]<='9')
            num++;
        else
            num=0;
        if(max<num)
            max=num;
    }
    printf("%d",max);
}