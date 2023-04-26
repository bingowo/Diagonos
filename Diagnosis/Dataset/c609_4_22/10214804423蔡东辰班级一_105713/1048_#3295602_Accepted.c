#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int len;//位数
    int v[200];//数值，最多有 Len 位数字
}bign;
void print(bign* a){//打印高精度
    for(int i = a->len-1; i >= 0; i--){printf("%d", a->v[i]);}
}
void init_Bign(char* s, bign* a);//初始化
bign add(bign a, bign b);//高精度加法
int main(){
    int T; scanf("%d", &T);
    for(int j = 0; j<T; j++){
        int n; scanf("%d", &n);
        if(n==0){printf("case #%d:\n0\n", j); continue;}
        if(n<=2){printf("case #%d:\n1\n", j); continue;}
        bign L[120];
        bign a = {1, {1}};
        L[0] = a;
        L[1] = a;
        for(int i = 2; i < 120; i++){
        	L[i] = add(L[i-1], L[i-2]);
		}
        printf("case #%d:\n", j);
        print(&L[n-1]);printf("\n");
    }
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
bign add(bign a, bign b){//c为加后的结果
    //需要注意数字在bign里是倒序存的，如果值是1234，存的就是4321
    //那么我们就是从结构体的最左边开始。
    bign c = {0, {0}};
    int carry = 0;//进位
    for (int i = 0; i < a.len || i < b.len; ++i)
        //以较长的为界，因为大家最长都有length位数字
        //且不够的地方一定都是零，可以放心加
        //从左开始等效于从各位开始，所以最开始的carry一定是0
    {
        int temp = a.v[i] + b.v[i] + carry;//两个对应位与进位相加
        carry = temp / 10;//十位为新的进位，如果不是十进制就看。
        c.v[c.len++] = temp % 10;//各位为该位结果
    }
    if(carry != 0){//如果最后进位不为0，则直接赋值给结果的最高位
        c.v[c.len++] = carry;
    }
    return c;
}