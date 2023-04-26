#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ABO[4][4][4]={1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
                        1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,
                        1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1, 
                        1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1};

typedef struct {char s[3]; int n;} person;

char table[][4] = {"A,","AB,","B,","O,"};

int change(char s[])
{
    if (!strcmp("A",s)) return 1;
    else if (!strcmp("B",s)) return 3;
    else if (!strcmp("AB",s)) return 2;
    else if (!strcmp("O",s)) return 4;
    else return 0;
}

main()
{
    char dad[3], mom[3], son[3];
    scanf("%s %s %s",dad,mom,son);
    int dad_ = change(dad); int mom_ = change(mom); int son_ = change(son);
    if (dad_!=0) printf("%s ",dad);
    else if (!ABO[0][mom_-1][son_-1]&&!ABO[1][mom_-1][son_-1]&!ABO[2][mom_-1][son_-1]&&!ABO[3][mom_-1][son_-1]) printf("impossible ");
    else
    {
        char t[20] = {};
        t[0] = '{';
        for (int i=0;i<4;i++) if (ABO[i][mom_-1][son_-1]) strcat(t,table[i]);
        t[strlen(t)-1] = '}';
        printf("%s ",t);
    }
    if (mom_!=0) printf("%s ",mom);
    else if (!ABO[dad_-1][0][son_-1]&&!ABO[dad_-1][1][son_-1]&!ABO[dad_-1][2][son_-1]&&!ABO[dad_-1][3][son_-1]) printf("impossible ");
    else
    {
        char t[20] = {};
        t[0] = '{';
        for (int i=0;i<4;i++) if (ABO[dad_-1][i][son_-1]) strcat(t,table[i]);
        t[strlen(t)-1] = '}';
        printf("%s ",t);
    }
    if (son_!=0) printf("%s ",son);
    else if (!ABO[dad_-1][mom_-1][0]&&!ABO[dad_-1][mom_-1][1]&!ABO[dad_-1][mom_-1][2]&&!ABO[3][mom_-1][son_-1]) printf("impossible ");
    else
    {
        char t[20] = {};
        t[0] = '{';
        for (int i=0;i<4;i++) if (ABO[dad_-1][mom_-1][i]) strcat(t,table[i]);
        t[strlen(t)-1] = '}';
        printf("%s ",t);
    }
    return 0;
}