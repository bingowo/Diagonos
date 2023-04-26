#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void trans(int a,int l){//将a转换为l位二进制数,并输出
    
//}
int main(){
    char que[500],ans[5600];
    scanf("%s",que);
    printf("0001");
    int l=strlen(que);
    //trans(l,10);
    for(int i=0;i<l-2;i+=3){
        char s[4];
        strncpy(s,que+i,3);
        printf("%s",s);
        int a=atoi(s);
        //trans(a,10);
    }
}