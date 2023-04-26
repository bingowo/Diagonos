//先变成十进制再变成B进制。pow返回类型是浮点数类型。2**3就是浮点数类型。所以不能用pow
#include<stdio.h>
#include<string.h>
void Reserve(int before,char * num,int after){
    int i,j,yu;//yu:余数
    long sum = 0;
    char tmp[32] = {0};
    if(num=0)
    for(i=0;i<strlen(num);i++){//before进制->10进制
        if(num[i]>='0' && num[i]<='9')sum = sum * before + (num[i] - '0');
        else if(num[i]>='A'&&num[i]<='F') sum = sum * before + (num[i] - 'A' + 10);
        else if(num[i]>='a'&&num[i]<='f') sum = sum * before + (num[i] - 'a' + 10);
    }
    if(sum==0)printf("0");
    for(i=0;sum!=0;i++){//10进制->after进制
        yu = sum % after;
        sum /= after;
        if (yu >= 10)tmp[i] = yu - 10 + 'A';
        else tmp[i] = yu + '0';
    }
    i = i-1;
    j = 0;
    while(i >= 0)num[j++] = tmp[i--];
    num[j] = 0;
    printf("%s\n",num);
}
int main(){
    int a,b;
    char n[32];
    scanf("%d%s%d",&a,n,&b);
    Reserve(a,n,b);
    return 0;
}
