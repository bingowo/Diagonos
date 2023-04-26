#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[21];
        int alpha[1000]={0};
        int num[10]={0};
        scanf("%s",s);
        int len=strlen(s);
        printf("case #%d:\n",i);
        for(int i=0;i<len;i++)
        {
            alpha[s[i]]++;
        }
        while(alpha['Z'])
        {
            alpha['Z']--;
            alpha['E']--;
            alpha['R']--;
            alpha['O']--;
            num[0]++;

        }
        while(alpha['W'])
        {
            alpha['T']--;
            alpha['W']--;
            alpha['O']--;
            num[2]++;
        }
        while(alpha['U'])
        {
            alpha['F']--;
            alpha['O']--;
            alpha['U']--;
            alpha['R']--;
            num[4]++;
        }
        while(alpha['F'])
        {
            alpha['F']--;
            alpha['I']--;
            alpha['V']--;
            alpha['E']--;
            num[5]++;
        }
        while(alpha['X'])
        {
            alpha['S']--;
            alpha['I']--;
            alpha['X']--;
            num[6]++;
        }
        while(alpha['V'])
        {
            alpha['S']--;
            alpha['E']--;
            alpha['V']--;
            alpha['E']--;
            alpha['N']--;
            num[7]++;
        }
        while(alpha['G'])
        {
            alpha['E']--;
            alpha['I']--;
            alpha['G']--;
            alpha['H']--;
            alpha['T']--;
            num[8]++;
        }
        while(alpha['I'])
        {
            alpha['N']--;
            alpha['I']--;
            alpha['N']--;
            alpha['E']--;
            num[9]++;
        }
        while(alpha['O'])
        {
            alpha['O']--;
            alpha['N']--;
            alpha['E']--;
            num[1]++;
        }
        while(alpha['R'])
        {
            alpha['T']--;
            alpha['H']--;
            alpha['E']-=2;
            alpha['R']--;
            num[3]++;
        }
        for(int p=0;p<10;p++)
        {
            while(num[p]>0)
            {
                printf("%d",p);
                num[p]--;
            }
        }
        printf("\n");
    }
}