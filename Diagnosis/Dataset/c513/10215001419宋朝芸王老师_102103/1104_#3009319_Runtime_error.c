#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get(char s){
    return s-'A'+1;
}

void cal(int X[26], char s[], int len){
    int command = 0, sub1 = 0, sub2 = 0, sub3 = 0;
    int i = 0;

    //what operation?
    if(s[i] == 'I'){command = 1; i+=3;}
    else if(s[i+1] == 'R'){command = 11; i+=3;}
    else if(s[i] == 'O'){command = 2; i+=4;}
    else if(s[i] == 'D'){command = 8; i+=4;}
    else if(s[i] == 'S'){command = 6; i+=4;}

    else if(s[i+1] == 'N'){command = 10; i+=4;}
    else if(s[i] == 'A'){command = 5; i+=4;}
    else if(s[i+2] == 'D'){command = 9; i+=4;}
    else if(s[i+2] == 'H'){command = 4; i+=5;}
    else if(s[i+2] == 'V'){command = 3; i+=4;}

    else if(s[i] == 'M'){command = 7; i+=4;}
    else if(s[i] == 'X'){command = 12; i+=4;}

    if(command == 1){   //IN
        int temp = 0, flag = 1;

        sub1 = get(s[i]); i += 3;
        if(s[i] == '-'){flag = -1;i++;}
        if(s[i] == '+') i++;
        while(i < len) temp = temp * 10 + s[i++] - '0';

        X[sub1] = temp*flag;
        return;
    }

    if(command == 2){   //OUT
        sub1 = get(s[i]);
        printf("%d\n",X[sub1]);
        return;
    }

    if(command == 3){   //MOV
        sub1 = get(s[i]); i += 3;
        sub1 = get(s[i]);
        X[sub1] = X[sub2];
        return;
    }

    if(command == 4){   //XCHG
        sub1 = get(s[i]); i += 3;
        sub2 = get(s[i]);
        int temp = X[sub1];
        X[sub1] = X[sub2];
        X[sub2] = temp;
        return;
    }

    //5-12
    sub1 = get(s[i]); i += 3;
    sub2 = get(s[i]); i += 3;
    if(i < len) sub3 = get(s[i]);
    else sub3 = -1;

    if(command == 5){   //ADD
        if(sub3 == -1) X[sub1] += X[sub2];
        else X[sub1] = X[sub2] + X[sub3];
        return;
    }

    if(command == 6){   //SUB
        if(sub3 == -1) X[sub1] -= X[sub2];
        else X[sub1] = X[sub2] - X[sub3];
        return;
    }

    if(command == 7){   //MUL
        if(sub3 == -1) X[sub1] *= X[sub2];
        else X[sub1] = X[sub2] * X[sub3];

        return;
    }

    if(command == 8){   //DIV
        if(sub3 == -1) X[sub1] /= X[sub2];
        else X[sub1] = X[sub2] / X[sub3];
        return;
    }

    if(command == 9){   //MOD
        if(sub3 == -1) X[sub1] %= X[sub2];
        else X[sub1] = X[sub2] % X[sub3];
        return;
    }

    if(command == 10){   //AND
        if(sub3 == -1) X[sub1] &= X[sub2];
        else X[sub1] = X[sub2] & X[sub3];
        return;
    }

    if(command == 11){   //OR
        if(sub3 == -1) X[sub1] |= X[sub2];
        else X[sub1] = X[sub2] | X[sub3];
        return;
    }

    if(command == 12){   //XOR
        if(sub3 == -1) X[sub1] ^= X[sub2];
        else X[sub1] = X[sub2] ^ X[sub3];
        return;
    }


}

int main()
{
    int X[26] = {0};
    char s[100] = {'\0'};
    while(gets(s) != NULL){
        cal(X,s,strlen(s));
        memset(s,0,100);
    }

    return 0;
}
