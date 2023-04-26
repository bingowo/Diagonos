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
    t[100];
    int tj=0;                  //输出数组的下标
    int y=n.x;
    int ys=0;              //上一位的余数
    for(int i=0;i<y;i++){
        int gg=n.a[i]+ys*10;
        if(gg<2){
            gg=gg*10+n.a[i+1];
            i++;
        }
        if(gg%2==1&&fh==-1){
            t[tj]=gg/2;
            tj++;
            ys=1;
            fh=1;
        }else{
           t[tj]=gg/2;
           tj++;
           ys=gg%2;
        }
    }
    return 0;
}
