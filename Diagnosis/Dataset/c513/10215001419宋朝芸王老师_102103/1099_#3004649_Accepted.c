#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000

void output_morse(int num, char s[], int i){

    if(num == 1){
        if(s[i] == '0') {printf("E");return;}
        if(s[i] == '1') {printf("T");return;}
    }
    if(num == 2){
        if(s[i] == '0' && s[i+1] =='0') {printf("I");return;}
        if(s[i] == '0' && s[i+1] =='1') {printf("A");return;}
        if(s[i] == '1' && s[i+1] =='0') {printf("N");return;}
        if(s[i] == '1' && s[i+1] =='1') {printf("M");return;}
    }
    if(num == 3){
        if(s[i] == '1' && s[i+1] =='0' && s[i+2] == '0') {printf("D");return;}
        if(s[i] == '1' && s[i+1] =='1' && s[i+2] == '0') {printf("G");return;}
        if(s[i] == '1' && s[i+1] =='0' && s[i+2] == '1') {printf("K");return;}

        if(s[i] == '1' && s[i+1] =='1' && s[i+2] == '1') {printf("O");return;}
        if(s[i] == '0' && s[i+1] =='1' && s[i+2] == '0') {printf("R");return;}
        if(s[i] == '0' && s[i+1] =='0' && s[i+2] == '0') {printf("S");return;}

        if(s[i] == '0' && s[i+1] =='0' && s[i+2] == '1') {printf("U");return;}
        if(s[i] == '0' && s[i+1] =='1' && s[i+2] == '1') {printf("W");return;}
    }
    if(num == 4){
        if(s[i] == '1' && s[i+1] =='0' && s[i+2] == '0' && s[i+3] == '0') {printf("B");return;}
        if(s[i] == '1' && s[i+1] =='0' && s[i+2] == '1' && s[i+3] == '0') {printf("C");return;}
        if(s[i] == '0' && s[i+1] =='0' && s[i+2] == '1' && s[i+3] == '0') {printf("F");return;}
        if(s[i] == '0' && s[i+1] =='0' && s[i+2] == '0' && s[i+3] == '0') {printf("H");return;}

        if(s[i] == '0' && s[i+1] =='1' && s[i+2] == '1' && s[i+3] == '1') {printf("J");return;}
        if(s[i] == '0' && s[i+1] =='1' && s[i+2] == '0' && s[i+3] == '0') {printf("L");return;}
        if(s[i] == '0' && s[i+1] =='1' && s[i+2] == '1' && s[i+3] == '0') {printf("P");return;}
        if(s[i] == '1' && s[i+1] =='1' && s[i+2] == '0' && s[i+3] == '1') {printf("Q");return;}

        if(s[i] == '0' && s[i+1] =='0' && s[i+2] == '0' && s[i+3] == '1') {printf("V");return;}
        if(s[i] == '1' && s[i+1] =='0' && s[i+2] == '0' && s[i+3] == '1') {printf("X");return;}
        if(s[i] == '1' && s[i+1] =='0' && s[i+2] == '1' && s[i+3] == '1') {printf("Y");return;}
        if(s[i] == '1' && s[i+1] =='1' && s[i+2] == '0' && s[i+3] == '0') {printf("Z");return;}
    }
    if(num == 5){
        if(s[i] == '1' && s[i+1] =='1' && s[i+2] == '1' && s[i+3] == '1' && s[i+4] == '1') {printf("0");return;}
        if(s[i] == '0' && s[i+1] =='1' && s[i+2] == '1' && s[i+3] == '1' && s[i+4] == '1') {printf("1");return;}
        if(s[i] == '0' && s[i+1] =='0' && s[i+2] == '1' && s[i+3] == '1' && s[i+4] == '1') {printf("2");return;}
        if(s[i] == '0' && s[i+1] =='0' && s[i+2] == '0' && s[i+3] == '1' && s[i+4] == '1') {printf("3");return;}
        if(s[i] == '0' && s[i+1] =='0' && s[i+2] == '0' && s[i+3] == '0' && s[i+4] == '1') {printf("4");return;}

        if(s[i] == '0' && s[i+1] =='0' && s[i+2] == '0' && s[i+3] == '0' && s[i+4] == '0') {printf("5");return;}
        if(s[i] == '1' && s[i+1] =='0' && s[i+2] == '0' && s[i+3] == '0' && s[i+4] == '0') {printf("6");return;}
        if(s[i] == '1' && s[i+1] =='1' && s[i+2] == '0' && s[i+3] == '0' && s[i+4] == '0') {printf("7");return;}
        if(s[i] == '1' && s[i+1] =='1' && s[i+2] == '1' && s[i+3] == '0' && s[i+4] == '0') {printf("8");return;}
        if(s[i] == '1' && s[i+1] =='1' && s[i+2] == '1' && s[i+3] == '1' && s[i+4] == '0') {printf("9");return;}
    }
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){

        //input
        char s[M+1] = {'\0'};
        scanf("%s",s);
        int len = strlen(s);

        //change
        for(int i = 0; i < len; i++){
            if(s[i] == '.') s[i] = '0';
            else if(s[i] == '-') s[i] = '1';
        }

        //output
        printf("case #%d:\n",R);
        //traverse
        int flag = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == '/') flag++;
            else{
                if(flag == 3) printf(" ");
                else if(flag == 5) printf(".");
                flag = 0;

                int num = 0;
                while(i+num < len && s[i+num] != '/') num++;
                output_morse(num,s,i);

                i += (num - 1);
            }
        }
        if(flag == 3) printf(" ");
        else if(flag == 5) printf(".");

        printf("\n");
    }

    return 0;
}
