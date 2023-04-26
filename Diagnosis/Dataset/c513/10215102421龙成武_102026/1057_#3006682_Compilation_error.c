#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int len,i,p,q;
    char w[1001],ans[3000]={0},a,b;
    scanf("%s",w);
    len=strlen(w);
    ans[1500]=w[0];
    p=q=1500;
    for(i=1;i<len;i++)
    {
        a=ans[p];
        b=w[i];
        if(stricmp(&a,&b)<=0)
        {
            p--;
            ans[p]=w[i];
        }
        else
        {
            q++;
            ans[q]=w[i];
        }
    }
    for(i=p;i<=q;i++)
    {
        printf("%c",ans[i]);
    }
    return 0;
}
