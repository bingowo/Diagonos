#include<stdio.h>
#include<string.h>
int main()
{
    char a[501];
    scanf("%s",a);
    printf("0001");//第一段0001；
    //第二段数字长度：
    int length=strlen(a);
    char l2[10];
    for(int i=0;i<10;i++){
        l2[i]=0;
    }
    int m=0;
    while(length>0){
        l2[m++]=length%2;
        length=length/2;
    }
    for(m=9;m>=0;m--){
        printf("%d",l2[m]);
    }
    //具体数字段。
    int len=strlen(a);
    int res=len%3,time=len/3;
    for(int step=0;step<time;step++){
        
    }
    
    
    return 0;
}