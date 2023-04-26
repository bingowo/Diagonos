#include <stdio.h>
#include <string.h>
int main(){
    char str[50];
    scanf("%s",str);
    int lenth=strlen(str);
    int max=1;//围栏最大程度长度初始化为1
    for(int i=0;i<lenth;i++){
        int a=1;
        int j=i+1; //搜索下一个字符
        while(j<lenth && str[j]==str[i]) j++;
        if(j==lenth) break;
        if (str[j]=='-' || str[j]=='|' && j < lenth){
            while(str[i] != str[j]){
                a++;i=j;j++;
            }
            if(a>max) max=a;
        }
    }
    printf("%d",max);
}