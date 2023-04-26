#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char s[1000000];gets(s);
    int i,j,p=0,max=0;
    int len=strlen(s),start=0;
    for(i=0;i<len;)
    {
        int p[150]={0};
        int k=0;
        while(p[s[i]]==0)
        {
            p[s[i]]=1;
            k++;
            if(k>max){p=i;max=k;}
            i++;
        }
    }
    for(i=p-max;i<p;i++)
        printf("%c",s[i]);
}