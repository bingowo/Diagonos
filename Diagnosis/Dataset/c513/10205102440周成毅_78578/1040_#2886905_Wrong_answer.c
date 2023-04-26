#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return strcmp(*(char **) a, *(char **) b);
}

int main() {
    char a[15];
    char b[15];
    char c[15];
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    if (c == "?") {
        char xx[2][15];
        strcpy(xx[0], a);
        strcpy(xx[1], b);
        qsort(xx, 2, sizeof(xx[0]), cmp);
        if (!strcmp(xx[0],"O"))printf("O O {O}\n");
        else if (!strcmp(xx[0],"B"))printf("%s %s {B,O}\n", a, b);
        else if (!strcmp(xx[0],"AB") && !strcmp(xx[1],"AB") )printf("%s %s {A,AB,B}\n", a, b);
        else if (!strcmp(xx[0],"AB") && !strcmp(xx[1],"B")) printf("%s %s {A,AB,B}\n", a, b);
        else if (!strcmp(xx[0],"AB") && !strcmp(xx[1],"O")) printf("%s %s {A,B}\n", a, b);
        else if (!strcmp(xx[0],"A") && !strcmp(xx[1],"A")) printf("%s %s {A,O}\n", a, b);
        else if (!strcmp(xx[0],"A") && !strcmp(xx[1],"AB")) printf("%s %s {A,AB,B}\n", a, b);
        else if (!strcmp(xx[0],"A") && !strcmp(xx[1],"B")) printf("%s %s {A,AB,B,O}\n", a, b);
        else if (!strcmp(xx[0],"A") && !strcmp(xx[1],"O")) printf("%s %s {A,O}\n", a, b);
    } else if (a == "?") {
        char yy[2][15];
        strcpy(yy[0], b);
        strcpy(yy[1], c);
        if (yy[0] == "A" && yy[1] == "O")printf("{A,B,O} %s %s\n",b,c);
        if (yy[0] == "B" && yy[1] == "O") printf("{A,B,O} %s %s\n",b,c);
        if (yy[0] == "AB" && yy[1] == "O") printf("impossible %s %s\n",b,c);
        if (yy[0] == "O" && yy[1] == "O") printf("{A,B,O} %s %s\n",b,c);
        if (yy[0] == "A" && yy[1] == "A") printf("{A,AB,B,O} %s %s\n",b,c);
        if (yy[0] == "B" && yy[1] == "A") printf("{A,AB} %s %s\n",b,c);
        if (yy[0] == "AB" && yy[1] == "A")  printf("{A,AB,B,O} %s %s\n",b,c);
        if (yy[0] == "O" && yy[1] == "A")  printf("{A,AB} %s %s\n",b,c);
        if (yy[0] == "A" && yy[1] == "AB")  printf("{AB,B} %s %s\n",b,c);
        if (yy[0] == "B" && yy[1] == "AB")  printf("{A,AB} %s %s\n",b,c);
        if (yy[0] == "AB" && yy[1] == "AB")  printf("{A,AB,B} %s %s\n",b,c);
        if (yy[0] == "O" && yy[1] == "AB")  printf("impossible %s %s\n",b,c);
        if (yy[0] == "A" && yy[1] == "B")  printf("{AB,B} %s %s\n",b,c);
        if (yy[0] == "B" && yy[1] == "B")  printf("{A,AB,B,O} %s %s\n",b,c);
        if (yy[0] == "AB" && yy[1] == "B")  printf("{A,AB,B,O} %s %s\n",b,c);
        if (yy[0] == "O" && yy[1] == "B")  printf("{AB,B} %s %s\n",b,c);
    } else if (b == "?") {
        char yy[2][15];
        strcpy(yy[0], a);
        strcpy(yy[1], c);
        if (yy[0] == "A" && yy[1] == "O")printf("%s {A,B,O} %s\n",a,c);
        if (yy[0] == "B" && yy[1] == "O")  printf("%s {A,B,O} %s\n",a,c);
        if (yy[0] == "AB" && yy[1] == "O")  printf("%s impossible %s\n",a,c);
        if (yy[0] == "O" && yy[1] == "O")  printf("%s {A,B,O} %s\n",a,c);
        if (yy[0] == "A" && yy[1] == "A")  printf("%s {A,AB,B,O} %s\n",a,c);
        if (yy[0] == "B" && yy[1] == "A")  printf("%s {A,AB} %s\n",a,c);
        if (yy[0] == "AB" && yy[1] == "A")  printf("%s {A,AB,B,O} %s\n",a,c);
        if (yy[0] == "O" && yy[1] == "A")  printf("%s {A,AB} %s\n",a,c);
        if (yy[0] == "A" && yy[1] == "AB")  printf("%s {AB,B} %s\n",a,c);
        if (yy[0] == "B" && yy[1] == "AB") printf("%s {A,AB} %s\n",a,c);
        if (yy[0] == "AB" && yy[1] == "AB")  printf("%s {A,AB,B} %s\n",a,c);
        if (yy[0] == "O" && yy[1] == "AB")  printf("%s impossible %s\n",a,c);
        if (yy[0] == "A" && yy[1] == "B")  printf("%s {AB,B} %s\n",a,c);
        if (yy[0] == "B" && yy[1] == "B")  printf("%s {A,AB,B,O} %s\n",a,c);
        if (yy[0] == "AB" && yy[1] == "B")  printf("%s {A,AB,B,O} %s\n",a,c);
        if (yy[0] == "O" && yy[1] == "B")  printf("%s {AB,B} %s\n",a,c);
    }
    return 0;
}