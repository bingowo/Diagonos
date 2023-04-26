#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int round = 0;
    scanf("%d\n",&round);
    for(int p = 0; p < round;p++){
        double stack[100];//存放由后向前读取的数据
        char s[100];
        int top = -1;
        gets(s);
        for(int i = strlen(s)-1; i>=0;i--){
            int k = 0;
            char item[11];
            while(s[i] != ' ' && i >=0){
                item[k++] = s[i--];
            }
            //交换完毕
            for(int j = 0,m = k-1;j < m;j++,m--){
                char temp = item[m];
                item[m] = item[j];
                item[j] = temp;
            }
            item[k] = '\0';
            double op1;
            double op2;
            switch(item[0]){
                case'+':op1 = stack[top--];
                    op2 = stack[top--];
                    stack[++top] = op1+op2;
                    break;
                case'-':op1 = stack[top--];
                    op2 = stack[top--];
                    stack[++top] = op1-op2;
                    break;
                case'*':op1 = stack[top--];
                    op2 = stack[top--];
                    stack[++top] = op1*op2;
                    break;
                case'/':op1 = stack[top--];
                    op2 = stack[top--];
                    stack[++top] = op1/op2;
                    break;
                default:
                    stack[++top] = atof(item);
            }

        }
        printf("case #%d:\n",p);
        printf("%lf\n",stack[top]);
    }

}

