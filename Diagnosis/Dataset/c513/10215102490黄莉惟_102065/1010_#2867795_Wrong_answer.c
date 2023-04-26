#include<stdio.h>
#include<string.h>
int main(){
    char s[500];
    int i,t,j,n;
    scanf("%s",s);
    printf("0001");
    int num=strlen(s);
    for(i=9;i>-1;i--) printf("%d",(unsigned)num<<(31-i)>>31);
    n=num/3;
    if(num==1){
        for(i=3;i>-1;i--) printf("%d",(unsigned)(s[0]-48)<<(31-i)>>31);
    }
    if(num==2){
        for(i=6;i>-1;i--) printf("%d",(unsigned)((s[0]-48)*10+s[1]-48)<<(31-i)>>31);
    }
    if(num%3==0){
    for(j=0;j<3*n;j+=3){
        t=(s[j]-48)*100+(s[j+1]-48)*10+s[j+2]-48;
        for(i=9;i>-1;i--){ printf("%d",(unsigned)t<<(31-i)>>31);}
        }
    }
    if((num%3==2)&&(num!=2)){
        for(j=0;j<=num-5;j+=3){
            t=(s[j]-48)*100+(s[j+1]-48)*10+s[j+2]-48;
            for(i=9;i>-1;i--){ printf("%d",(unsigned)t<<(31-i)>>31);}
        }
        for(i=6;i>-1;i--) printf("%d",(unsigned)((s[num-2]-48)*10+s[num-1]-48)<<(31-i)>>31);
    }
}
