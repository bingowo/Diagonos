#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int cnt;
    int val[100];
}BigInt;
void DIV(BigInt* bigint, int m);//m是除数
void ADD(BigInt* bigint, int n);//n是加数
int main(){
    char num[101];
    scanf("%s", num);
    int sign = 1;
    int cnt = 0; int len = strlen(num);
    BigInt n = {0, {0}};
    for(int i = len-1; i>=1; i--){
        n.val[n.cnt++] = num[i] - '0';
    }//输入1234.存放4321
    //处理符号位
    if(num[0] == '-'){ sign = -1;}
    else{ n.val[n.cnt++] = num[0] - '0';}

    int result[500] = {0};
    while(n.cnt>0){
        int temp = n.val[0] % 2;//左边存的低位
        result[cnt++] = temp;
        DIV(&n, 2);

        if(sign == -1 && temp){
            //只有被除数为负数且余数为负一时才需要处理
            if(n.cnt == 0){
                n.val[n.cnt++] = 1;
            }
            else{
                ADD(&n, 1);
            }
        }
        sign *= -1;
    }
    for(int i = cnt-1; i>=0; i--){
        printf("%d", result[i]);
    }
    return 0;
}
void DIV(BigInt* bigint, int m){
    int carry = 0;//进位
    if(bigint->val[bigint->cnt-1] < m){
        bigint->cnt--;
        carry = 1;
    }
    for(int i = bigint->cnt-1; i>=0; i--){
        int temp = 10*carry + bigint->val[i];
        bigint->val[i] = temp / m;
        carry = temp % m;
    }
}
void ADD(BigInt* bigint, int n){
    int start = 0;
    int carry = 0;
    do{
        carry = (bigint ->val[start] + n)/10;
        bigint ->val[start] = (bigint ->val[start]+n)%10;
        start ++;
    }while(carry != 0 && start < bigint->cnt);
    if(carry){
        bigint->val[bigint->cnt] = carry;
        bigint->cnt++;
    }
}
