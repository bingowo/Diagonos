#include <stdio.h>
#include <string.h>

int main()
{
    char F[4];
    char M[4];
    char C[4];
    scanf("%s %s %s",F,M,C);
    if(C[0]=='?')
    {
        if(F[0]=='O'&&M[0]=='O')
            printf("%s %s O",F,M);
        else if(F[0]=='A'&&M[0]=='O'||F[0]=='O'&&M[0]=='A')
        {
            printf("%s %s ",F,M);
            printf("{A,O}");
        }
        else if(F[0]=='A'&&M[0]=='B'&&M[1]||F[0]=='B'&&M[0]=='A'&&F[1])
        {
            printf("%s %s ",F,M);
            printf("{A,B,O,AB}");
        }
        else if(F[0]=='A'&&M[0]=='A'||F[0]=='A'&&M[0]=='A')
        {
            printf("%s %s ",F,M);
            printf("{A,O}");
        }
        else
        {
            printf("%s %s ",F,M);
            printf("{A,B,AB}");
        }
    }
    else
    {
        if(F[0]='?')
        {
            if(C[0]=='O')
            {
                if(M[0]=='O')
                {
                    printf("O %s %s",M,C);
                }
                else if(M[0]=='B')
                {
                    printf("{A,B,O} %s %s",M,C);
                }
                else if(M[0]=='A'&&M[1]=='B')
                {
                    printf("impossible %s %s",M,C);
                }
                else
                {
                    printf("{A,B,O} %s %s",M,C);
                }

            }
            else if(C[0]=='B')
            {
                if(M[0]=='O')
                {
                    printf("{A,B,O} %s %s",M,C);
                }
                else if(M[0]=='B')
                {
                    printf("{A,B,O,AB} %s %s",M,C);
                }
                else if(M[0]=='A'&&M[1]=='B')
                {
                    printf("{A,B,O,AB} %s %s",M,C);
                }
                else
                {
                    printf("{B,AB} %s %s",M,C);
                }
            }
            else if(C[0]=='A'&&C[1]=='B')
            {
                if(M[0]=='O')
                {
                    printf("impossible %s %s",M,C);
                }
                else if(M[0]=='B')
                {
                    printf("{A,AB} %s %s",M,C);
                }
                else if(M[0]=='A'&&M[1]=='B')
                {
                    printf("{A,B,AB} %s %s",M,C);
                }
                else
                {
                    printf("{B,AB} %s %s",M,C);
                }
            }
            else
            {
                if(M[0]=='O')
                {
                    printf("{A,AB} %s %s",M,C);
                }
                else if(M[0]=='B')
                {
                    printf("{A,AB} %s %s",M,C);
                }
                else if(M[0]=='A'&&M[1]=='B')
                {
                    printf("{A,B,O,AB} %s %s",M,C);
                }
                else
                {
                    printf("{A,B,O,AB} %s %s",M,C);
                }
            }

        }
    }
}
