#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int a[110];
    int x;                 //位数

}bigint;

bigint   f(char* t)
{
    bigint k;
    int m=0;          //用于存储几位数
    for(int i=0;i<strlen(t);i++){
        if(isdigit(t[i])){
            k.a[m]=t[i]-'0';
            m++;
        }
    }
    k.x=m;
    return k;
}

int main()
{
    char s[110];
    scanf("%s",s);
    int fh=1;
    if(s[0]=='-'){
        fh=-1;
    }
    bigint n=f(s);
    int t[110];
    int tj=0;                  //输出数组的下标
    int y=n.x;                //数组长度
    while(y>0){
        int ys=0;              //上一位的余数
        for(int i=0;i<y;i++){
            int gg=n.a[i]+ys*10;
            if(gg%2==1&&fh==-1){
               n.a[i]=gg/2+1;
               ys=1;       //余数为1
               fh=-fh;
            }else{
                n.a[i]=gg/2;
                ys=gg%2;
                fh=-fh;
            }
            if(i==y-1){
                t[tj]=ys;
                tj++;
            }
        }
        int j=y;
        for(int i=0;i<j;i++){         //对数组长度更新 并去除前置零
            if(n.a[i]==0){
                y--;
            }else{
                break;
            }
        }
        for(int i=0;i<y;i++){
            n.a[i]=n.a[i+j-y];
        }
    }
    for(int i=tj-1;i>=0;i--){
        printf("%d",t[i]);
    }
    return 0;
}
