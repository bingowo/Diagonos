#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void solveint(int n)
{
    unsigned char* p = (unsigned char*)&n;
    for (int i = 0;i<4;i++)
    {
        printf("%02x ",*p++);
    }

}

void solvedouble(double f)
{
    unsigned char* p = (unsigned char*)&f;
    for(int i = 0;i<8;i++)
    {
        printf("%02x ",*p++);
    }
}

int main()
{
    char s[100];memset(s,0,100*sizeof(char));
    while(scanf("%s",s)!=EOF)
    {
        if(strchr(s,'.')==0)
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
