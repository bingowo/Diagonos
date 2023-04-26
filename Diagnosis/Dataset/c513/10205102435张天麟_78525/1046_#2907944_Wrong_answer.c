#include<stdio.h>
#include<string.h>
int main()
{
    int T,n;
    char c;
    scanf("%d",&T);
    scanf("%c",&c);
    for(n=0;n<T;n++)
    {
        char s[101];
        int i=0,num=0;
        scanf("%c",&c);
        while(c!='\n')
        {
            if(c!=' ')
            {
                s[i]=c;
                i++;
            }
            else
            {
                s[i]='\0';
                i=0;
                if(strcmp(s,"the")*strcmp(s,"a")*strcmp(s,"an")*strcmp(s,"of")*strcmp(s,"for")*strcmp(s,"and")!=0)num++;
            }
            scanf("%c",&c);
        }
        printf("case #%d:\n%d\n",n,num);
    }
    return 0;
}