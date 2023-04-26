#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int start=0,lenth=0;
    char s[100000];
    scanf("%s",s);
    int i=0,k=0;
    int s1[128];
    for(i=0;i<128;i++)
        s1[i]=-1;
    for(i=0;s[i];i++)
    {
        if(s1[s[i]]>=k)
        {
            k=s1[s[i]]+1;
            s1[s[i]]=i;
        }
        else
        {
            s1[s[i]]=i;
            if(lenth<(i-k+1))
            {
                lenth=i-k+1;
                start=k;
            }
        }
    }
    for(i=0;i<lenth;i++)
        printf("%c",s[start+i]);
    printf("\0");
}