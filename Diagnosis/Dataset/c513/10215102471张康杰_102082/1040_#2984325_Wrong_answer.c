#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char A[2][2]={{'A','A'},{'A','O'}};
    char B[2][2]={{'B','B'},{'B','O'}};
    char O[1][2]={'O','O'};
    char AB[1][2]={'A','B'};
    char input[10];
    scanf("%s",input);
    if(strcmp(input,"A A ?") == 0)
    printf("A A {A,O}");
    else if(strcmp(input,"A B ?") == 0)
    printf("A B {A,AB,B,O}");
    else if(strcmp(input,"A AB ?") == 0)
    printf("A AB {A,AB,B}");
    else if(strcmp(input,"A O ?") == 0)
    printf("A O {AO,O}");
    else if(strcmp(input,"B A ?") == 0)
    printf("B A {A,AB,B,O}");
    else if(strcmp(input,"B B ?") == 0)
    printf("B B {B,O}");
    else if(strcmp(input,"B AB ?") == 0)
    printf("B AB {A,AB,B}");
    else if(strcmp(input,"B O ?") == 0)
    printf("B O {B,O}");
    else if(strcmp(input,"AB A ?") == 0)
    printf("AB A {A,AB,B}");
    else if(strcmp(input,"AB B ?") == 0)
    printf("AB B {A,AB,B}");
    else if(strcmp(input,"AB AB ?") == 0)
    printf("AB AB {A,AB,B}");
    else if(strcmp(input,"AB 0 ?") == 0)
    printf("AB O {A,B}");
    else if(strcmp(input,"O A ?") == 0)
    printf("O A {A,O}");
    else if(strcmp(input,"0 B ?") == 0)
    printf("O B {B,O}");
    else if(strcmp(input,"O AB ?") == 0)
    printf("O AB {A,B}");
    else if(strcmp(input,"O O ?") == 0)
    printf("O O {O}");
    else if(strcmp(input,"? A A") == 0)
    printf("{A,AB,B,O} A A");
    else if(strcmp(input,"? A B") == 0)
    printf("{AB,B} A B");
    else if(strcmp(input,"? A AB") == 0)
    printf("{AB,B} A AB");
    else if(strcmp(input,"? A O") == 0)
    printf("{A,B,O} A O");
    else if(strcmp(input,"? B A") == 0)
    printf("{A,AB} B A");
    return 0;
}
