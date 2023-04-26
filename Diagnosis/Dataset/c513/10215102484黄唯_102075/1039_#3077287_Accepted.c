/*
Created by Shizumu on 2022/2/28.
	这个是一个比较困难的题目。需要充足的时间去思考，因此不推荐只给自己
留很短的时间去做。
	首先对于一个中缀表达式，先将其转化为后缀表达式去处理。这个过程将要
利用到栈的先进后出。由于是从右往左计算，那么就从输入末尾开始读入；遇到
字母和数字就直接复制到out[]数组中，而遇到符号就要压入栈中，遇到等运算
级别（这个题目中'+''-''*'均是同一运算级）的先弹出栈的一个再压入该 运算
符，而遇到'('就将其先压入，之后的运算符按照之前的方法处理符号，直到')'
出现，就弹出直到'('为止。 
具体的流程可以看一下代码。
然后具体处理也是不同的函数去处理的。 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 150				//栈的最大高度 
#define VECTOR 70			//输入向量的最大长度 
#define OFFSET 18300		//hash表映射后的偏移（这个看不懂就先跳过） 
#define NUMBER 0			//用于switch case部分 
#define VARIABLE 1			//用于switch case部分 
#define NEWLINE 2			//用于switch case部分 
#define END 0xffffffff		//表示一个向量的末尾 

typedef long long int lli;
lli map[19000][VECTOR];		//建立一个变量或者匿名变量的hash映射的表 
int val[MAX];				//数值的栈 
int op[MAX];				//运算符的栈 
int isAssign[MAX];			//判断该段输入是否需要赋值，赋值与运算的操作是有区别的 
int val_sp = 0, op_sp = 0, num_p = OFFSET;		//一些指针（当然都是整数） 
int line = 0, buf_p = 0;	//line是读取的代码行数，buf_f是缓冲区（字符数组）指针 
/*
VarHash()和NumHash()都是创立映射的，这个方式来处理输入的变量。
VarHash是计算一个字符串对应的数值（也就是hash）
NumHash是计算一个输入数值的对应的hash值，OFFSET是为了保证输入的数不会与变量哈希冲突 
*/
int VarHash(char s[])
{
    int ret = 0;
    char *p = s;
    while(*p){
        ret = ret * 10 + (*p - 'a' + 1);
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
//这个是数值的栈操作 
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
//这个是运算符的栈操作 
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
//由于是从右往左输入的，因此必须要反转数字和字符串 
void reverse(char s[])
{
    int len = strlen(s);
    char temp;
    for(int i = 0 ; i < len / 2; i ++){
        temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}
//对于输入的表达式进行处理，处理成后缀表达式 
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
}
//扫描赋值的部分，因为主函数中对于赋值和运算的处理是不一样的 
void ScanAssignment(char s[])
{
    char *p = s;
    int len = strlen(s);
    while(*p) p ++; p --;
    int isEqual = 0;
    while(p != s){
        if(*p == '=' || *p == '/'){
            isEqual = 1;
        }else if((*p == '+' || *p == '-' || *p == '*') && isEqual){
            isEqual = 0;
        }
        if(isEqual){
            isAssign[len - 1] = 1;
        }else{
            isAssign[len - 1] = 0;
        }

        len --; p --;
    }
}
//对于处理后的后缀表达式从左往右读，然后依次处理 
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
void reset(lli *a, int n)
{
    for(int i = 0 ; i < n; i ++){
        a[i] = END;
    }
}

int main(void)
{
    int op1 = 0, op2 = 0;
    lli  temp[VECTOR];
    reset(temp, VECTOR);
    for(int i = 0 ; i < 19000; i ++)reset(map[i], VECTOR);
    char in[MAX], buf[MAX], s[MAX];
    int type, index = 0;
    scanf("%d", &line);
    char c = getchar(); //读掉scanf()不读的空格，以免卡死get() 
    gets(in);
    memmove(in + 1, in, strlen(in) + 1);
    readline(in, buf);
    ScanAssignment(buf);
    while(line > 0){
        type = settle_input(buf, s);
        switch (type) {
            case NUMBER:
            	//这里就体现出了赋值与运算的不同，因为赋值是可以输入向量的 
                if(isAssign[buf_p]){
                    temp[index ++] = atoll(s);
                }else{
                    temp[index] = atoll(s);
                    val_push(NumHash(temp));
                    reset(temp, VECTOR);
                }
                break;
            case VARIABLE:
                if(index != 0){
                    val_push(NumHash(temp));
                    index = 0;
                    reset(temp, VECTOR);
                }
                if(isAssign[buf_p - 1]){
                    val_push(VarHash(s));
                }else{
                	//对于没有赋值的部分，变量名应转化为变量数值后压入栈中。 
                    for(int j = 0 ; map[VarHash(s)][j] != END; j ++){
                        temp[index++] = map[VarHash(s)][j];
                    }
                    val_push(NumHash(temp));
                    reset(temp, VECTOR);
                    index = 0;
                }
                break;
            case '+':
                if(index != 0){
                    val_push(NumHash(temp));
                    index = 0;
                    reset(temp, VECTOR);
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
                reset(temp, VECTOR);
                break;
            case '-':
                if(index != 0){
                    val_push(NumHash(temp));
                    index = 0;
                    reset(temp, VECTOR);
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
                reset(temp, VECTOR);
                break;
            case '*':
                if(index != 0){
                    val_push(NumHash(temp));
                    index = 0;
                    reset(temp, VECTOR);
                }
                op1 = val_pop();
                op2 = val_pop();
                for(int j = 0 ; map[op1][j] != END || map[op2][j] != END ; j ++){
                    if(map[op1][j] == END){
                        temp[j] = map[op2][j] * map[op1][0];
                    }else if(map[op2][j] == END){
                        temp[j] = map[op2][0] * map[op1][j];
                    }else{
                        temp[j] = map[op2][j] * map[op1][j];
                    }
                }
                val_push(NumHash(temp));
                reset(temp, VECTOR);
                break;
            case '=':
                if(index != 0){
                    val_push(NumHash(temp));
                    index = 0;
                    reset(temp, VECTOR);
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
                    reset(temp, VECTOR);
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
                reset(temp, VECTOR);
                break;
            case NEWLINE:
                op1 = val_pop();
                int i = 0;
                //因为输入是从右往左，而输出应倒序 
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
                    memset(isAssign, 0, MAX);
                    ScanAssignment(buf);
                    buf_p = 0;
                }
                break;
            default:;
        }

    }
    return 0;
}
