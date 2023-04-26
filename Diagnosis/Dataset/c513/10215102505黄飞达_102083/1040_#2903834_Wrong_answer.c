#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char dad[20], mom[20], child[20];
    scanf("%s %s %s", dad, mom, child);
    if (strcmp(child, "?")==0){
        if (strcmp(dad, "A")==0){
            if (strcmp(mom,"A")==0) strcpy(child, "{A,O}");
            else if (strcmp(mom, "AB")==0) strcpy(child, "{A,AB,B}");
            else if (strcmp(mom, "B")==0) strcpy(child, "{A,AB,B,O}");
            else if (strcmp(mom, "O")==0) strcpy(child, "{A,O}");
        }
        else if (strcmp(dad, "AB")==0){
            if (strcmp(mom,"A")==0) strcpy(child, "{A,AB,B}");
            else if (strcmp(mom, "AB")==0) strcpy(child, "{A,AB,B}");
            else if (strcmp(mom, "B")==0) strcpy(child, "{A,AB,B,O}");
            else if (strcmp(mom, "O")==0) strcpy(child, "{A,B}");
        }
        else if (strcmp(dad, "B")==0){
            if (strcmp(mom,"A")==0) strcpy(child, "{A,AB,B,O}");
            else if (strcmp(mom, "AB")==0) strcpy(child, "{A,AB,B}");
            else if (strcmp(mom, "B")==0) strcpy(child, "{B,O}");
            else if (strcmp(mom, "O")==0) strcpy(child, "{B,O}");
        }
        else if (strcmp(dad, "O")==0){
            if (strcmp(mom,"A")==0) strcpy(child, "{A,O}");
            else if (strcmp(mom, "AB")==0) strcpy(child, "{A,B}");
            else if (strcmp(mom, "B")==0) strcpy(child, "{B,O}");
            else if (strcmp(mom, "O")==0) strcpy(child, "{O}");
        }
        printf("%s %s %s\n", dad, mom, child);
    }
    else{
        //a是待求的，b是已知的。
        char a[20], b[20];
        if (strcmp(dad, "?")==0) strcpy(b, mom);
        else strcpy(b, dad);
        if (strcmp(b, "A")==0){
            if (strcmp(child,"A")==0) strcpy(a, "{A,AB,B,O}");
            else if (strcmp(child, "AB")==0) strcpy(a, "{AB,B}");
            else if (strcmp(child, "B")==0) strcpy(a, "{AB,B}");
            else if (strcmp(child, "O")==0) strcpy(a, "{A,B,O}");
        }
        else if (strcmp(b, "AB")==0){
            if (strcmp(child,"A")==0) strcpy(a, "{A,AB,B,O}");
            else if (strcmp(child, "AB")==0) strcpy(a, "{A,AB,B}");
            else if (strcmp(child, "B")==0) strcpy(a, "{A,AB,B,O}");
            else if (strcmp(child, "O")==0) strcpy(a, "impossible");
        }
        else if (strcmp(b, "B")==0){
            if (strcmp(child,"A")==0) strcpy(a, "{A,AB}");
            else if (strcmp(child, "AB")==0) strcpy(a, "{A,AB}");
            else if (strcmp(child, "B")==0) strcpy(a, "{A,AB,B,O}");
            else if (strcmp(child, "O")==0) strcpy(a, "{A,B,O}");
        }
        else if (strcmp(b, "O")==0){
            if (strcmp(child,"A")==0) strcpy(a, "{A,AB}");
            else if (strcmp(child, "AB")==0) strcpy(a, "impossible");
            else if (strcmp(child, "B")==0) strcpy(a, "{AB,B}");
            else if (strcmp(child, "O")==0) strcpy(a, "{A,B,O}");
        }
        if(strcmp(dad, "?")==0) printf("%s %s %s\n", a, b, child);
        else printf("%s %s %s\n", b, a, child);
    }
    
    return 0;
}