#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char c=getchar();
    int max=0;char out[100];int k=1;
    while(k)
    {
        int p[150]={0};
        int e=0;char s[100];
        while(p[c]==0&&k==1)
        {
            s[e++]=c;
            p[c]=1;
            if(e>max){strcpy(out,s);max=e;out[e]='\0';}
            if((c=getchar())!='\n')k=1;
            else k=0;
        }
    }
    printf("%s",out);
}
