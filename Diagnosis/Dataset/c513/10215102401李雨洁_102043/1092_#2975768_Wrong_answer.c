#include <stdio.h>
#include <string.h>

#define Magic 1000000007

int main()
{
    char w[1000];
    scanf("%s",w);
    int end = 1;
    if(strlen(w) == 1) end = 1;
    else if(strlen(w) == 2)
    {
        if(w[0] == w[1]) end = 1;
        else end = 4;
    }
    else
    {
        if(w[0] != w[1]) end = 2;
        for(int i = 1; i < strlen(w)-1; i++)
        {
            int c = 1;
            if(w[i] != w[i-1]) c = 2;
            if(w[i] != w[i+1]) c = 2;
            if(w[i] != w[i+1] && w[i-1] != w[i+1] && w[i] != w[i-1]) c = 3;
            end = (end * c) % Magic;
        }
        if(w[strlen(w)-1] != w[strlen(w)-2])
            end = (end * 2) % Magic;
    }
    printf("%d",end);
    return 0;
}

