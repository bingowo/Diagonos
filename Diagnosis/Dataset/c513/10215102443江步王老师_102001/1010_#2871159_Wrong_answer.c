#include<stdio.h>

void trans(int value, int num);
void ntrans(int len);
int main()
{
    char s[501];
    int i=0,n=0,len;//n用于记录小组下标
    int num[167];
    int value[167];//存储每一组数字对应的十进制值
    for (i=0;i<167;i++){
        num[i]=0;
    }
    for (i=0;i<167;i++){
        value[i]=0;
    }
    i=0;
    //记录每组的数字个数
    scanf("%s",s);
    char *p=s;
    len=strlen(s);
    while(*p!='\0'){
        if (i%3==0){//3个一组
            num[n]=i;
            i=0;
            n++;
        }
        value[n]=value[n]*10+(*p-'0');
        p++;
    }
    if (i%3!=0){
        num[n]=i;
    }
    printf("0001");
    ntrans(len);
    for(i=0;i<=n;i++){
        trans(value[i],num[i]);
    }
    return 0;
}

void trans(int value, int num)//每三个数字转换成10位二进制,末尾如果是一位或两位数字，则分别转换成4位或7位二进制
{
    if (num==3){
        int res[10];
        int i;
        for (i=0;i<10;i++){
            res[i]=0;
        }
        i=0;
        while(value>0){
            res[i]=value%2;
            value=value/2;
            i++;
        }
        for (i=9;i>=0;i--){
            printf("%d",res[i]);//倒序输出res中的数字,输出二进制数
        }
    }
    else if (num==2){
        int res[7];
        int i;
        for (i=0;i<7;i++){
            res[i]=0;
        }
        i=0;
        while(value>0){
            res[i]=value%2;
            value=value/2;
            i++;
        }
        for (i=6;i>=0;i--){
            printf("%d",res[i]);//倒序输出res中的数字,输出二进制数
        }
    }
    else if (num==1){
        int res[4];
        int i;
        for (i=0;i<4;i++){
            res[i]=0;
        }
        i=0;
        while(value>0){
            res[i]=value%2;
            value=value/2;
            i++;
        }
        for (i=3;i>=0;i--){
            printf("%d",res[i]);//倒序输出res中的数字,输出二进制数
        }
    }
    return;
}

void ntrans(int len)//将数字长度转化为10位二进制数
{
        int res[10];
        int i;
        for (i=0;i<10;i++){
            res[i]=0;
        }
        i=0;
        while(len>0){
            res[i]=len%2;
            len=len/2;
            i++;
        }
        for (i=9;i>=0;i--){
            printf("%d",res[i]);//倒序输出res中的数字,输出二进制数
        }
        return;
}

