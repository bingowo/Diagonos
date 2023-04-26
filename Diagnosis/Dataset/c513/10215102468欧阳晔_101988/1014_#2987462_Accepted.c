#include <stdio.h>
#include <string.h>
#include <math.h>

int gcd(int a, int b)
{
    int ret, rest = a % b;
    while(rest){
        a = b;
        b = rest;
        rest = a % b;
    }
    ret= b;
    return ret;
}

//分别把整数部分和小数部分转化，然后放在一起，便于之后做运算 
void DecToTri(int integer, int numerator, char tri[], int length)	 
{
    int index = 98, len;
    if(integer == 0){
        tri[index--] = '0';
    }else{
        while(integer > 0){
            tri[index--] = integer % 3 + '0';
            integer /= 3;
        }		
    }
    memmove(tri, tri + index + 1, 99 - index);
    len = strlen(tri);
    tri[99] = '\0', index = 98;
    while(numerator > 0 || 98 - index < length){
        tri[index--] = numerator % 3 + '0';
        numerator /= 3;
    }
    memmove(tri + len, tri + index + 1, 99 - index);
	
}

void TriToBalance(char *tri, char * balance, int length)
{
    int index = 98;
    int len = strlen(tri);
    for(int i = len - 1; i >= 0 || balance[index]; i --){
        int j = index;
        if(i >= 0){
            balance[index] = tri[i] + 1 + balance[index];
        }else{
            balance[index] += (1 + '0');
        }
        while(balance[j] >= '3'){
            balance[j] -= 3;
            balance[--j] += 1;
        }
        index --;
    }
    for(int i = 98; balance[i]; i--){
        if(balance[i] == '1'){
            balance[i] = '0';
        }else if(balance[i] == '0'){
            balance[i] = '2';
        }else if(balance[i] == '2'){
            balance[i] = '1';
        }
    }
    memmove(balance, balance + index + 1, 99 - index);
    len = strlen(balance);
    if(length != 0){
        memmove(balance + (len - length) + 1, balance + (len - length), length + 1);
        balance[len - length] = '.';
    }
}

int main(void)
{
    int integer = 0, numerator = 0, denominator = 0, multi;
    scanf("%d %d", &numerator, &denominator);
    integer = numerator / denominator;
    numerator %= denominator;
    multi = gcd(numerator, denominator);
	//为了不让最后小数后面多出0，要先转化为最简分数 
    numerator /= multi, denominator /= multi;
    
    char tri[100] = {0}, balance[100] = {0};
    //计算出小数位数的长度 
    int length = (int)(log10((double)denominator) / log10(3));
    if(integer != 0 && numerator == 0){
        length = 0;
    }
    if(integer == 0 && numerator == 0){
        printf("0");
    }else{
        DecToTri(integer, numerator, tri, length);
        TriToBalance(tri, balance, length);
        printf("%s", balance);
    }
	
	
    return 0;
}