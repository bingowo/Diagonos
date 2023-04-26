#include <stdio.h>
#include <string.h>
int main()
{
    char f[2]={0},m[2]={0},c[2]={0},answer[7][12]={0};
    scanf("%s %s %s",f,m,c);
    int len=0;
    if (strcmp(c,"?")==0)
    {
        if (strcmp(f,"O")==0||strcmp(m,"O")==0)
        {
            if (strcmp(f,"AB")==0||strcmp(m,"AB")==0)
            {
                answer[0][0]='A';
                answer[1][0]='B';
                len=2;
            }
            else if (strcmp(f,"A")==0||strcmp(m,"A")==0)
            {
                answer[0][0]='A';
                answer[1][0]='O';
                len=2;
            }
            else if (strcmp(f,"B")==0||strcmp(m,"B")==0)
            {
                answer[0][0]='B';
                answer[1][0]='O';
                len=2;
            }
            else
            {
                answer[0][0]='O';
                len=1;
            }
        }
        else if (strcmp(f,"AB")==0||strcmp(m,"AB")==0)
        {
            answer[0][0]='A';
            strcpy(answer[1],"AB");
            answer[2][0]='B';
            len=3;
        }
        else if(strcmp(f,m)==0)
        {
            strcpy(answer[0],f);
            answer[1][0]='O';
            len=2;
        }
        else
        {
            answer[0][0]='A';
            strcpy(answer[1],"AB");
            answer[2][0]='B';
            answer[3][0]='O';
            len=4;
        }
        printf("%s %s {",f,m);
        for (int i=0;i<len;i++)
        {
            printf("%s%c",answer[i],i==len-1?'}':',');
        }
    }

    else if (strcmp(f,"?")==0)
    {
        if (strcmp(c,"A")==0)
        {
            if(strcmp(m,"A")&&strcmp(m,"AB"))
            {
                answer[0][0]='A';
                strcpy(answer[1],"AB");
                len=2;

            }
            else
            {
                answer[0][0]='A';
                strcpy(answer[1],"AB");
                answer[2][0]='B';
                answer[3][0]='O';
                len=4;
            }
        }
        else if(strcmp(c,"B")==0)
        {
            if(strcmp(m,"B")&&strcmp(m,"AB"))
            {
                strcpy(answer[0],"AB");
                answer[1][0]='B';
                len=2;

            }
            else
            {
                answer[0][0]='A';
                strcpy(answer[1],"AB");
                answer[2][0]='B';
                answer[3][0]='O';
                len=4;
            }
        }
        else if (strcmp(c,"AB")==0)
        {
            if (strcmp(m,"AB")==0)
            {
                answer[0][0]='A';
                strcpy(answer[1],"AB");
                answer[2][0]='B';
                len=3;
            }
            else if (strcmp(m,"A")==0)
            {
                strcpy(answer[0],"AB");
                len=1;
            }
            else if (strcmp(m,"B")==0)
            {
                answer[0][0]='A';
                strcpy(answer[1],"AB");
                len=2;
            }
            else
            {
                strcpy(answer[0],"impossible");
            }
        }
        else if (strcmp(c,"O")==0)
        {
            if (strcmp(m,"AB")==0)
            {
                strcpy(answer[0],"impossible");
            }
            else
            {
                answer[0][0]='A';
                answer[1][0]='B';
                answer[2][0]='0';
                len=3;
            }
        }
        if (len==0)
        {
            printf("impossible ");
        }
        else
        {
            printf("{");
            for(int i=0;i<len;i++)
            {
                printf("%s%c",answer[i],i==len-1?'}':',');
            }
        }
        printf(" %s %s",m,c);
    }
    else if (strcmp(m,"?")==0)
    {
        if (strcmp(c,"A")==0)
        {
            if(strcmp(f,"A")&&strcmp(f,"AB"))
            {
                answer[0][0]='A';
                strcpy(answer[1],"AB");
                len=2;

            }
            else
            {
                answer[0][0]='A';
                strcpy(answer[1],"AB");
                answer[2][0]='B';
                answer[3][0]='O';
                len=4;
            }
        }
        else if(strcmp(c,"B")==0)
        {
            if(strcmp(f,"B")&&strcmp(f,"AB"))
            {
                strcpy(answer[0],"AB");
                answer[1][0]='B';
                len=2;

            }
            else
            {
                answer[0][0]='A';
                strcpy(answer[1],"AB");
                answer[2][0]='B';
                answer[3][0]='O';
                len=4;
            }
        }
        else if (strcmp(c,"AB")==0)
        {
            if (strcmp(f,"AB")==0)
            {
                answer[0][0]='A';
                strcpy(answer[1],"AB");
                answer[2][0]='B';
                len=3;
            }
            else if (strcmp(f,"A")==0)
            {
                strcpy(answer[0],"AB");
                len=1;
            }
            else if (strcmp(f,"B")==0)
            {
                answer[0][0]='A';
                strcpy(answer[1],"AB");
                len=2;
            }
            else
            {
                strcpy(answer[0],"impossible");
            }
        }
        else if (strcmp(c,"O")==0)
        {
            if (strcmp(f,"AB")==0)
            {
                strcpy(answer[0],"impossible");
            }
            else
            {
                answer[0][0]='A';
                answer[1][0]='B';
                answer[2][0]='0';
                len=3;
            }
        }
        printf("%s ",f);
        if (len==0)
        {
            printf("impossible ");
        }
        else
        {
            printf("{");
            for(int i=0;i<len;i++)
            {
                printf("%s%c",answer[i],i==len-1?'}':',');
            }
        }
        printf(" %s",c);
    }


}
