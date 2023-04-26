#include<stdio.h>
#include<string.h>
int main(){
    char s[500];
    int i,t,j,n;
    scanf("%s",s);
    int num=strlen(s);
    if((num%3==2)&&(num!=2)){
        for(j=0;j<=num-5;j+=3){
            t=(s[j]-48)*100+(s[j+1]-48)*10+s[j+2]-48;
            for(i=9;i>-1;i--){ printf("%d",(unsigned)t<<(31-i)>>31);}
        }
         for(i=6;i>-1;i--) printf("%d",(unsigned)((s[num-2]-48)*10+s[num-1]-48)<<(31-i)>>31);
    }
}
}
