#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void binary(char *c,char *s){
    char tab[16][5]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"},*s1,*s2,*s3,m;
    s1=s;
    if(*c=='0'){*s1='0';s1++};
    else{ 
        if(isdigit(*c)&&*c-'0'<2){*s1=tab[*c-'0'][3];}
        else if(isdigit(*c)&&*c-'0'<4){*s1=tab[*c-'0'][2];*(s1+1)=tab[*c-'0'][3];}
        else if(isdigit(*c)&&c-'0'<8){*s1=tab[*c-'0'][1];*(s1+2)=tab[*c-'0'][2];*(s1+3)=tab[*c-'0'][3];}
        else {*s1=tab[*c-'0'][0];*(s1+1)=tab[*c-'0'][1];*(s1+2)=tab[*c-'0'][2];*(s1+3)=tab[*c-'0'][3];}
        c++;
        if(*c){
        do{
            if(isdigit(*c)){*s1=tab[*c-'0'][0];*(s1+1)=tab[*c-'0'][1];*(s1+2)=tab[*c-'0'][2];*(s1+3)=tab[*c-'0'][3];}
            else {*s1=tab[*c-'A'+10][0],*(s1+1)=tab[*c-'A'+10][1],*(s1+2)=tab[*c-'A'+10][2],*(s1+3)=tab[*c-'A'+10][3];}
            s1=s1+4;
            c++;
            }
        while(*c);
        }
    }
    *s1=0;
}
int main(){
    long long int i,a,b,a1=0,b1=0;
    int m;
    char s[1000],c[100],*s1,sign;
    scanf("%s",c);
    binary(c+2,s);
    s1=s;
    for(;*s1;s1++){
        a=-a1-b1+*s1-'0';
        b=a1-b1;
        a1=a;
        b1=b;
    }
    if(b<0){
        b=-b;
        sign='-';

    }
    else if(b>0)sign='+';
    else sign=0;
    if(a!=0){
    if(b!=1&&b!=-1){printf("%lld",a);printf("%c",sign);if(sign)printf("%lldi",b);}
    else if(b!=0){printf("%lld",a);printf("%c",sign);if(sign)printf("i");}
    else printf("%lld",a);}
    else{
        if(b==0)printf("%lld",a);
        else if(b!=1&&b!=-1){printf("%c",sign);if(sign)printf("%lldi",b);}
        else {if(sign!='+'&&sign!=0)printf("%c",sign);printf("i");}
    }
    return 0;
}




