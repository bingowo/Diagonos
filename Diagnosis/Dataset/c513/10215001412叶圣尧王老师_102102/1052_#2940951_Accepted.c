#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[130]={0};
char number[10][6]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
void trans(char str[])
{
    int NUM[10]={0};
    int len=strlen(str);
    for(int i=0;i<len;i++)a[str[i]]++;
    while(a['Z'])
    {
        a['Z']--;a['E']--;a['R']--;a['O']--;NUM[0]++;
    }
    while(a['W'])
    {
        a['T']--;a['W']--;a['O']--;NUM[2]++;
    }
    while(a['U'])
    {
        a['F']--;a['O']--;a['U']--;a['R']--;NUM[4]++;
    }
    while(a['F'])
    {
        a['F']--;a['I']--;a['V']--;a['E']--;NUM[5]++;
    }
    while(a['X'])
    {
        a['S']--;a['I']--;a['X']--;NUM[6]++;
    }
    while(a['V'])
    {
        a['S']--;a['E']--;a['V']--;a['E']--;a['N']--;NUM[7]++;
    }
    while(a['G'])
    {
        a['E']--;a['I']--;a['G']--;a['H']--;a['T']--;NUM[8]++;
    }
    while(a['I'])
    {
        a['N']--;a['I']--;a['N']--;a['E'];NUM[9]++;
    }
    while(a['O'])
    {
        a['O']--;a['N']--;a['E']--;NUM[1]++;
    }
    while(a['R'])
    {
        a['T']--;a['H']--;a['R']--;a['E']-=2;NUM[3]++;
    }
    
    for(int i=0;i<10;i++)
    {
        while(NUM[i])
        {
            NUM[i]--;printf("%d",i);
        }
    }
}

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char str[21];scanf("%s",str);
        printf("case #%d:\n",i);
        trans(str);
        printf("\n");
    }
}








