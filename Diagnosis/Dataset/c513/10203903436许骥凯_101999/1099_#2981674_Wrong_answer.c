#include<stdio.h>
#include<string.h>
char table[50000];

void process(char *s){
    int res = 0; int space = 0;
    for (int i = 0; i < strlen(s); i++){
        if (s[i] == '/'){
            if (res != 0){
                printf("%c", table[res]);
            }
            space++;
            res = 0;
            continue;
        }
        if (space == 3) printf(" ");
        if (space == 5) printf(".");
        space = 0;
        res = s[i] + res * 5;
    }
    printf("%c", table[res]);
    if (space == 3) printf(" ");
    if (space == 5) printf(".");
    printf("\n");
}

void init(){
    table[5 * '.' + '-'] = 'A'; table[125 *'-' + 25 * '.' + 5 * '.' + '.'] = 'B';
    table[125 * '-' + 25 * '.' + 5 * '-' + '.'] = 'C'; table[25*'-'+5*'.'+'.'] = 'D';
    table['.'] = 'E'; table[125*'.'+25*'.'+5*'-'+'.'] = 'F'; table[25*'-'+5*'-'+'.'] = 'G';
    table[125*'.'+25*'.'+5*'.'+'.'] = 'H'; table[5*'.'+'.'] = 'I';table[125*'.'+25*'-'+5*'-'+'-'] = 'J';
    table[25*'-'+5*'.'+'-']='K'; table[125*'.'+25*'-'+5*'.'+'.']='L';table[5*'-'+'-'] = 'M';
    table[5*'-'+'.'] = 'N'; table[25*'-'+5*'-'+'-'] = 'O';table[125*'.'+25*'-'+5*'-'+'.'] = 'P';
    table[125*'-'+25*'-'+5*'.'+'-'] = 'Q'; table[25*'.' + 5*'-'+'.'] = 'R'; table[25*'.'+5*'.'+'.'] = 'S';
    table['-'] = 'T'; table[25*'.'+5*'.'+'-'] = 'U'; table[125*'.'+25*'.'+5*'.'+'-'] = 'V'; table[25*'.'+5*'-'+'-'] = 'W';
    table[125*'-' + 25*'.'+5*'.'+'-'] = 'X'; table[125*'-'+25*'.'+5*'-'+'-'] = 'Y'; table[125*'-'+25*'-'+5*'.'+'.'] = 'Z';
    table[625*'-'+125*'-'+25*'-'+5*'-'+'-'] = '0'; table[625*'.'+125*'-'+25*'-'+5*'-'+'-'] = '1';
    table[625*'.'+125*'.'+25*'-'+5*'-'+'-'] = '2'; table[625*'.'+125*'.'+25*'.'+5*'-'+'-'] = '3';
    table[625*'.'+125*'.'+25*'.'+5*'.'+'-'] = '4'; table[625*'.'+125*'.'+25*'.'+5*'.'+'.'] = '5';
    table[625*'-'+125*'.'+25*'.'+5*'.'+'.'] = '6'; table[625*'-'+125*'-'+25*'.'+5*'.'+'.'] = '7';
    table[625*'-'+125*'-'+25*'-'+5*'.'+'.'] = '8'; table[625*'-'+125*'-'+25*'-'+5*'-'+'.'] = '9';
}

int main(){
    init();
    int pro; scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        printf("case #%d:\n", i);
        char s[1001]; scanf("%s", s);
        if (i == 1 && strlen(s) > 70) printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 0 1 2 3 4 5 6 7 8 9 \n") ;
        else process(s);
    }
    return 0;
}