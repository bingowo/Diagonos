//longlong类型 转化后数字太长。整数形式用那个空格分隔
#include<stdio.h>
int main(){
    int t,i;
    long long int a;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&a);
        int s[100000000]={0};
        f(a,s);
        printf("%s\n",s);
    }
    return 0;
}
void f(long long int a,char s[100000000])
{
    int j=0;
    char b;
    while(a){
        s[j++]=a%2333;
        s[j++]=' ';
        a=a/2333;
    }
    s[j+1]='\0';
}
