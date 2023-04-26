#include<stdio.h>
#include <stdlib.h>
#include <string.h>
//思路
//1。获得字符串们
//2。从字符串中得到数字
//3。分两种比较方式：先比较数字后面通过strcmp
//4。调用qsort
//5。完成比较输出

int int_sert(char *s){
    int sum = 0;
    int flag = 0;
    int len = strlen(s);
    for(int i = 0 ;i < len;i++ ){
        if(s[i]>='0' && s[i]<= '9'){
            flag = 1;
            sum = sum*10;
            sum+=s[i]-48;
        }
    }
    if (flag == 0)
        sum = -1;

    return  sum;

}
int cmp(const void* a,const void *b){
    char*s1;
    char*s2;
    int number1;
    int number2;
    s1 = *(char (*) [31])a;
    s2 = *(char (*) [31])b;
    number1 = int_sert(s1);
    number2 = int_sert(s2);
     if(number1==number2){
         return strcmp(s1,s2);
     }else{
         return number1-number2;
     }




}
char str [110][31];

int main(){
    int count = 0;
    while(scanf("%s",str[count])!= EOF){
        count++;
    }
    qsort(str,count,sizeof(str[0]),cmp);
    for (int i = 0;i < count;i++){
        printf("%s ",str[i]);
    }

}