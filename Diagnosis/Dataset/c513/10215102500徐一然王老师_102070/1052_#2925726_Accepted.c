#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(int*a,int*b)
{
        return *a-*b;
}

int main()
{
    int count,count1;
    scanf("%d\n",&count);
    count1=count;
    char S[100];
    int Map[128];

    while(count--)
    {
        int i=0;
        int A[10];
        int* p2=A;
        for(int i=0;i<128;i++)
        {
            Map[i]=0;
        }
        gets(S);
        char *p1=S;
        while(*p1)
        {
            Map[*p1]++;
            p1++;
        }

        while(Map['Z']!=0)
        {
            Map['Z']--;
            Map['E']--;
            Map['R']--;
            Map['O']--;
            A[i]=0;
            i++;
        }
        while(Map['X']!=0)
        {
            Map['X']--;
            Map['S']--;
            Map['I']--;
            A[i]=6;
            i++;
        }

        while(Map['G']!=0)
        {
            Map['E']--;
            Map['I']--;
            Map['G']--;
            Map['H']--;
            Map['T']--;
            A[i]=8;
            i++;
        }

        while(Map['H']!=0)
        {
            Map['T']--;
            Map['H']--;
            Map['R']--;
            Map['E']--;
            Map['E']--;
            A[i]=3;
            i++;
        }

        while(Map['S']!=0)
        {
            Map['S']--;
            Map['E']--;
            Map['V']--;
            Map['E']--;
            Map['N']--;
            A[i]=7;
            i++;
        }

        while(Map['V']!=0)
        {
            Map['F']--;
            Map['I']--;
            Map['V']--;
            Map['E']--;
            A[i]=5;
            i++;
        }

        while(Map['F']!=0)
        {
            Map['F']--;
            Map['O']--;
            Map['U']--;
            Map['R']--;
            A[i]=4;
            i++;
        }

        while(Map['T']!=0)
        {
            Map['T']--;
            Map['W']--;
            Map['O']--;
            A[i]=2;
            i++;
        }

        while(Map['O']!=0)
        {
            Map['O']--;
            Map['N']--;
            Map['E']--;
            A[i]=1;
            i++;
        }
        while(Map['I']!=0)
        {
            Map['N']--;
            Map['I']--;
            Map['N']--;
            Map['E']--;
            A[i]=9;
            i++;
        }
        printf("case #%d:\n",count1-count-1);
        qsort(p2,i,sizeof(A[0]),cmp);
        for(int j=0;j<i-1;j++)
        {
            printf("%d",A[j]);
        }
        printf("%d\n",A[i-1]);

    }
}
