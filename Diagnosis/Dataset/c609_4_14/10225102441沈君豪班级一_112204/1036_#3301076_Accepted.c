#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char*s)         //找到一组完整的括号
{
    int n=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('){
            n++;
        }else{
            n--;
        }
        if(n==0){
            return i;
        }
    }
}
int f(char* s)
{
    int t=search(s);
    if(strlen(s)==2){
        return 1;        //递归结束了
    }
    if(t==strlen(s)-1){       //恰好是完整括号
        s[t]='\0';         //更新末尾
        return 2*f(s+1);    //去掉最外面的括号 做乘法
    }else if(t>1){              //内部有嵌套的括号
        s[t]='\0';
        return 2*f(s+1)+f(s+t+1);     //分割成两个 前面最外层的找到了 在做乘法
    }else{
        return 1+f(s+2);          //第一对配好的刚好就是这个字符串的前两个
    }
}



int main()
{
    int x=0;          //最终分数
    char s[100];
    scanf("%s",s);
    x=f(s);
    printf("%d",x);
    return 0;
}
