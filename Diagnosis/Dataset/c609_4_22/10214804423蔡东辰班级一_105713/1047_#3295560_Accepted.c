#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int len;//位数
    int v[101];//数值，最多有 Len 位数字
    /*
    char vs[Len+1];//字符串
    int sign;//符号
    */
}bign;
void init_Bign(char* s, bign* a);//初始化
bign multi(bign a, int b);//大整数与低精度整数乘

int main(){
    int T;
    scanf("%d", &T);
    for(int j = 0; j<T; j++){
        char s[3];
        scanf("%s", s);//输入a
        int a0 = atoi(s);//对应a的低精度
        int n;
        scanf("%d", &n);
        bign a = {0, {0}};
        init_Bign(s, &a);
        if(n == 0){
        	printf("case #%d:\n1\n", j);
        	continue;
		}
        for(int i = 0; i < n-1; i++){
            a = multi(a, a0);
        }
        printf("case #%d:\n", j);
        for(int i = a.len-1; i >= 0; i--){
		    printf("%d", a.v[i]);
	    }
	    printf("\n");
    }
    return 0;
}
void init_Bign(char* s, bign* a){
    int slen = strlen(s);
    for(int i = slen - 1; i >= 1; i--){
    	a->v[a->len++] = s[i] - '0';//如果输入1234，目前数组里就是432
    	//顺带着len就把一共多少个数给数了
	}
	if(s[0] != '-'){
    	a->v[a->len++] = s[0] - '0';//特判符号位是否是-
	}
}
bign multi(bign a, int b){//c存放结果
    bign c = {0, {0}};
    int carry = 0;//进位
    for (int i = 0; i < a.len; ++i)
    {
        int temp = a.v[i]* b + carry;
        c.v[c.len++] = temp % 10;//个位作为该位结果
        carry = temp /10;//高位部分作为新的进位
    }
    while(carry != 0){
        //和加法不一样，进位可能不止一位
        //这个过程相当于不断地把最后的进位给均摊下去
        c.v[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}