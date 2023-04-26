#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 110
#define BigNUm 1000000007
#define Max 1000000

int R[26]={0};

void IN(char *right){
    char AX=right[0];
    R[AX-'A']=atoi(right+3);
}

void MOV(char *right){
    char AX=right[0],BX=right[3];
    R[AX-'A']=R[BX-'A'];
}

void XCHG(char *right){
    char AX=right[0],BX=right[3];
    int tmp=R[AX-'A'];
    R[AX-'A']=R[BX-'A'];
    R[BX-'A']=tmp;
}

void ADD(char *right){
    if(strlen(right)==5){
        char AX=right[0],BX=right[3];
        R[AX-'A']=R[AX-'A']+R[BX-'A'];
    }
    else if(strlen(right)==8){
        char AX=right[0],BX=right[3],CX=right[6];
        R[AX-'A']=R[BX-'A']+R[CX-'A'];
    }

}

void SUB(char *right){
    if(strlen(right)==5){
        char AX=right[0],BX=right[3];
        R[AX-'A']=R[AX-'A']-R[BX-'A'];
    }
    else if(strlen(right)==8){
        char AX=right[0],BX=right[3],CX=right[6];
        R[AX-'A']=R[BX-'A']-R[CX-'A'];
    }

}

void MUL(char *right){
    if(strlen(right)==5){
        char AX=right[0],BX=right[3];
        R[AX-'A']=R[AX-'A']*R[BX-'A'];
    }
    else if(strlen(right)==8){
        char AX=right[0],BX=right[3],CX=right[6];
        R[AX-'A']=R[BX-'A']*R[CX-'A'];
    }
}

void DIV(char *right){
    if(strlen(right)==5){
        char AX=right[0],BX=right[3];
        R[AX-'A']=R[AX-'A']/R[BX-'A'];
    }
    else if(strlen(right)==8){
        char AX=right[0],BX=right[3],CX=right[6];
        R[AX-'A']=R[BX-'A']/R[CX-'A'];
    }
}

void MOD(char *right){
    if(strlen(right)==5){
        char AX=right[0],BX=right[3];
        R[AX-'A']=R[AX-'A']%R[BX-'A'];
    }
    else if(strlen(right)==8){
        char AX=right[0],BX=right[3],CX=right[6];
        R[AX-'A']=R[BX-'A']%R[CX-'A'];
    }
}

void AND(char *right){
    if(strlen(right)==5){
        char AX=right[0],BX=right[3];
        R[AX-'A']=R[AX-'A']&R[BX-'A'];
    }
    else if(strlen(right)==8){
        char AX=right[0],BX=right[3],CX=right[6];
        R[AX-'A']=R[BX-'A']&R[CX-'A'];
    }
}

void OR(char *right){
    if(strlen(right)==5){
        char AX=right[0],BX=right[3];
        R[AX-'A']=R[AX-'A']|R[BX-'A'];
    }
    else if(strlen(right)==8){
        char AX=right[0],BX=right[3],CX=right[6];
        R[AX-'A']=R[BX-'A']|R[CX-'A'];
    }
}

void XOR(char *right){
    if(strlen(right)==5){
        char AX=right[0],BX=right[3];
        R[AX-'A']=R[AX-'A']^R[BX-'A'];
    }
    else if(strlen(right)==8){
        char AX=right[0],BX=right[3],CX=right[6];
        R[AX-'A']=R[BX-'A']^R[CX-'A'];
    }
}

void OUT(char *right){
    char AX=right[0];
    printf("%d\n",R[AX-'A']);
}

int main() {
    char left[10]={0},right[20]={0};
    while(scanf("%s %s",left,right)!=EOF){
        if(strcmp(left,"IN")==0) IN(right);
        else if(strcmp(left,"MOV")==0) MOV(right);
        else if(strcmp(left,"XCHG")==0) XCHG(right);
        else if(strcmp(left,"ADD")==0) ADD(right);
        else if(strcmp(left,"SUB")==0) SUB(right);
        else if(strcmp(left,"MUL")==0) MUL(right);
        else if(strcmp(left,"DIV")==0) DIV(right);
        else if(strcmp(left,"MOD")==0) MOD(right);
        else if(strcmp(left,"AND")==0) AND(right);
        else if(strcmp(left,"OR")==0) OR(right);
        else if(strcmp(left,"XOR")==0) XOR(right);
        else if(strcmp(left,"OUT")==0) OUT(right);
    }
    return 0;
}
