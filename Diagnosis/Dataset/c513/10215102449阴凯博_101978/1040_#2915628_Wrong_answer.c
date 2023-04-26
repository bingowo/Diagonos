#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char mom[5]={0},dad[5]={0},child[5]={0};
    scanf("%s %s %s",dad,mom,child);
    if (mom[0]=='?')
    {
        if (child[0]=='O')
        {
            if (strlen(dad)==2)
                printf("%s impossible %s\n",dad,child);
            else
                printf("%s {A,B,O} %s\n",dad,child);
        }
        if (strlen(child)==2)
        {
            if (strlen(dad)==2)
                printf("%s {A,AB,B} %s\n",dad,child);
            else if (dad[0]=='O')
                printf("%s impossible %s\n",dad,child);
            else
            {
                if (dad[0]=='A')
                    printf("%s {AB,B} %s\n",dad,child);
                else
                    printf("%s {A,AB} %s\n",dad,child);
            }
        }
        else if (child[0]=='A')
        {
            if (dad[0]=='B')
                printf("%s {A,AB} %s\n",dad,child);
            else
                printf("%s {A,AB,B,O} %s\n",dad,child);
        }
        if (child[0]=='B')
        {
            if (dad[0]=='A')
                printf("%s {AB,B} %s\n",dad,child);
            else if (dad[0]=='O')
                printf("%s {AB,B} %s\n",dad,child);
            else
                printf("%s {A,AB,B} %s\n",dad,child);
        }
    }
    if (dad[0]=='?')
    {
        if (child[0]=='O')
        {
            if (strlen(mom)==2)
                printf("impossible %s %s\n",mom,child);
            else
                printf("{A,B,O} %s %s\n",mom,child);
        }
        if (strlen(child)==2)
        {
            if (strlen(mom)==2)
                printf("{A,AB,B} %s %s\n",mom,child);
            else if (mom[0]=='O')
                printf("impossible %s %s\n",mom,child);
            else
            {
                if (mom[0]=='A')
                    printf("{AB,B} %s %s\n",mom,child);
                else
                    printf("{A,AB} %s %s\n",mom,child);
            }
        }
        else if (child[0]=='A')
        {
            if (mom[0]=='B')
                printf("{A,AB} %s %s\n",mom,child);
            else
                printf("{A,AB,B,O} %s %s\n",mom,child);
        }
        if (child[0]=='B')
        {
            if (mom[0]=='A')
                printf("{AB,B} %s %s\n",mom,child);
            else if (mom[0]=='O')
                printf("{AB,B} %s %s\n",mom,child);
            else 
                printf("{A,AB,B} %s %s\n",mom,child);
        }
    }
    if (child[0]=='?')
    {
        if (mom[0]=='O' && dad[0]=='O')
            printf("%s %s {O}\n",dad,mom);
        else if (mom[0]=='O' && strlen(dad)==1)
            printf("%s %s {%s,O}\n",dad,mom,dad);
        else if (dad[0]=='O' && strlen(mom)==1)
            printf("%s %s {%s,O}\n",dad,mom,mom);
        else if ((mom[0]=='O' && strlen(dad)==2) || (dad[0]=='O' && strlen(mom)==2))
            printf("%s %s {A,B}\n",dad,mom);
        else if (strlen(dad)==2 || strlen(mom)==2)
            printf("%s %s {A,AB,B}\n",dad,mom);
        else if (dad[0]==mom[0])
            printf("%s %s {%s,O}",dad,mom,mom);


    }
    return 0;
}
