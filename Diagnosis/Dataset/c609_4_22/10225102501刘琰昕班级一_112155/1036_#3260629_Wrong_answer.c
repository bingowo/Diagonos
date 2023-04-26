#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int stack[200];
int *top=stack;

int main()
{
    char c;
    while((c=getchar())!='\n')
    {
        if(c=='(')
           {
                *top++=-1;
           }
        else if(c==')')
        {

            if(*--top==-1)
            {
                *top++=1;
            }
            else
            {
                int temp=*top;
                while(*--top!=-1)
                    temp+=*top;
                *top++=2*temp;
            }
        }
    }
    printf("%d",stack[0]);
    return 0;
}
