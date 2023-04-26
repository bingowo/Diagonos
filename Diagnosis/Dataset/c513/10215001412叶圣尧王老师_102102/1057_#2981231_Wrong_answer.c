#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void val(char c)
{
    if(c>='a'&&c<='z')printf("%c",c-32);
    else putchar(c);
}

int main()
{
    char w[1001];scanf("%s",w);char head[1001],tail[1001];
    int j=0,k=0;head[0]=w[0];
    for(int i=1;i<strlen(w);i++)
    {
        if(w[i]>=head[k])head[++k]=w[i];
        else tail[j++]=w[i];
    }
    for(int i=k;i>=0;i--)
        val(head[i]);
    for(int i=0;i<j;i++)
        val(tail[j]);
}