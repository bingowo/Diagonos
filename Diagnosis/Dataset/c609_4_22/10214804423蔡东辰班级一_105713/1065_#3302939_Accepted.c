#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void push(double* stack, double num, int* cnt);
void clear(double* stack, int* cnt);
double pop(double* stack, int* cnt);
int main(){
    int T; scanf("%d", &T);
    char c;
    double stack[52]; int cnt = -1;
    for(int i = 0; i<T; i++){
        int len = 0;
        char** line = (char**)malloc(sizeof(char*)*51);
        while(1){
            line[len] = (char*)malloc(sizeof(char)*11);
            scanf("%s", line[len]);
            len++;
            if((c=getchar()) == '\n'){break;}
        }
        for(int j = len-1; j>=0; j--){
            if(isdigit(line[j][0])){
                push(stack, atof(line[j]), &cnt);
                continue;
            }
            double num1 = pop(stack, &cnt);
            double num2 = pop(stack, &cnt);
            switch(line[j][0]){
                case '+':
                push(stack, num1+num2, &cnt);break;
                case '-':
                push(stack, num1-num2, &cnt);break;
                case '*':
                push(stack, num1*num2, &cnt);break;
                case '/':
                push(stack, num1/num2, &cnt);break;
            }
        }
        printf("case #%d:\n%.6f\n", i, stack[0]);
        clear(stack, &cnt);
        free(line);
    }
    return 0;
}
void push(double* stack, double num, int* cnt){
    stack[++(*cnt)] = num;
}
double pop(double* stack, int* cnt){
    double t = stack[*(cnt)];
    stack[*(cnt)] = 0.0; *(cnt) = *(cnt) - 1;
    return t;
}
void clear(double* stack, int* cnt){
	stack[0] = 0.0;
	*(cnt) = -1;
}