#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const int ABO[4][4][4]={  //A:0 B:1 AB:2 O:3
        {
            {1,0,0,1},
            {1,1,1,0},
            {1,1,1,1},
            {1,0,0,1},
        },
        {
            {1,1,1,0},
            {1,1,1,0},
            {1,1,1,0},
            {1,0,1,0},
        },
        {
            {1,1,1,1},
            {1,1,1,0},
            {0,0,1,1},
            {0,0,1,1},
        },
        {
            {1,0,0,1},
            {1,0,1,0},
            {0,0,1,1},
            {0,0,0,1},
        },
    };
    char s[10]={0};
    int a[10]={0};
    gets(s);
    int i,l,j;
    l=strlen(s);
    if(l==5)//ц╩спAB
    {
        if(s[4]=='?')
        {
            printf("%c %c ",s[0],s[2]);
            int father,mother;
            if(s[0]=='A')
                father=0;
            if(s[0]=='B')
                father=2;
            if(s[0]=='O')
                father=3;
            if(s[2]=='A')
                mother=0;
            if(s[2]=='B')
                mother=2;
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
                    if(a[i]==3)
                        printf("B,");
                    if(a[i]==2)
                        printf("AB,");
                    if(a[i]==4)
                        printf("O,");

                }
                else
                {
                    if(a[i]==1)
                        printf("A}");
                    if(a[i]==3)
                        printf("B}");
                    if(a[i]==2)
                        printf("AB}");
                    if(a[i]==4)
                        printf("O}");
                }
            }
        }
        if(s[0]=='?')
        {
            int mother,child=0;
            if(s[4]=='A')
                child=0;
            if(s[4]=='B')
                child=2;
            if(s[4]=='O')
                child=3;
            if(s[2]=='A')
                mother=0;
            if(s[2]=='B')
                mother=2;
            if(s[2]=='O')
                mother=3;
            for(i=0,j=0;i<4;i++)
            {
                if(ABO[i][mother][child]==1)
                    a[j++]=i+1;
            }
            if(a[0]!=0)
            {
                printf("{");
                for(i=0;a[i]!=0;i++)
                    {
                        if(a[i+1]!=0)
                        {
                    if(a[i]==1)
                        printf("A,");
                    if(a[i]==3)
                        printf("B,");
                    if(a[i]==2)
                        printf("AB,");
                    if(a[i]==4)
                        printf("O,");
                }
                else
                {
                    if(a[i]==1)
                        printf("A}");
                    if(a[i]==3)
                        printf("B}");
                    if(a[i]==2)
                        printf("AB}");
                    if(a[i]==4)
                        printf("O}");
                }
            }
            }
            else
                printf("impossible");
            printf(" %c %c",s[2],s[4]);
        }
        if(s[2]=='?')
        {
            int father,child;
            if(s[0]=='A')
                father=0;
            if(s[0]=='B')
                father=2;
            if(s[0]=='O')
                father=3;
            if(s[4]=='A')
                child=0;
            if(s[4]=='B')
                child=2;
            if(s[4]=='O')
                child=3;
            for(i=0,j=0;i<4;i++)
            {
                if(ABO[father][i][child]==1)
                    a[j++]=i+1;
            }
            printf("%c ",s[0]);
            if(a[0]!=0)
            {
                printf("{");
                for(i=0;a[i]!=0;i++)
                    {
                        if(a[i+1]!=0)
                        {
                    if(a[i]==1)
                        printf("A,");
                    if(a[i]==3)
                        printf("B,");
                    if(a[i]==2)
                        printf("AB,");
                    if(a[i]==4)
                        printf("O,");
                }
                else
                {
                    if(a[i]==1)
                        printf("A}");
                    if(a[i]==3)
                        printf("B}");
                    if(a[i]==2)
                        printf("AB}");
                    if(a[i]==4)
                        printf("O}");
                }
            }
            }
            else
                printf("impossible");
            printf(" %c",s[4]);
        }
    }
    if(l==6)
    {
        int father,mother;
        if(s[0]=='A'&&s[1]=='B')
        {
            if(s[5]=='?')
            {
                printf("AB %c ",s[3]);
            father=1;
            if(s[3]=='A')
                mother=0;
            if(s[3]=='B')
                mother=2;
            if(s[3]=='O')
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
                    if(a[i]==3)
                        printf("B,");
                    if(a[i]==2)
                        printf("AB,");
                    if(a[i]==4)
                        printf("O,");

                }
                else
                {
                    if(a[i]==1)
                        printf("A}");
                    if(a[i]==3)
                        printf("B}");
                    if(a[i]==2)
                        printf("AB}");
                    if(a[i]==4)
                        printf("O}");
                }
            }
        }
        if(s[3]=='?')
        {
            int father,child;
            father=1;
            if(s[5]=='A')
                child=0;
            if(s[5]=='B')
                child=2;
            if(s[5]=='O')
                child=3;
            for(i=0,j=0;i<4;i++)
            {
                if(ABO[father][i][child]==1)
                    a[j++]=i+1;
            }
            printf("AB ");
            if(a[0]==0)
                printf("impossible");
            else
            {
                printf("{");
                for(i=0;a[i]!=0;i++)
                    {
                        if(a[i+1]!=0)
                        {
                    if(a[i]==1)
                        printf("A,");
                    if(a[i]==3)
                        printf("B,");
                    if(a[i]==2)
                        printf("AB,");
                    if(a[i]==4)
                        printf("O,");
                }
                else
                {
                    if(a[i]==1)
                        printf("A}");
                    if(a[i]==3)
                        printf("B}");
                    if(a[i]==2)
                        printf("AB}");
                    if(a[i]==4)
                        printf("O}");
                }
            }
            }
            printf(" %c",s[5]);
        }
            }
        if(s[2]=='A'&&s[3]=='B')
        {
            if(s[5]=='?')
            {
                printf("%c AB ",s[0]);
            mother=1;
            if(s[0]=='A')
                father=0;
            if(s[0]=='B')
                father=2;
            if(s[0]=='O')
                father=3;
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
                    if(a[i]==3)
                        printf("B,");
                    if(a[i]==2)
                        printf("AB,");
                    if(a[i]==4)
                        printf("O,");

                }
                else
                {
                    if(a[i]==1)
                        printf("A}");
                    if(a[i]==3)
                        printf("B}");
                    if(a[i]==2)
                        printf("AB}");
                    if(a[i]==4)
                        printf("O}");
                }
            }
            }
            if(s[0]=='?')
            {
                int mother,child;
                mother=1;
                if(s[5]=='A')
                    child=0;
                if(s[5]=='B')
                    child=2;
                if(s[5]=='O')
                    child=3;
                for(i=0,j=0;i<4;i++)
                {
                    if(ABO[i][mother][child]==1)
                    a[j++]=i+1;
                }
                if(a[0]==0)
                printf("impossible");
                else
            {
                printf("{");
                for(i=0;a[i]!=0;i++)
                    {
                        if(a[i+1]!=0)
                        {
                    if(a[i]==1)
                        printf("A,");
                    if(a[i]==3)
                        printf("B,");
                    if(a[i]==2)
                        printf("AB,");
                    if(a[i]==4)
                        printf("O,");
                }
                else
                {
                    if(a[i]==1)
                        printf("A}");
                    if(a[i]==3)
                        printf("B}");
                    if(a[i]==2)
                        printf("AB}");
                    if(a[i]==4)
                        printf("O}");
                }
            }
            }
            printf(" AB %c",s[5]);
            }
        }
        if(s[4]=='A'&&s[5]=='B')
        {
            if(s[0]=='?')
            {
                int mother,child;
                child=1;
                if(s[2]=='A')
                mother=0;
                if(s[2]=='B')
                mother=2;
                if(s[2]=='O')
                mother=3;
                for(i=0,j=0;i<4;i++)
                {
                    if(ABO[i][mother][child]==1)
                    a[j++]=i+1;
                }
                if(a[0]==0)
                printf("impossible");
                else
            {
                printf("{");
                for(i=0;a[i]!=0;i++)
                    {
                        if(a[i+1]!=0)
                        {
                    if(a[i]==1)
                        printf("A,");
                    if(a[i]==3)
                        printf("B,");
                    if(a[i]==2)
                        printf("AB,");
                    if(a[i]==4)
                        printf("O,");
                }
                else
                {
                    if(a[i]==1)
                        printf("A}");
                    if(a[i]==3)
                        printf("B}");
                    if(a[i]==2)
                        printf("AB}");
                    if(a[i]==4)
                        printf("O}");
                }
            }
            }
            printf(" %c AB",s[2]);
            }
            if(s[2]=='?')
            {
                int father,child;
                child=1;
                if(s[0]=='A')
                father=0;
            if(s[0]=='B')
                father=2;
            if(s[0]=='O')
                father=3;
                for(i=0,j=0;i<4;i++)
            {
                if(ABO[father][i][child]==1)
                    a[j++]=i+1;
            }
            printf("%c ",s[0]);
            if(a[0]==0)
                printf("impossible");
            else
            {
                printf("{");
                for(i=0;a[i]!=0;i++)
                    {
                        if(a[i+1]!=0)
                        {
                    if(a[i]==1)
                        printf("A,");
                    if(a[i]==3)
                        printf("B,");
                    if(a[i]==2)
                        printf("AB,");
                    if(a[i]==4)
                        printf("O,");
                }
                else
                {
                    if(a[i]==1)
                        printf("A}");
                    if(a[i]==3)
                        printf("B}");
                    if(a[i]==2)
                        printf("AB}");
                    if(a[i]==4)
                        printf("O}");
                }
            }
            }
            printf(" AB");
        }
    }
    }
    if(l==7)
    {
        if(s[6]=='?')
            printf("AB AB {A,AB,B}");
        if(s[0]=='?')
            printf("{A,AB,B} AB AB");
        if(s[3]=='?')
            printf("AB {A,AB,B} AB");
    }
}