#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const int ABO[4][4][4]={  //A:0 B:1 AB:2 O:3
        {
            {1,0,0,1},
            {1,1,1,1},
            {1,1,1,0},
            {1,0,0,1},
        },
        {
            {1,1,1,1},
            {0,1,0,1},
            {1,1,1,0},
            {0,1,0,1},
        },
        {
            {1,1,1,0},
            {1,1,1,0},
            {1,1,1,0},
            {1,1,0,0},
        },
        {
            {1,0,0,1},
            {0,1,0,1},
            {1,1,0,0},
            {0,0,0,1},
        },
    };
    char s[10]={0};
    int a[10]={0};
    gets(s);
    int i,l,j;
    l=strlen(s);
    if(l==5)//没有AB
    {
        if(s[4]=='?')
        {
            printf("%c %c ",s[0],s[2]);
            int father,mother;
            if(s[0]=='A')
                father=0;
            if(s[0]=='B')
                father=1;
            if(s[0]=='O')
                father=3;
            if(s[2]=='A')
                mother=0;
            if(s[2]=='B')
                mother=1;
            if(s[2]=='O')
                mother=3;
            for(i=0,j=0;i<4;i++)
            {
                if(ABO[father][mother][i]==1)
                    a[j++]=i+1;
            }
            printf("{");
            for(i=0;a[i]!=0;i++)
            {
                if(a[i+1]!=0)
                {
                    if(a[i]==1)
                        printf("A,");
                    if(a[i]==2)
                        printf("B,");
                    if(a[i]==3)
                        printf("AB,");
                    if(a[i]==4)
                        printf("O,");

                }
                else
                {
                    if(a[i]==1)
                        printf("A}");
                    if(a[i]==2)
                        printf("B}");
                    if(a[i]==3)
                        printf("AB}");
                    if(a[i]==4)
                        printf("O}");

                }
            }
        }
    }
}