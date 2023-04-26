#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[51];
    scanf("%s",s);
    int len= strlen(s);
    int num=0;
    int max=0;
    for(int i=0;i<len-1;i++)
    {
        if(s[i]=='|'&&s[i+1]=='-')
            num++;
        else if(s[i]=='-'&&s[i+1]=='|')
            num++;
        else
            num=0;
        if(max<num)
            max=num;
    }
    printf("%d",max+1);
}
