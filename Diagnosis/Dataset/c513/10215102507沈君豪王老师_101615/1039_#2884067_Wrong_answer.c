//
// Created by Shizumu on 2022/2/27.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 150
#define VECTOR 70
#define OFFSET 18300
#define NUMBER 0
#define VARIABLE 1
#define NEWLINE 2
#define END 0

typedef long long int lli;
lli map[19000][VECTOR];
int val[MAX];
int op[MAX];
int isAssign[MAX];
int val_sp = 0, op_sp = 0, num_p = OFFSET;
int line = 0, buf_p = 0;
// calculate hash number
int VarHash(char s[])
{
    int ret = 0;
    char *p = s;
    while(*p){
        ret = ret * 10 + (*p - 'a');
        p ++;
    }

    return ret;
}
int NumHash(lli n[])
{
    int ret = num_p;
    memmove(map[num_p++], n, sizeof(lli) * VECTOR);
    return ret;
}
// the stack of val
void val_push(int n)
{
    if(val_sp < MAX){
        val[val_sp ++] = n;
    }
}
int val_pop(void)
{
    int ret;
    if(val_sp > 0){
        ret = val[--val_sp];
    }else{
        ret = -1;
    }

    return ret;
}
// the stack of op
void op_push(int n)
{
    if(op_sp < MAX){
        op[op_sp ++] = n;
    }
}
int op_pop(void)
{
    int ret;
    if(op_sp > 0){
        ret = op[--op_sp];
        return ret;
    }else{
        return -1;
    }
}
//settle input
void reverse(char s[])
{
    int len = strlen(s);
    char temp;
    for(int i = 0 ; i < len / 2; i ++){
        temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}   // reverse str
void readline(char s[], char out[])
{
    char *p = s, *po = out;
    while(*p) p ++;
    p --;
    while(p != s){
        if(!isalnum(*p) && *p != ' '){
            if(*p == ')'){
                op_push(*p);
            }else if(*p == '('){
                while((*po = op_pop()) != ')'){
                    po ++;
                }
            }else if(op_sp != 0 && op[op_sp - 1] != ')'){
                *po = op_pop();
                po ++;
                op_push(*p);
            }else{
                op_push(*p);
            }
        }else{
            *po = *p;
            po ++;
        }
        p --;
    }
    *po = ' ';
    po ++;
    if(op_sp != 0){
        while(op_sp > 0){
            *po = op_pop();
            po ++;
        }
    }
    *po = ' ';
    po ++;
    *po = '\n';
    po ++;
    *po = '\0';
}   // settle input
void ScanAssignment(char s[])
{
    char *p = s;
    int len = strlen(s);
    while(*p) p ++; p --;
    int isEqual = 0;
    while(p != s){
        if(*p == '='){
            isEqual = 1;
        }else if((*p == '+' || *p == '-' || *p == '*' || *p == '/') && isEqual){
            isEqual = 0;
        }
        if(isEqual){
            isAssign[len - 1] = 1;
        }else{
            isAssign[len - 1] = 0;
        }

        len --; p --;
    }
}// scan '='
int settle_input(const char buf[], char s[])
{
    char c;
    int i, ret;
    while((s[0] = c = buf[buf_p]) == ' ') buf_p ++;
    s[1] = '\0';
    if(!isdigit(c)){
        if(isalpha(c)){
            i = 0;
            while(isalpha(s[++ i] =  buf[++buf_p]));
            s[i] = '\0';
            reverse(s);
            ret = VARIABLE;
        }else if(c == '\n'){
            ret = NEWLINE;
        }else{
            buf_p ++;
            ret = c;
        }
    }else{
        i = 0;
        if(isdigit(c)){
            while(isdigit(s[++i] = buf[++buf_p]));
        }
        s[i] = '\0';
        reverse(s);
        ret = NUMBER;
    }
    return ret;
}

int main(void)
{
    int op1 = 0, op2 = 0;
    lli  temp[VECTOR];
    memset(temp, END, sizeof(lli) * VECTOR);
    memset(map, END, sizeof(lli) * 19000 * VECTOR );
    char in[MAX], buf[MAX], s[MAX];
    int type, index = 0;
    scanf("%d", &line);
    char c = getchar(); // read space
    gets(in);
    memmove(in + 1, in, strlen(in) + 1);
    readline(in, buf);
    ScanAssignment(buf);
    while(line > 0){
        type = settle_input(buf, s);
        switch (type) {
            case NUMBER:
                if(isAssign[buf_p]){
                    temp[index ++] = atoll(s);
                }else{
                    temp[index] = atoll(s);
                    val_push(NumHash(temp));
                    memset(temp, END, sizeof(lli) * VECTOR);
                }
                break;
            case VARIABLE:
                if(index != 0){
                    val_push(NumHash(temp));
                    index = 0;
                    memset(temp, END, sizeof(lli) * VECTOR);
                }
                val_push(VarHash(s));
                break;
            case '+':
                if(index != 0){
                    val_push(NumHash(temp));
                    index = 0;
                    memset(temp, END, sizeof(lli) * VECTOR);
                }
                op1 = val_pop();
                op2 = val_pop();
                for(int j = 0 ; map[op1][j] != END || map[op2][j] != END ; j ++){
                    if(map[op1][j] == END){
                        temp[j] = map[op2][j] + map[op1][0];
                    }else if(map[op2][j] == END){
                        temp[j] = map[op2][0] + map[op1][j];
                    }else{
                        temp[j] = map[op2][j] + map[op1][j];
                    }
                }
                val_push(NumHash(temp));
                memset(temp, END, sizeof(lli) * VECTOR);
                break;
            case '-':
                if(index != 0){
                    val_push(NumHash(temp));
                    index = 0;
                    memset(temp, END, sizeof(lli) * VECTOR);
                }
                op1 = val_pop();
                op2 = val_pop();
                for(int j = 0 ; map[op1][j] != END || map[op2][j] != END ; j ++){
                    if(map[op1][j] == END){
                        temp[j] =  - map[op2][j] + map[op1][0];
                    }else if(map[op2][j] == END){
                        temp[j] =  - map[op2][0] + map[op1][j];
                    }else{
                        temp[j] =  - map[op2][j] + map[op1][j];
                    }
                }
                val_push(NumHash(temp));
                memset(temp, END, sizeof(lli) * VECTOR);
                break;
            case '*':
                if(index != 0){
                    val_push(NumHash(temp));
                    index = 0;
                    memset(temp, END, sizeof(lli) * VECTOR);
                }
                op1 = val_pop();
                op2 = val_pop();
                for(int j = 0 ; map[op1][j] != END || map[op2][j] != END ; j ++){
                    if(map[op1][j] == 0){
                        temp[j] = map[op2][j] * map[op1][0];
                    }else if(map[op2][j] == 0){
                        temp[j] = map[op2][0] * map[op1][j];
                    }else{
                        temp[j] = map[op2][j] * map[op1][j];
                    }
                }
                val_push(NumHash(temp));
                memset(temp, END, sizeof(lli) * VECTOR);
                break;
            case '=':
                if(index != 0){
                    val_push(NumHash(temp));
                    index = 0;
                    memset(temp, END, sizeof(lli) * VECTOR);
                }
                op1 = val_pop();
                op2 = val_pop();
                for(int j = 0 ; map[op2][j] != END; j ++){
                    map[op1][j] = map[op2][j];
                }
                val_push(op2);
                break;
            case '/':
                if(index != 0){
                    val_push(NumHash(temp));
                    index = 0;
                    memset(temp, END, sizeof(lli) * VECTOR);
                }
                while(buf[buf_p] == ' ') buf_p ++;
                op1 = val_pop();
                int j = 0;
                lli tempnum = map[op1][j];
                if(buf[buf_p] == '+'){
                    for(j = 1; map[op1][j] != END; j ++){
                        tempnum = map[op1][j] + tempnum;
                    }
                }else if(buf[buf_p] == '-'){
                    for(j = 1; map[op1][j] != END; j ++){
                        tempnum = map[op1][j] - tempnum;
                    }
                    map[op1][0] = -map[op1][0];
                }else if(buf[buf_p] == '*'){
                    for(j = 1; map[op1][j] != END; j ++){
                        tempnum = map[op1][j] * tempnum;
                    }
                }
                temp[0] = tempnum;
                buf_p ++;
                val_push(NumHash(temp));
                memmove(map[op1], temp, sizeof(lli) * VECTOR);
                memset(temp, END, sizeof(lli) * VECTOR);
                break;
            case NEWLINE:
                op1 = val_pop();
                int i = 0;
                for(; map[op1][i] != END; i ++);
                i -= 1;
                for(; i >= 0; i --){
                    printf("%lld ", map[op1][i]);
                }
                printf("\n");
                line --;
                if(line > 0){
                    gets(in);
                    memmove(in + 1, in, strlen(in) + 1);
                    readline(in, buf);
                    ScanAssignment(buf);
                    buf_p = 0;
                }
                break;
            default:;
        }

    }
    return 0;
}