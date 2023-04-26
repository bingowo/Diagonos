#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[101]={0};
    scanf("%s",s);
    int len=0,tlen=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(tlen==0&&s[i]=='0') ;
            else tlen+=1;
        }
        else
        {
            len=len>tlen?len:tlen;
            tlen=0;
        }
        if(i+1==strlen(s))
            len=len>tlen?len:tlen;
    }
    printf("%d",len);
    return 0;
}