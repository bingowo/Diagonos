#include <stdio.h>
#include <stdlib.h>

#define out 0
#define parenthese 3
#define bracket 2
#define brace 1

int main()
{
    short T=0;
    scanf("%hd",&T);
    for(int i=0;i<T;i++)
    {
        char *sequence;
        short state=out,iselegant=1,len=0;
        sequence=(char*)malloc(101);
        sequence=fgets(sequence,105,stdin);
        if(!sequence) printf("error");
        len=strlen(sequence)-1;
        for(int j=0;j<len;j++)
        {
            switch(*(sequence+j));
            {
                case '(':
                    if(state==brace||state==parenthese) iselegant=0;
                    else state=parenthese;
                    break;
                case '[':
                    if(state==parenthese||state==bracket) iselegant=0;
                    else state=bracket;
                    break;
                case '{':
                    if(state==brace||state==parenthese) iselegant=0;
                    else state=parenthese;
            }
        }
    }
}
