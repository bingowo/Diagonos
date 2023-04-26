#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int len;//位数
    int v[1005];//数值，最多有 Len 位数字
}bign;

//内部创建字符数组的初始化
void init(bign* a){
    char s[1006];
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
//使用方法，创建一个bign ai={0,{0}}，和一个bign af={0, {0}}，分别对应这个数的整数部分和小数部分
//然后input(&ai, &bi);
void input(bign* i, bign* f){
    char s[1005]; scanf("%s", s);
    if(strchr(s, '.') == NULL){
        strcat(s, ".0");
    }//如果输入的是23这样的纯整数，则加上.0
    int len = strlen(s);//获得此时的长度
    if(s[len-1] == '.'){//如果输入的是123.这样的，补上后置零
    	strcat(s, "0");
	}
	len = strlen(s);
    int temp2 = strchr(s, '.') - s;//小数点距离整数在哪儿，这个的值也正好是整数部分的长度
    i->len = (temp2 == 0)? 1 : temp2;//如果输入是.123，需要补上前置的0，所以让len=1
    if(temp2){//如果整数部分是有的，那么就逐个录入
        for(int j = 0; j < i->len; j++){i->v[j] = s[i->len - 1 - j]-'0';}
        //此处可能涉及符号判断，但是没写
    }
    f->len = len - temp2 - 1;//小数部分长度
    for(int j =0; j<f->len; j++){
        f->v[j] = s[len - 1 - j] -'0';
    }
    return;
}
int main(){
	bign ai = {0, {0}};bign af = {0, {0}};input(&ai, &af);
	bign bi = {0, {0}};bign bf = {0, {0}};input(&bi, &bf);
	//这段代码用作浮点数的对齐
	//比如输入0.1，和0.123，小数部分被放进大整数，分别是1和123，要把1和123对齐，应该把1变做100
	int len = (af.len>bf.len)?af.len : bf.len;//len存储最长的小数长度
	int lensub;//存储长度之差
	if(af.len>bf.len){
	    lensub = af.len - bf.len;
	    for(int j = 0; j<lensub; j++){
	        bf = multi(bf, 10);
	    }
	}
	else{
	    lensub = bf.len - af.len;
	    for(int j = 0; j<lensub; j++){
	        af = multi(af, 10);
	    }
	}
	for(int i = 0; i<len; i++){
	    ai = multi(ai, 10);
	    bi = multi(bi, 10);
	}
	ai = add(ai, af);
	bi = add(bi, bf);
	int judge = compare(ai, bi);
	bign c = {0, {0}};
	int N; scanf("%d", &N);//保留N位小数
	if(judge>0){//a>b
	    c = sub(ai, bi);
	    if(N<len){
	        if(c.v[len - N - 1] > 4){
	            bign one = {1, {1}};
	            for(int j = 0; j < len-N; j++){one = multi(one, 10) ;}
	            c = add(c, one);
	        }
	    }
	    int ilen = 0;
	    for(ilen = 1005; ilen>len+1; ilen--){
	        if(c.v[ilen-1] == 0){
	            continue;
	        }
	        else{
	            break;
	        }
	    }
	    ilen -= len;
	    for(int j = 0; j<ilen; j++){
	        printf("%d", c.v[len+ilen-1-j]);
	    }//整数部分
	    printf(".");
	    if(N<len){
	    	for(int j = 0; j<N; j++){
	        	printf("%d", c.v[len-1-j]);
	    	}    
	    }
	    else{
	        for(int j = 0; j<len; j++){
	            printf("%d", c.v[len-1-j]);
	        }
	        for(int j = 0; j<N-len; j++){
	            printf("0");
	        }
	    }
	}
	else if(judge<0){
	    c = sub(bi, ai);
		if(N<len){
	        if(c.v[len - N - 1] > 4){
	            bign one = {1, {1}};
	            for(int j = 0; j < len-N; j++){one = multi(one, 10) ;}
	            c = add(c, one);
	        }
	    }
	    //小数部分就是从结果的v的len-1处(这里的len是外部的len)，往0的方向，打印
	    //如果N比小数长度小，就打印N个，否则，打印完，并且补上多的0
	    //整数部分长度，先从结构体的数组最长处开始遍历，一直到LEN-len的地方
	    int ilen = 0;
	    for(ilen = 1005; ilen>len+1; ilen--){
	        if(c.v[ilen-1] == 0){
	            continue;
	        }
	        else{
	            break;
	        }
	    }
	    ilen -= len;
	    printf("-");
	    for(int j = 0; j<ilen; j++){//整数部分
	        printf("%d", c.v[len+ilen-1-j]);
	    }
	    printf(".");
	    //小数部分
	    if(N<len){
	    	for(int j = 0; j<N; j++){
	        	printf("%d", c.v[len-1-j]);
	    	}    
	    }
	    else{
	        for(int j = 0; j<len; j++){
	            printf("%d", c.v[len-1-j]);
	        }
	        for(int j = 0; j<N-len; j++){
	            printf("0");
	        }
	    }
	}
	else{
	    printf("0.");
	    for(int i = 0; i<N; i++){
	        printf("0");
	    }
	}
}