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
            if((strcmp(s,"a")!=0)&&(strcmp(s,"the")!=0)&&(strcmp(s,"of")!=0)&&(strcmp(s,"an")!=0)&&(strcmp(s,"for")!=0)&&(strcmp(s,"and")!=0)&&(strcmp(s,"A")!=0)&&(strcmp(s,"The")!=0)&&(strcmp(s,"Of")!=0)&&(strcmp(s,"An")!=0)&&(strcmp(s,"For")!=0)&&(strcmp(s,"And")!=0))
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
