#include <stdio.h>
int main()
{
    char s[101];
    int res=0,tem=0;
    scanf("%s",s);
    int begin=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(begin=0 && s[i]>'0' && s[i]<='9') begin=1;
        else if(s[i]>='0' && s[i]<='9' && begin==1) tem++;
        else if(begin==1 && (s[i]<='0'||s[i]>='9')){begin=0;res=res>tem?res:tem;}
    }
    res=res>tem?res:tem;
    printf("%d",res);
    return 0;
}