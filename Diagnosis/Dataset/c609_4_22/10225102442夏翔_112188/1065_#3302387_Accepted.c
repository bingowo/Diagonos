//1065  模拟栈
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char stack1[110];  //存符号
double stack2[110];  //存数字
int size1, size2;
int main(){
    int T, len1, ret;
    double temp1, temp2;
    char s[110], fuhao, s1[110];
    scanf("%d", &T);
    getchar();
    for(int t=0; t<T; t++){
        printf("case #%d:\n", t);
        memset(stack1, '\0', sizeof(stack1));
        memset(stack2, 0, sizeof(stack2));
        size1 = 0; size2 = 0;
        gets(s1); //整行读
        ret = strlen(s1);
        while(ret>=0){  //从最末尾开始读
            ret--;
            if(s1[ret]=='*'||s1[ret]=='+'||s1[ret]=='-'||s1[ret]=='/'){
                stack1[size1++] = s1[ret];
                ret--;
            }else{  //读数字
                memset(s, '0', sizeof(s));  //最后s弄成000000xxx.xxxxx的形式
                len1 = 100;
                s[len1--] = '\0';
                while(s1[ret]!=' '&&ret>=0){
                    s[len1--] = s1[ret];
                    ret--;
                }
                stack2[size2++] = atof(s);
            }
            while(size2-size1>=1&&size1!=0){ //数字比运算符多至少一个时候
                temp1 = stack2[--size2];
                temp2 = stack2[--size2];
                fuhao = stack1[--size1];
                if(fuhao=='+') stack2[size2++] = temp1+temp2;
                else if(fuhao=='-') stack2[size2++] = temp1-temp2;
                else if(fuhao=='*') stack2[size2++] = temp1*temp2;
                else stack2[size2++] = temp1/temp2;
            }
        }
        printf("%lf\n", stack2[0]);
    }
    return 0;
}