#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    int T;
    int i, j, k;
    int n = 0;
    int L;
    char c;
    char s[];
    char the[]="the";
    char a[]="a";
    char an[]="an";
    char fr[]="for";
    char of[]="of";
    char ad[]="and";
    scanf("%d", &T);
    c = getchar();
    for (i = 0; i < T; i++)
    {
        scanf("%s", s);
        L=strlen(s);
        for(j=0;j<L;j++)
            {s[j] = tolower(s[j]);}
        n = 0;
        while ((c = getchar()) != '\n')
        {
            if (strcmp(s, the) == 0)
            {
                ;
            }
            else if (strcmp(s, a) == 0)
            {
                ;
            }
            else if (strcmp(s, an) == 0)
            {
                ;
            }
            else if (strcmp(s, of) == 0)
            {
                ;
            }
            else if (strcmp(s, ad) == 0)
            {
                ;
            }
            else if (strcmp(s, fr) == 0)
            {
                ;
            }
            else
            {
                n++;
            }
            scanf("%s", s);
            L=strlen(s);
            for(j=0;j<L;j++)
                {s[j] = tolower(s[j]);}
        }
        if (strcmp(s, the) == 0)
        {
            ;
        }
        else if (strcmp(s, a) == 0)
        {
            ;
        }
        else if (strcmp(s, an) == 0)
        {
            ;
        }
        else if (strcmp(s, of) == 0)
        {
            ;
        }
        else if (strcmp(s, ad) == 0)
        {
            ;
        }
        else if (strcmp(s, fr) == 0)
        {
            ;
        }
        else
        {
            n++;
        }
        printf("case #%d:\n", i);
        printf("%d\n", n);
    }
    return 0;
}