#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    void zero(int *a,int l);
    char s[100000];
    int a[128]={0};
    gets(s);
    int l=strlen(s);
    int i,st,end,len;
    int max=0;
    for(i=0;i<l;i++)
    {
        int j;
        int count=0;
        for(j=i;j<l&&a[s[j]]==0;)
        {
            count++;
            a[s[j]]++;
            j++;
        }

        if(count>max)
        {
            st=i;
            len=count;
            max=count;
        }
        zero(a,128);
    }

    for(int k=st;k<st+len;k++)
        {printf("%c",s[k]);}


    return 0;
}


void zero(int *a,int l)
{
    for(int i=0;i<l;i++)
        *(a+i)=0;
}
