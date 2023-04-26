#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number(char*str){
    int len,sum=0,flag=0;
    len = strlen(str);
    for(int i=0;i<len;i++){
        if(str[i] >= '0' && str[i] <= '9'){
            sum=10*sum+str[i]-48;
            flag=1;//标志变量
        }
    }
    if (flag==0) sum=-1;
    return sum;
}
int strnumcmp(const void*a,const void*b){
    char *str1,*str2;
    str1=(char*)a;
    str2=(char*)b;
    if(number(str1)>number(str2)) return 1;
    else if(number(str1)<number(str2)) return -1;
    else return strcmp(str1,str2);
}

int main(){
    char str[101][31];
    int i=0,j;
    while(scanf("%s",str[i])!=EOF) i++;
    qsort(str,i+1,sizeof(str[0]),strnumcmp);
    printf("1");
    for(j=0;j<i+1;j++){
        printf("%s ",str[j]);
    }
    printf("%s\n",str[j]);
    return 0;
}

//一段字符串转数字的方法：先乘十，再加这一位，sum=10*sum+str[i]-48;
//无限输入操作
// int i=0;
// while(scanf("%s ",str[i])!=EOF) i++;
//qsort：qsort(str,i+1,sizeof(str[0]),strnumcmp);数组名字、元素数量、元素大小，比较函数
//这个题如果不提取数字就贼麻烦贼麻烦