#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char c;
    char S1[2001];
    char S2[2001];
    c=getchar();
    c=toupper(c);
    S1[0]=c;
    S2[0]=c;
    int i=1;
    while(c!=EOF)
    {
        c=getchar();
        c=toupper(c);
        if(c>=S1[0])
        {
            for(int j=0;j<i;j++)
            {
                S2[j]=S1[j];
            }
            S1[0]=c;
            for(int j=1;j<i+1;j++)
            {
                S1[j]=S2[j-1];
            }
            i++;

        }
        else
        {
            S1[i]=c;
            i++;
        }

    }
    printf("%s",S1);
}
