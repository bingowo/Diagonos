#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int len;//位数
    int v[505];//数值，最多有 Len 位数字
}bign;

//内部创建字符数组的初始化
void init(bign* a){
    char s[500 + 1];
    scanf("%s", s);
    int slen = strlen(s);
    for(int i = slen - 1; i >= 1; i--){
    	a->v[a->len++] = s[i] - '0';//如果输入1234，目前数组里就是432
    	//顺带着len就把一共多少个数给数了
	}
	if(s[0] != '-'){
    	a->v[a->len++] = s[0] - '0';//特判符号位是否是-
	}
}
//外部创建数组的初始化
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
void print(bign* a){
    for(int i = a->len-1; i >= 0; i--){
	    printf("%d", a->v[i]);
	}
}
//比较大整数（绝对值）大小
int compare(bign a, bign b){
    if(a.len > b.len){//a大
        return 1;
    }else if(a.len < b.len){//a小
        return -1;
    }else{//此分支说明长度相等,从高位往地位比较
        for (int i = a.len - 1; i >= 0; --i){
            if(a.v[i] > b.v[i]){//只要有一位a大，则a大
                return 1;
            }
            else if(a.v[i] < b.v[i]){//只要有一位a小，则a小
                return -1;
            }
        }
        return 0;
    }
}
bign add(bign a, bign b){//c为加后的结果
	bign c = {0, {0}};
    int carry = 0;//进位
    for (int i = 0; i < a.len || i < b.len; ++i)
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
bign sub(bign a, bign b){
	bign c = {0, {0}};
    for(int i = 0; i<a.len || i<b.len; i++)//以较长为界
    {
        if(a.v[i] < b.v[i])//被减数小于减数
        {
            a.v[i+1] -- ;//高位被借一位。
            a.v[i] += 10;//借位后当前位加10
        }
        c.v[c.len++] = a.v[i] - b.v[i];
    }
    while(c.len > 1  && c.v[c.len-1] == 0){
        c.len--;
    }
    return c;
}
//和低精度数的乘法
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
        c.v[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}//不用指针
//和低精度数的除法
bign divv(bign a, int b, int* r)//被除数，除数，余数，结果
{
    bign c = {0, {0}};
    c.len = a.len;
    for(int i = a.len - 1; i >= 0; i--){
        *r = *(r)*10 + a.v[i];
        if(*r < b){
        //不够除
			c.v[i] = 0;
        }
        else{
            c.v[i] = *(r) / b;//此位的商
            *r = *(r) % b;//新的余数 
        }
    }
    while(c.len > 1 && c.v[c.len - 1] == 0){
		c.len -- ;//去除高位0，让len记录到正确的数字。
    }
    return c;
}
//高精度和高精度的数的乘法
bign Multi(bign a, bign b){
	bign c = {0, {0}};
    int carry = 0;
    for(int i = 0; i<a.len; i++){
        for(int j = 0; j<b.len; j++){
            int temp = c.v[i+j] + a.v[i] * b.v[j] + carry;
            c.v[i+j] = temp % 10;
            carry = temp / 10;
        }
        int m = 0;
        while(carry){//处理多出去的进位
        	int temp = c.v[i + b.len + m] + carry;
            c.v[i + b.len + m] = temp % 10;
            carry = temp / 10;
            m++;
        }
    }
    c.len = a.len + b.len;
    while(c.len > 1 && c.v[c.len - 1] == 0){
		c.len -- ;//去除高位0，让len记录到正确的数字。
    }
    return c;
}
int main(){
	bign ai = {0, {0}}; bign af = {0, {0}};
	bign bi = {0, {0}}; bign bf = {0, {0}};
	bign one = {1, {1}};
	
	char s1[505]; scanf("%s", s1);
	char a[505] = {'0'};
	strcat(a, s1); if(strchr(a, '.') != NULL){strcat(a, "0");}
	int len1 = strlen(a); while(*(a+ai.len) != '.' && ai.len<len1){ai.len++;}
	for(int i = 0; i < ai.len-1; i++){ai.v[i] = a[ai.len - 1 -i] - '0';}
	for(int i = 0; i< len1 - ai.len - 1; i++){
		af.v[af.len++] = a[len1 - 1 -i] - '0';
	}
	while(ai.len > 1 && ai.v[ai.len - 1] == 0){
		ai.len -- ;//去除高位0，让len记录到正确的数字。
    }
	
	char s2[505]; scanf("%s", s2);
	char b[505] = {'0'};
	strcat(b, s2); if(strchr(b, '.') != NULL){strcat(b, "0");}
	
	int len2 = strlen(b); while(*(b+bi.len) != '.' && bi.len<len2){bi.len++;}
	for(int i = 0; i<bi.len-1; i++){bi.v[i] = b[bi.len - 1 -i] - '0';}
	for(int i = 0; i< len2 - bi.len - 1; i++){
		bf.v[bf.len++] = b[len2 - 1 -i] - '0';
	}
	while(bi.len > 1 && bi.v[bi.len - 1] == 0){
		bi.len -- ;//去除整数高位0，让len记录到正确的数字。
    }
	int N; scanf("%d", &N);
	//小数部分相加可能向整数进位，因此先记录长的小数长度。
	int flen = (af.len > bf.len)?af.len : bf.len;
	if(bf.len < flen){
		int temp = flen - bf.len;
		int t = 1;
		for(int i = 0; i<temp; i++){
			t *= 10;
		}
		bf = multi(bf, t);
	}
	if(af.len < flen){
		int temp = flen - af.len;
		int t = 1;
		for(int i = 0; i<temp; i++){
			t *= 10;
		}
		af = multi(af, t);
	}
    bign ci = {0, {0}}; bign cf = {0, {0}};
	ci = add(ai, bi);
	cf = add(af, bf);
	if(cf.len > flen){//新小数更长则说明发生进位，整数加一。
		ci = add(ci, one);
		cf.v[cf.len-1] = 0;
		cf.len--;
	}
	//小数部分四舍五入
	if(cf.v[flen - N - 1] >= 5){
		bign carry = {0, {0}};
		for(int i = 0; i<flen - N; i++){
			carry.v[carry.len++] = 0;
		}
		carry.v[carry.len++] = 1;
		cf = add(cf, carry);
		if(cf.len > flen){
			ci = add(ci, one);
		}
	}
	print(&ci);
	printf(".");
	for(int i = 0; i < N; i++){
		if(i<flen){
			printf("%d", cf.v[flen-1-i]);
		}
		else{
			printf("0");
		}
	}
	return 0;
}