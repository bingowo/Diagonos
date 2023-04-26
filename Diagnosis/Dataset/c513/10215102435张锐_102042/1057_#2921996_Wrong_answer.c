#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[2000]={'0'};
    char c;int i=1000,j=1000;//i记录前面，j记录后面
    c=getchar();
    if(c>'a') c=c-'a'+'A';
    s[1000]=c;
    while((c=getchar())!=EOF)
    {
        if(c>'a') c=c-'a'+'A';
        if(c>=s[i]) s[--i]=c;
        else s[++j]=c;
    }
    for(int k=i;k<=j;k++)
    {
        printf("%c",s[k]);
    }
    return 0;
}
