#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char c=getchar();
    int max=0;char out[100];
    while(c!='\n'||c!=EOF)
    {
        int p[150]={0};
        int k=0,e=0;char s[100];
        while(p[c]==0&&c!='\n')
        {
            s[e++]=c;
            p[c]=1;
            if(e>max){strcpy(out,s);max=k;out[e]='\0';}
            c=getchar();
        }
    }
    printf("%s",out);
}