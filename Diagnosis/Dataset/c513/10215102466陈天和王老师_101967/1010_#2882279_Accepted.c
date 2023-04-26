#include <stdio.h>
#include <string.h>
void i2(int n,int wei){
    int s[10]={0};
    for(int i=0;i<wei;i++){
        int a=1;
        s[i]=a&n;
        n>>=1;
    }
    for(int i=wei-1;i>=0;i--){
        printf("%d",s[i]);
    }
}
int main() {
    char s[1000000];
    scanf("%s",s);
    int cnt=0;
    printf("0001");//输出数字编码
    i2(strlen(s),10);//输出位数编码
    while(strlen(s)-cnt>=3){
        int num=(s[cnt]-'0')*100+(s[cnt+1]-'0')*10+s[cnt+2]-'0';
        i2(num,10);
        cnt+=3;
    }
    if(strlen(s)-cnt==2){
        int num=(s[cnt]-'0')*10+s[cnt+1]-'0';
        i2(num,7);
    }
    else if(strlen(s)-cnt==1){
        int num=s[cnt]-'0';
        i2(num,4);
    }//真正的编码


    return 0;
}
//debug:字符数组存数字，当数字用的时候忘记-'0'了。好菜哦