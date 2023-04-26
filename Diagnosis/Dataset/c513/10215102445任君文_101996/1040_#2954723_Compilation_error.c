#include<string.h>
#include<stdio.h>
#define M 100
int q(char a,char b,char c)
{
    if(a=='?')
        return 1;
    else if(b=='?')
        return 2;
    else
        return 3;
}
int main()
{
    int des;
    char A[2]={'A','O'};
    char res[M]={0};
    char B[2]={'B','O'};
    char O[2]={'O','O'};
    char AB[2]={'A','B'};
    char m;
    char f;
    char c;
    scanf("%s",&f);
    scanf("%s",&m);
    scanf("%s",&c);
    des=q(f,m,c);
    if(des==3)
    {
        if(f=='A'))
        {
            if(m=='A')
                printf("A A {A,O}\n");
            else if(m=='B')
                printf("A B {AB,A,B,O}\n");
            else if(m=='O')
                printf("A O {A,O}\n");
            else
                printf("A AB {AB,A,B}\n");
        }
        else if(f=='B'))
        {
            if(m=='B')
                printf("B B {B,O}\n");
            else if(m=='A')
                printf("B A {AB,A,B,O}\n");
            else if(m=='O')
                printf("B O {B,O}\n");
            else
                printf("B AB {AB,A,B}\n");
        }
        else if(f=='O'))
        {
            if(m=='A')
                printf("O A {A,O}\n");
            else if(m=='B')
                printf("O B {B,O}\n");
            else if(m=='O')
                printf("O O {O}\n");
            else
                printf("O AB {A,B}\n");
        }
        else
        {
            if(m=='A')
                printf("AB A {AB,A,B}\n");
            else if(m=='B')
                printf("AB B {AB,A,B}\n");
            else if(m=='O')
                printf("AB O {A,B}\n");
            else
                printf("AB AB {AB,A,B}\n");
        }
    }
    else if(des==2)
    {
        if(f=='A')
        {
           ;
        }
        else if(f=='B')
        {
            ;
        }
        else if(f=='O');
        {
            ;
        }
        else
        {
            ;
        }
    }
    
    return 0;
}