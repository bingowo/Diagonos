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
        if(F[0]=='O')
        {

                if(M[0]=='O')
            {
                printf("%s %s {O}",F,M);
            }
            else if(M[0]=='B')
            {
                printf("%s %s {B,O}",F,M);
            }
            else if(!strcmp(M,"AB"))
            {
                printf("%s %s {A,B}",F,M);
            }
            else
            {
                printf("%s %s {A,O}",F,M);
            }

        }
        else if(F[0]=='B')
        {
                if(M[0]=='O')
                {
                    printf("%s %s {B,O}",F,M);
                }
                else if(M[0]=='B')
                {
                    printf("%s %s {B,O}",F,M);
                }
                else if(!strcmp(M,"AB"))
                {
                    printf("%s %s {A,AB,B}",F,M);
                }
                else
                {
                    printf("%s %s {A,AB,B,O}",F,M);
                }
        }
        else if(!strcmp(F,"AB"))
        {
                if(M[0]=='O')
            {
                printf("%s %s {A,B}",F,M);
            }
            else if(M[0]=='B')
            {
                printf("%s %s {A,AB,B}",F,M);
            }
            else if(!strcmp(M,"AB"))
            {
                printf("%s %s {A,AB,B}",F,M);
            }
            else
            {
                printf("%s %s {A,AB,B}",F,M);
            }
        }
        else
        {
                if(M[0]=='O')
            {
                printf("%s %s {A,O}",F,M);
            }
            else if(M[0]=='B')
            {
                printf("%s %s {A,AB,B,O}",F,M);
            }
            else if(!strcmp(M,"AB"))
            {
                printf("%s %s {A,AB,B}",F,M);
            }
            else
            {
                printf("%s %s {A,O}",F,M);
            }
        }
    }
    else
    {
        if(F[0]=='?')
        {
            if(C[0]=='O')
            {
                if(M[0]=='O')
                {
                    printf("{A,B,O} %s %s",M,C);
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
                    printf("{AB,B} %s %s",M,C);
                }
                else if(M[0]=='B')
                {
                    printf("{A,AB,B,O} %s %s",M,C);
                }
                else if(M[0]=='A'&&M[1]=='B')
                {
                    printf("{A,AB,B,O} %s %s",M,C);
                }
                else
                {
                    printf("{AB,B} %s %s",M,C);
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
                    printf("{A,AB,B} %s %s",M,C);
                }
                else
                {
                    printf("{AB,B} %s %s",M,C);
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
                    printf("{A,AB,B,O} %s %s",M,C);
                }
                else
                {
                    printf("{A,AB,B,O} %s %s",M,C);
                }
            }

        }
        else
        {


            if(C[0]=='O')
            {
                if(F[0]=='O')
                {
                    printf("%s {A,B,O} %s",F,C);
                }
                else if(F[0]=='B')
                {
                    printf("%s {A,B,O} %s",F,C);
                }
                else if(F[0]=='A'&&F[1]=='B')
                {
                    printf("%s impossible %s",F,C);
                }
                else
                {
                    printf("%s {A,B,O} %s",F,C);
                }

            }
            else if(C[0]=='B')
            {
                if(F[0]=='O')
                {
                    printf("%s {AB,B} %s",F,C);
                }
                else if(F[0]=='B')
                {
                    printf("%s {A,AB,B,O} %s",F,C);
                }
                else if(F[0]=='A'&&F[1]=='B')
                {
                    printf("%s {A,AB,B,O} %s",F,C);
                }
                else
                {
                    printf("%s {AB,B} %s",F,C);
                }
            }
            else if(C[0]=='A'&&C[1]=='B')
            {
                if(F[0]=='O')
                {
                    printf("%s impossible %s",F,C);
                }
                else if(F[0]=='B')
                {
                    printf("%s {A,AB} %s",F,C);
                }
                else if(F[0]=='A'&&F[1]=='B')
                {
                    printf("%s {A,AB,B} %s",F,C);
                }
                else
                {
                    printf("%s {AB,B} %s",F,C);
                }
            }
            else
            {
                if(F[0]=='O')
                {
                    printf("%s {A,AB} %s",F,C);
                }
                else if(F[0]=='B')
                {
                    printf("%s {A,AB} %s",F,C);
                }
                else if(F[0]=='A'&&F[1]=='B')
                {
                    printf("%s {A,AB,B,O} %s",F,C);
                }
                else
                {
                    printf("%s {A,AB,B,O} %s",F,C);
                }
            }






        }
    }
}
