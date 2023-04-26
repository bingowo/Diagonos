#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*s1,const void*s2)
{
    return *(char*)s1 - *(char*)s2;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i < T;i++)
    {
        int table[256];
        char decode[20];
        memset(table,0,sizeof(int)*256);
        char input[21];
        scanf("%s",input);
        int j,k = 0,len = strlen(input);
        for(j = 0;j < len;j++)
        {
            table[input[j]]++;
        }
        printf("case #%d:\n",i);
        for(j = table['Z'];j > 0;j--)
        {
            decode[k++] = '0';
            table['Z']--;
            table['E']--;
            table['R']--;
            table['O']--;
        }
        for(j = table['X'];j > 0;j--)
        {
            decode[k++] = '6';
            table['X']--;
            table['S']--;
            table['I']--;
        }
        for(j = table['W'];j > 0;j--)
        {
            decode[k++] = '2';
            table['W']--;
            table['T']--;
            table['O']--;
        }
        for(j = table['U'];j > 0;j--)
        {
            decode[k++] = '4';
            table['U']--;
            table['F']--;
            table['O']--;
            table['R']--;
        }
        for(j = table['R'];j > 0;j--)
        {
            decode[k++] = '3';
            table['R']--;
            table['T']--;
            table['H']--;
            table['E'] -= 2;
        }
        for(j = table['O'];j > 0;j--)
        {
            decode[k++] = '1';
            table['O']--;
            table['N']--;
            table['E']--;
        } 
        for(j = table['G'];j > 0;j--)
        {
            decode[k++] = '8';
            table['G']--;
            table['E']--;
            table['I']--;
            table['H']--;
            table['T']--;
        }
        for(j = table['F'];j > 0;j--)
        {
            decode[k++] = '5';
            table['F']--;
            table['I']--;
            table['V']--;
            table['E']--;
        }
        for(j = table['V'];j > 0;j--)
        {
            decode[k++] = '7';
        }
        decode[k] = '\0';
        qsort(decode,k,sizeof(char),cmp);
        printf("%s\n",decode);
    }
}