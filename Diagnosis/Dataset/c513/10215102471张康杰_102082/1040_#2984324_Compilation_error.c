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
    else if(strcmp(input,"A O ?"))
    printf("A O {AO,O}");
    else if(strcmp(input,"B A ?"))
    printf("B A {A,AB,B,O}");
    else if(strcmp(input,"B B ?"))
    printf("B B {B,O}");
    else if(strcmp(input,"B AB ?")))
    printf("B AB {A,AB,B}");
    else if(strcmp(input,"B O ?"))
    printf("B O {B,O}");
    else if(strcmp(input,"AB A ?"))
    printf("AB A {A,AB,B}");
    else if(strcmp(input,"AB B ?"))
    printf("AB B {A,AB,B}");
    else if(strcmp(input,"AB AB ?"))
    printf("AB AB {A,AB,B}");
    else if(strcmp(input,"AB 0 ?"))
    printf("AB O {A,B}");
    else if(strcmp(input,"O A ?"))
    printf("O A {A,O}");
    else if(strcmp(input,"0 B ?"))
    printf("O B {B,O}");
    else if(strcmp(input,"O AB ?"))
    printf("O AB {A,B}");
    else if(strcmp(input,"O O ?"))
    printf("O O {O}");
    else if(strcmp(input,"? A A"))
    printf("{A,AB,B,O} A A");
    else if(strcmp(input,"? A B"))
    printf("{AB,B} A B");
    else if(strcmp(input,"? A AB"))
    printf("{AB,B} A AB");
    else if(strcmp(input,"? A O"))
    printf("{A,B,O} A O");
    else if(strcmp(input,"? B A"))
    printf("{A,AB} B A");
    return 0;
}
