#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {char s[11]; int abo,rh;} person;

char table[][4] = {"A","AB","B","O"};

const int ABO[4][4][4]={1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
                        1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,
                        1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1, 
                        1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1};


void deal(person *a)
{
    memset(a->s,0,sizeof(a->s));
    scanf("%s",a->s);
    if (!strcmp(a->s,"?")) {a->abo = 0; return ;}
    char s[101] = {}; strcpy(s,a->s);
    if (strchr(s,'+')) {a->rh = 1; *strchr(s,'+') = '\0';}
    else {a->rh = 1; *strchr(s,'-') = '\0';}
    if (!strcmp("A",s)) a->abo = 1;
    else if (!strcmp("B",s)) a->abo = 3;
    else if (!strcmp("AB",s)) a->abo = 2;
    else if (!strcmp("O",s)) a->abo = 4;
}

int main()
{
    int n; scanf("%d",&n);
    while (n--)
    {
        person dad,mom,son;
        deal(&dad); deal(&mom);
        deal(&son);
        if (!strcmp(dad.s,"O-")&&!strcmp(mom.s,"O-"))
        {
            printf("O- O- O-\n");
            return 0;
        }
        if (dad.abo!=0) printf("%s ",dad.s);
        else if (!ABO[0][mom.abo-1][son.abo-1]&&!ABO[1][mom.abo-1][son.abo-1]&!ABO[2][mom.abo-1][son.abo-1]&&!ABO[3][mom.abo-1][son.abo-1]) 
            printf("impossible ");
        else
        {
            char t[20] = {};
            t[0] = '{';
            for (int i=0;i<4;i++)
            {
                if (ABO[i][mom.abo-1][son.abo-1])
                {
                    strcat(t,table[i]); strcat(t,"+,");
                    strcat(t,table[i]); strcat(t,"-,");
                }
            } 
            t[strlen(t)-1] = '}';
            printf("%s ",t);
        }
        if (mom.abo!=0) printf("%s ",mom.s);
        else if (!ABO[dad.abo-1][0][son.abo-1]&&!ABO[dad.abo-1][1][son.abo-1]&!ABO[dad.abo-1][2][son.abo-1]&&!ABO[dad.abo-1][3][son.abo-1]) printf("impossible ");
        else
        {
            char t[20] = {};
            t[0] = '{';
            for (int i=0;i<4;i++)
            {
                if (ABO[dad.abo-1][i][son.abo-1]) 
                {
                    strcat(t,table[i]); strcat(t,"+,");
                    strcat(t,table[i]); strcat(t,"-,");
                }
            } 
            t[strlen(t)-1] = '}';
            printf("%s ",t);
        }
        if (son.abo!=0) printf("%s ",son.s);
        else if (!ABO[dad.abo-1][mom.abo-1][0]&&!ABO[dad.abo-1][mom.abo-1][1]&!ABO[dad.abo-1][mom.abo-1][2]&&!ABO[3][mom.abo-1][son.abo-1]) printf("impossible ");
        else
        {
            char t[20] = {};
            t[0] = '{';
            for (int i=0;i<4;i++)
            {
                if (ABO[dad.abo-1][mom.abo-1][i])
                {
                    if (dad.rh||mom.rh)  {strcat(t,table[i]); strcat(t,"+,");}
                    strcat(t,table[i]); strcat(t,"-,");
                }
            }
            t[strlen(t)-1] = '}';
            printf("%s ",t);
        }
        printf("\n");
    }
    return 0;
}