#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[1000001];
    scanf("%s",&s);
    int i,len;
    int m[128];
    for(i=0;i<128;i++) m[i]=-1;
    int t=0;
    int start;
    for(i=0;i<strlen(s);i++)
    {
        if(m[s[i]]>=t)
        {
            t=m[s[i]]+1;
            m[s[i]]=i;
        }
        else
        {
             m[s[i]]=i;
            if(len<i-t+1)
            {
                start=t;
                len=i-t+1;
            }
        }
    }
    for(int j=0;j<len;j++)
        printf("%c",s[start+j]);
    printf("\n");
}
