#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int start=0,lenth=0;
    char s[100000];
    int s1[128];
    scanf("%s",s);
    int i=0,k,j,p;
    for(0;p<128;p++)s1[p]=-1;
    for(k=0,j=0;s[j];)
    {
        for(i=k;s[i];i++)
        {
            if(s1[s[i]]<k)
            {
                s1[s[i]]=i;
                if(lenth<(i-k+1))
                {
                    lenth=i-k+1;
                    start=k;
                }
                j=i+1;
            }
            else
            {
                k=s1[s[i]]+1;
                j=k;
        break;
            }
        }
    }
    for(i=0;i<lenth;i++)
        printf("%c",s[start+i]);
    printf("\0");
}