#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int len;//位数
    int v[500];//数值，最多有 Len 位数字
}bign;
void print(bign* a){
    for(int i = a->len-1; i >= 0; i--){
	    printf("%d", a->v[i]);
	}
}
int compare(bign a, bign b);
void init_Bign(char* s, bign* a);
void sub(bign a, bign b, bign* c);
int main(){
    char s1[501];
    char s2[501];
    while(scanf("%s %s", s1, s2) != EOF){
        bign c = {0, {0}};
        bign a = {0, {0}}; init_Bign(s1, &a);
        bign b = {0, {0}}; init_Bign(s2, &b);
        
        if(compare(a, b) > 0){
        	printf("a>b\n");
            sub(a, b, &c);
        }
        else if(compare(a, b) < 0){
            sub(b, a, &c);
            printf("-");print(&c);printf("\n");
        }
        else{
            printf("0\n");
        }
    }
}
void sub(bign a, bign b, bign* c){//c为减出来的差
	//同样从bign.v的最左边（实际数字的各位开始）
    for(int i = 0; i<a.len || i<b.len; i++)//以较长为界
    {
        if(a.v[i] < b.v[i])//被减数小于减数
        {
            a.v[i+1] -- ;//高位被借一位。
            a.v[i] += 10;//借位后当前位加10
        }
        c->v[c->len++] = a.v[i] - b.v[i];
    }
    //因为默认的长度是一个偏长的，减法一定会让len里包含多余的0
    //所以用一个while循环来把len的值控制在准确的数字
    //但是要注意，至少要保留一位数字，因为如果相减得到0，len应当为1
    //从len开始遍历说明是从高位开始，其实就是除去高位可能有的多余的0
    while(c->len > 1  && c->v[c->len-1] == 0){
        c->len--;
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
int compare(bign a, bign b){
    if(a.len > b.len){//a大
        return 1;
    }else if(a.len < b.len){//a小
        return -1;
    }else{//此分支说明长度相等,从高位往地位比较
        for (int i = a.len - 1; i >= 0; --i)
        {
            if(a.v[i] > b.v[i]){//只要有一位a大，则a大
                return 1;
            }else if(a.v[i] < b.v[i]){//只要有一位a小，则a小
                return -1;
            }
        }
        return 0;
    }
}