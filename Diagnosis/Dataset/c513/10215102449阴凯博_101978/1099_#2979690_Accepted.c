#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char ch;
    char* s;
} CODE;


CODE arr2[2][2],arr3[2][4],arr4[2][6],arr5[2][5];


void empty(char* s)
{
    for (int i=strlen(s)-1;i>=0;i--)
        s[i]=0;
}

void print(char *s)
{
    switch (strlen(s))
        {
        case 1:
            {
                if (s[0]=='.')
                    printf("E");
                else
                    printf("T");
                break;
            }
        case 2:
            {
                if (s[0]=='.')
                {
                    for (int j=0;j<2;j++)
                        if (strcmp(s,arr2[0][j].s)==0)
                            printf("%c",arr2[0][j].ch);
                }
                else
                {
                    for (int j=0;j<2;j++)
                        if (strcmp(s,arr2[1][j].s)==0)
                            printf("%c",arr2[1][j].ch);
                }
                break;
            }
        case 3:
            {
                if (s[0]=='.')
                {
                    for (int j=0;j<4;j++)
                        if (strcmp(s,arr3[0][j].s)==0)
                            printf("%c",arr3[0][j].ch);
                }
                else
                {
                    for (int j=0;j<4;j++)
                        if (strcmp(s,arr3[1][j].s)==0)
                            printf("%c",arr3[1][j].ch);
                }
                break;
            }
        case 4:
            {
                if (s[0]=='.')
                {
                    for (int j=0;j<6;j++)
                        if (strcmp(s,arr4[0][j].s)==0)
                            printf("%c",arr4[0][j].ch);
                }
                else
                {
                    for (int j=0;j<6;j++)
                        if (strcmp(s,arr4[1][j].s)==0)
                            printf("%c",arr4[1][j].ch);
                }
                break;
            }
        case 5:
            {
                if (s[0]=='.')
                {
                    for (int j=0;j<5;j++)
                        if (strcmp(s,arr5[0][j].s)==0)
                            printf("%c",arr5[0][j].ch);
                }
                else
                {
                    for (int j=0;j<5;j++)
                        if (strcmp(s,arr5[1][j].s)==0)
                            printf("%c",arr5[1][j].ch);
                }
                break;
            }
        }
}



int main()
{

arr2[0][0].ch='A'; arr2[0][0].s=".-";    arr4[0][0].ch='H'; arr4[0][0].s="....";
arr2[0][1].ch='I'; arr2[0][1].s="..";    arr4[0][1].ch='V'; arr4[0][1].s="...-";
arr2[1][0].ch='M'; arr2[1][0].s="--";    arr4[0][2].ch='P'; arr4[0][2].s=".--.";
arr2[1][1].ch='N'; arr2[1][1].s="-.";    arr4[0][3].ch='L'; arr4[0][3].s=".-..";
arr3[0][0].ch='S'; arr3[0][0].s="...";   arr4[0][4].ch='F'; arr4[0][4].s="..-.";
arr3[0][1].ch='U'; arr3[0][1].s="..-";   arr4[0][5].ch='J'; arr4[0][5].s=".---";
arr3[0][2].ch='W'; arr3[0][2].s=".--";   arr4[1][0].ch='Y'; arr4[1][0].s="-.--";
arr3[0][3].ch='R'; arr3[0][3].s=".-.";   arr4[1][1].ch='X'; arr4[1][1].s="-..-";
arr3[1][0].ch='O'; arr3[1][0].s="---";   arr4[1][2].ch='B'; arr4[1][2].s="-...";
arr3[1][1].ch='G'; arr3[1][1].s="--.";   arr4[1][3].ch='C'; arr4[1][3].s="-.-.";
arr3[1][2].ch='K'; arr3[1][2].s="-.-";   arr4[1][4].ch='Q'; arr4[1][4].s="--.-";
arr3[1][3].ch='D'; arr3[1][3].s="-..";   arr4[1][5].ch='Z'; arr4[1][5].s="--..";
arr5[0][0].ch='1'; arr5[0][0].s=".----";  arr5[0][1].ch='2'; arr5[0][1].s="..---";
arr5[0][2].ch='3'; arr5[0][2].s="...--";  arr5[0][3].ch='4'; arr5[0][3].s="....-";
arr5[0][4].ch='5'; arr5[0][4].s=".....";  arr5[1][0].ch='6'; arr5[1][0].s="-....";
arr5[1][1].ch='7'; arr5[1][1].s="--...";  arr5[1][2].ch='8'; arr5[1][2].s="---..";
arr5[1][3].ch='9'; arr5[1][3].s="----.";  arr5[1][4].ch='0'; arr5[1][4].s="-----";
    int T;
    scanf("%d",&T);
    getchar();
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[10]={0},c;
        int a=0,cnt=0;
        while (c=getchar())
        {
//            printf("%c",c);
//            printf("%d\n",a);
            if (c=='/')
            {
                cnt++;
                continue;
            }

            if (cnt==3)
            {
                print(s);
                empty(s);
                printf(" ");
                cnt=0;
                a=0;
//                continue;
            }
            if (cnt==5)
            {
                print(s);
                empty(s);
                printf(".");
                cnt=0;
                a=0;
//                continue;
            }

            if (cnt==1 || c==EOF || c=='\n' )
            {
                print(s);
                empty(s);
                cnt=0;
                a=0;
                if (c==EOF || c=='\n')
                    break;
//                continue;
            }
            s[a++]=c;


        }
        printf("\n");
    }

    return 0;
}
