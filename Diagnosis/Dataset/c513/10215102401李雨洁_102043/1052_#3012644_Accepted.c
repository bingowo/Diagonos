#include <string.h>
#include <stdio.h>

int alpha[130];
char number[10][20] =
{"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

void trans(char str[])
{
    memset(alpha,0,520);
    int NUM[10] = {0};

    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        alpha[str[i]]++;
    }

    while(alpha['Z'])
    {
        alpha['Z']--;
        alpha['E']--;
        alpha['R']--;
        alpha['O']--;
        NUM[0]++;

    }
    while(alpha['W'])
    {
        alpha['T']--;
        alpha['W']--;
        alpha['O']--;
        NUM[2]++;
    }
    while(alpha['U'])
    {
        alpha['F']--;
        alpha['O']--;
        alpha['U']--;
        alpha['R']--;
        NUM[4]++;
    }
    while(alpha['F'])
    {
        alpha['F']--;
        alpha['I']--;
        alpha['V']--;
        alpha['E']--;
        NUM[5]++;
    }
    while(alpha['X'])
    {
        alpha['S']--;
        alpha['I']--;
        alpha['X']--;
        NUM[6]++;
    }
    while(alpha['V'])
    {
        alpha['S']--;
        alpha['E']--;
        alpha['V']--;
        alpha['E']--;
        alpha['N']--;
        NUM[7]++;
    }
    while(alpha['G'])
    {
        alpha['E']--;
        alpha['I']--;
        alpha['G']--;
        alpha['H']--;
        alpha['T']--;
        NUM[8]++;
    }
    while(alpha['I'])
    {
        alpha['N']--;
        alpha['I']--;
        alpha['N']--;
        alpha['E']--;
        NUM[9]++;
    }
    while(alpha['O'])
    {
        alpha['O']--;
        alpha['N']--;
        alpha['E']--;
        NUM[1]++;
    }
    while(alpha['R'])
    {
        alpha['T']--;
        alpha['H']--;
        alpha['E']-=2;
        alpha['R']--;

        NUM[3]++;
    }

    for(int i = 0; i < 10 ; i++)
    {
        while(NUM[i])
        {
            NUM[i]--;
           printf("%d",i) ;
        }
    }

}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++)
    {
        char str[20];
        scanf("%s",str);
        printf("case #%d:\n",i);
        trans(str);
        printf("\n");
    }
    return 0;
}

