#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[1000001];
    scanf("%s",s);
    int m[128]={-1};
    int start=0,len=0,t=0;
    char c;
    for(int i=0;s[i];i++)
    {
        c=s[i];
        if(m[c]>t)
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
    for(int i=0;i<len;i++)
        printf("%c",s[start+i]);
    printf("\n");
    return 0;
}
