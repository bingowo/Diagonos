#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solveint(int n);
void solvedouble(double d);
int main()
{
    char s[31];
    while(scanf("%s",s) != EOF)
    {
        if(strchr(s,'.') == 0)
        {
            solveint(atoi(s));
        }
        else
        {
            solvedouble(atof(s));
        }
    }
    
    
    
    return 0;
}

void solveint(int n);
{
    int c = sizeof(n);
    unsigned char* p = (unsigned char*)&n;
    while(c--)
    
    
}