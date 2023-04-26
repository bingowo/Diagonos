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
    for(int i=0;i<len;i++)
    {
        if(s[i]>='1'&&s[i]<='9')
            num++;
        else
            num=0;
        if(max<num)
            max=num;
    }
    printf("%d",max);
}