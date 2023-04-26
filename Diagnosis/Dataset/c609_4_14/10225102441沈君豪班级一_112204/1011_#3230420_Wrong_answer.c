#include <stdio.h>
#include <ctype.h>
#include <string.h>

int measure(int m,int n){
    int z=n;
    while(m%n!=0){
        z=m%n;
        m=n;
        n=z;
    }
    return z;
}

int main()
{
    char s[30];
    int a;
    scanf("%s",s);
    a = strlen(s);
    int b=0;                   /*用于判断是否到小数点*/
    int x=0,y=0,z=1;                 /*最后输出的结果*/
    for(int i=0;i<a;i++){
        if(!isdigit(s[i])){
            b=1;
            continue;
        }
        if(b==0){
            if(s[i]=='2')
                x=x*3-1;
            else
                x=x*3+s[i]-'0';
        }else{
            z=z*3;
            if(s[i]=='2')
                y=y*3-1;
            else
                y=y*3+s[i]-'0';
        }
    }
    int c;
    if(b==0)
        printf("%d",x);
    else{
        if(x==0&&y<0){
            y =-y;
            c=measure(y,z);
            printf("-%d %d",y/c,z/c);
           }
        else{
            if(y<0){
                x--;
                y=y+z;
            }
            if(x<0&&y>0){
                x++;
                y=z-y;
            }
            c=measure(y,z);
            printf("%d %d %d",x,y/c,z/c);
        }}

    return 0;
}
