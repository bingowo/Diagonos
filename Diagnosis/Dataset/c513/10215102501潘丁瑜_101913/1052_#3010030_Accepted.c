#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ZERO 1"Z"
//ONE 10"O"
//TWO 2"W"
//THREE 6"R"
//FOUR 3"U"
// FIVE 7"F"
//SIX 4"X"
//SEVEN 8"S"
// EIGHT 5"G"
// NINE 9"I"
int main()
{
    int N,i;
    scanf("%d\n",&N);
    for(i=0;i<N;i++)
    {
        char str[30]={0};
        char num[30]={0};
        char alpha[150]={0};
        char ch;
        int j;
        gets(str);
        for(j=0;j<strlen(str);j++)
        {
            ch = str[j];
            alpha[ch] += 1;
        }
        while(alpha['Z'])
        {
            num[0]++;
            alpha['Z']--;
            alpha['E']--;
            alpha['R']--;
            alpha['O']--;
        }
        while(alpha['W'])
        {
            num[2]++;
            alpha['T']--;
            alpha['W']--;
            alpha['O']--;
        }
        while(alpha['U'])
        {
            num[4]++;
            alpha['F']--;
            alpha['O']--;
            alpha['U']--;
            alpha['R']--;
        }
        while(alpha['X'])
        {
            num[6]++;
            alpha['S']--;
            alpha['I']--;
            alpha['X']--;
        }
        while(alpha['G'])
        {
            num[8]++;
            alpha['E']--;
            alpha['I']--;
            alpha['G']--;
            alpha['H']--;
            alpha['T']--;
        }
        while(alpha['R'])
        {
            num[3]++;
            alpha['T']--;
            alpha['H']--;
            alpha['R']--;
            alpha['E']--;
            alpha['E']--;
        }

        while(alpha['F'])
        {
            num[5]++;
            alpha['F']--;
            alpha['I']--;
            alpha['V']--;
            alpha['E']--;
        }

        while(alpha['S'])
        {
            num[7]++;
            alpha['S']--;
            alpha['E']--;
            alpha['V']--;
            alpha['E']--;
            alpha['N']--;
        }

        while(alpha['I'])
        {
            num[9]++;
            alpha['N']--;
            alpha['I']--;
            alpha['N']--;
            alpha['E']--;
        }

        while(alpha['O'])
        {
            num[1]++;
            alpha['O']--;
            alpha['N']--;
            alpha['E']--;
        }
        printf("case #%d:\n",i);
        for(j=0;j<10;j++)
        {
            while(num[j])
            {
                printf("%d",j);
                num[j]--;
            }

        }
        printf("\n");

    }
    return 0;
}
