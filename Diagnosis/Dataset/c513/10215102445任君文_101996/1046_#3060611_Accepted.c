#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    int T;
    int i, j;
    int n = 0;
    int L;
    char c;
    char s[100];
    char the[]="the";
    char a[]="a";
    char an[]="an";
    char fr[]="for";
    char of[]="of";
    char ad[]="and";
    scanf("%d", &T);
    c =getchar();
    for (i = 0; i < T; i++)
    {
        n = 0;
        do
        {
            scanf("%s", s);
            c=getchar();
            L=strlen(s);
            for(j=0;j<L;j++)
            {
                s[j] = tolower(s[j]);
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
        }while(c!='\n');
        printf("case #%d:\n", i);
        printf("%d\n", n);
    }
    return 0;
}