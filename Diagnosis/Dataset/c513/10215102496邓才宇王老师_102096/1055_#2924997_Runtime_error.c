#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000001];
    gets(s);
    int i,len;
    int m[128];
    for(i=0;i<128;i++) m[i]=-1;
    int t=0;
    int start;
    char c;
    for(i=0;i<strlen(s);i++)
    {
        c=s[i];
        if(m[c]>=t)
        {
            t=m[c]+1;
            m[c]=i;
        }
        else
        {
             m[c]=i;
            if(len<i-t+1)
            {
                start=t;
                len=i-t+1;
            }
        }
    }
    for(int j=0;j<len;j++)
        printf("%c",s[start+j]);
}
