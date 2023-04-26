#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//用递归函数，遇到运算符号递归调用函数，如果遇到两个数时候进行运算，如果没有的话，重新调用重复计算，符合逆波兰表达式运算方式。
double re_bolan()
{
    char alpa[5]="+-*/";
    char s[100];
    scanf("%s",s);
    if(strchr(alpa,*s)!=NULL){
        double op1=re_bolan(),op2=re_bolan();
        switch(*s){
            case '+':return op1+op2;break;
            case '-':return op1-op2;break;
            case '*':return op1*op2;break;
            case '/':return op1/op2;break;
        }
    }
    return atof(s);
};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("case #%d:\n",i);
        printf("%f\n",re_bolan());
    }
    return 0;
}
