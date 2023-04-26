#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int i,n;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        char s[101],c,*p=s,*p0;
        int ans=0,j=0;
        while((c=getchar())!='\n')s[j++]=c;
        s[j++]=' ';s[j]=0;
        while(*p)
        {
            p0=p;
            while(*p!=' ')p++;
            *p=0;
            p=p0;
            while(*p)
            {
                if(*p>='A'&&*p<='Z')*p+=32;
                p++;
            }
            if(strcmp(p0,"the")&&strcmp(p0,"a")&&strcmp(p0,"an")&&strcmp(p0,"of")&&strcmp(p0,"for")&&strcmp(p0,"and"))ans++;
            while(*(++p)==' '&&*p);
        }
        printf("case #%d:\n%d\n",i,ans);
    }
    return 0;
}
