#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct{
    char string[31];
    int number;
    int count;
}STR;
int strnumcmp(const void*a,const void*b)
{
    STR*st1,*st2;
    st1 = (STR*)a,st2 = (STR*)b;
    if(st1->count != st2->count)
        return st1->count - st2->count;
    else
    {
        if(st1->number != st2->number)
            return st1->number - st2->number;
        else
            return strcmp(st1->string,st2->string);
    }
}
int main()
{
    STR input[100];
    int i = 0;
    while(scanf("%s",input[i].string) != EOF)
    {
        input[i].number = 0;
        input[i].count = 0;
        char*pt = input[i].string;
        while(!isdigit(*pt) && *pt)
            pt++;
        input[i].number = (*pt) - '0';
        input[i].count++;
        while(*pt && isdigit(*pt))
        {
            if(*(pt + 1) && isdigit(*(pt + 1)))
            {
                input[i].number = 10*input[i].number + (*(pt + 1) - '0');
                input[i].count++;
            }
            pt++;
        }
        i++;

    }
    qsort(input,i,sizeof(input[0]),strnumcmp);
    for(int j = 0;j < i;j++)
    {
        printf("%s ",input[j].string);
    }

    return 0;
}
