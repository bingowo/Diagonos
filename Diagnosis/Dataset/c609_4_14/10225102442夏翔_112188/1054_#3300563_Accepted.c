//1054  高精度除法（版子） 高精度乘法  高精度加法
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int num[110], pos, len1, ans[110], len2;
void divide2(){ //  num/2 其他高精度除以低精度的除数的模板就是把2换成那个数
    int ret, temp=num[pos];
    while(temp<2){
        pos++;
        if(pos==len1) return; //已经除完了
        temp = temp*10+num[pos];
    }
    ret = pos;
    while(ret<len1){
        num[ret++] = temp/2;
        temp %= 2;
        while(temp<2 && ret<len1){
            temp = temp*10+num[ret];
            num[ret++] = 0;
        }
        if(temp>=2) ret--;
    }
}

void add1(){  //ans+1
    int temp=1, ret=0;
    while(temp!=0){
        ans[ret] += temp;
        temp = ans[ret]/10;
        ans[ret++] %= 10;
    }
    if(ret>len2) len2 = ret;
}

void multiply(){ //ans*2
    int ret=0, temp=0;
    while(ret<len2){
        ans[ret] = ans[ret]*2+temp;
        temp = ans[ret]/10;
        ans[ret++] %= 10;
    }
    while(temp!=0){
        ans[len2++] = temp%10;
        temp /= 10;
    }
}

int main(){
    int n;
    char s[110];
    scanf("%d", &n);
    for(int t=0; t<n; t++){
        printf("case #%d:\n", t);
        memset(num, 0, sizeof(num));
        memset(ans, 0, sizeof(ans));
        scanf("%s", s);
        pos = 0; len1 = strlen(s); len2 = 1;//pos记录除法最开头的位置
        for(int i=0; i<len1; i++) num[i] = (int)s[i]-48;
        while(pos<len1){
            multiply();
            if(num[len1-1]%2==1) add1();
            divide2();
        }
        for(int i=0; i<len2; i++) printf("%d", ans[len2-1-i]);
        printf("\n");
        
    }
    return 0;
}