#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char a;
        int count=0;
        char s[20];
        while((a=getchar())!=10)
        {
            if(a!=32)
                ungetc(a,stdin);
            scanf("%s",&s);
            for(int j=0;j<strlen(s);j++)
            {
                if(s[j]<'a')
                    s[j]=s[j]-'A'+'a';
            }
            if((strcmp(s,"a")!=0)&&(strcmp(s,"the")!=0)&&(strcmp(s,"of")!=0)&&(strcmp(s,"an")!=0)&&(strcmp(s,"for")!=0)&&(strcmp(s,"and")!=0))
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
