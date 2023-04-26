#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[100000];
    scanf("%s",s);
    int a[256];
    for(int i=0;i<256;i++)
        a[i]=0;
    int len= strlen(s);
    int count=0;
    int max=0;
    int begin=0;
    int end=0;
    int flag=0;
    for(int j=0;j<len;j++)
    {
        if(a[s[j]]==0)
        {
            a[s[j]]=1;
            count++;
            if(max<count)
            {
                max=count;
            }
        }
        else
        {
            flag=1;
            if(max<=count)
            {
                end=j-1;
                begin=end-count;
            }
            for(int k=0;k<256;k++)
                a[k]=0;
            count=0;
        }
    }
    if(flag==1)
    {
        for(int x=begin;x<=end;x++)
        {
            printf("%c",s[x]);
        }
    }
    else
        printf("%s",s);
    return 0;
}