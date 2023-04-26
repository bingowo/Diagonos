#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char c;
    char S1[1001];
    char S2[1001];
    c=getchar();
    c=toupper(c);
    S1[0]=c;
    S2[0]=c;
    int i=1;
    while((c=getchar())!=EOF)
    {
        c=toupper(c);
        if(c>=S1[0])
        {
            strcpy(S2,S1);
            for(int j=0;j++;j<1001)
            {
                S1[j]='\0';
            }
            i++;
            S1[0]=c;
            strcat(S1,S2);
        }
        else
        {
            S1[i]=c;
            i++;
        }
    }
    printf("%s",S1);
}
