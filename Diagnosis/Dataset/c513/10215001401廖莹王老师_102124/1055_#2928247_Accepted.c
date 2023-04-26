#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[1000000];char c;
    scanf("%s",s);
    int start=0,len=0;
    int i=0,t=0;
    int m[128];
    for(i=0;i<128;i++)m[i]=-1;
    for(i=0;s[i];i++)
    {
        c=s[i];
        if(m[c]<t)
        {
            m[c]=i;
            if(len<i-t+1){start=t;len=i-t+1;}
        }
        else {t=m[c]+1;m[c]=i;}
    }
    for(i=0;i<len;i++)printf("%c",s[i+start]);
    return 0;
}
