#include <stdio.h>
#include <string.h>
int main()
{
    char s1[5],s2[5],s3[5],s4[] = "AB";
    scanf("%s %s %s",s1,s2,s3);
    if(s3[0] == '?')
    {
        printf("%s %s ",s1,s2);
        if(strcmp(s1,s4)==0||strcmp(s2,s4)==0)
        {

            if(s2[0] == 'O'||s1[0]=='O') printf("{A,B}");
            else printf("{A,AB,B}");
        }
        else if(s1[0] == 'A')
        {
            if(s2[0]=='A') printf("{A,O}");
            else if(s2[0]=='B') printf("{A,AB,B,O}");
            else printf("{A,O}");
        }
        else if(s1[0] == 'B')
        {
            if(s2[0]=='B') printf("{B,O}");
            else if(s2[0]=='A') printf("{A,AB,B,O}");
            else printf("{B,O}");
        }
        else
        {
            if(s2[0]=='A') printf("{A,O}");
            else if(s2[0]=='B') printf("{B,O}");
            else printf("{O}");
        }
    }
    else
    {
        if(s2[0]=='?') {printf("%s ",s1);strcpy(s2,s1);}
        if(strcmp(s2,s4)==0)
        {
            if(strcmp(s3,s4)==0) printf("{A,AB,B} ");
            else if(s3[0]=='O') printf("impossible ");
            else printf("{A,AB,B,O} ");
        }
        else if(s2[0]=='A')
        {
            if(s3[0]=='A'&&strlen(s3)==1) printf("{A,AB,B,O} ");
            else if(s3[0]=='O') printf("{A,B,O} ");
            else printf("{AB,B} ");
        }
        else if(s2[0]=='B')
        {
            if(s3[0]=='B') printf("{A,AB,B,O} ");
            else if(s3[0]=='O') printf("{A,B,O} ");
            else printf("{A,AB} ");
        }
        else{
            if(strcmp(s3,s4)==0) printf("impossible ");
            else if(s3[0]=='A') printf("{A,AB} ");
            else if(s3[0]=='B') printf("{AB,B} ");
            else printf("{A,B,O} ");
        }
        if(s1[0]=='?') printf("%s ",s2);
        printf("%s",s3);

    }
    return 0;
}
