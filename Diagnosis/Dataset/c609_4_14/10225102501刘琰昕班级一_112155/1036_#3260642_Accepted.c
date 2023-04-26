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
    int ans=0;
    for(top--;top!=stack-1;top--)
        ans+=*top;
    printf("%d",ans);
    return 0;
}
