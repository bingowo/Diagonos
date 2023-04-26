#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int alpha[130];
int cmp(const void*a,const void*b)
{return *(int*)a>*(int*)b?1:-1;}

void trans(char* str)
{
    memset(alpha,0,520);
    int NUM[10] = {0},len = strlen(str);
    for(int i = 0; i < len; i++) alpha[(int)str[i]]++;
    while(alpha['Z'])//0
    {
        alpha['Z']--;
        alpha['E']--;
        alpha['R']--;
        alpha['O']--;
        NUM[0]++;
    }
    while(alpha['W'])//2
    {
        alpha['T']--;
        alpha['W']--;
        alpha['O']--;
        NUM[2]++;
    }
    while(alpha['U'])//4
    {
        alpha['F']--;
        alpha['O']--;
        alpha['U']--;
        alpha['R']--;
        NUM[4]++;
    }
    while(alpha['F'])//5
    {
        alpha['F']--;
        alpha['I']--;
        alpha['V']--;
        alpha['E']--;
        NUM[5]++;
    }
    while(alpha['X'])//6
    {
        alpha['S']--;
        alpha['I']--;
        alpha['X']--;
        NUM[6]++;
    }
    while(alpha['V'])//7
    {
        alpha['S']--;
        alpha['E']--;
        alpha['V']--;
        alpha['E']--;
        alpha['N']--;
        NUM[7]++;
    }
    while(alpha['G'])//8
    {
        alpha['E']--;
        alpha['I']--;
        alpha['G']--;
        alpha['H']--;
        alpha['T']--;
        NUM[8]++;
    }
    while(alpha['I'])//9
    {
        alpha['N']--;
        alpha['I']--;
        alpha['N']--;
        alpha['E']--;
        NUM[9]++;
    }
    while(alpha['O'])//1
    {
        alpha['O']--;
        alpha['N']--;
        alpha['E']--;
        NUM[1]++;
    }
    while(alpha['R'])//3
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
            printf("%d",i);
        }
    }    
}

int main()
{
    int T;scanf("%d",&T);getchar();
    char line[20];
    for(int p=0;p<T;p++)
    {
        gets(line);
        printf("case #%d:\n",p);
        trans(line);
        printf("\n");
    }

    return 0;
}