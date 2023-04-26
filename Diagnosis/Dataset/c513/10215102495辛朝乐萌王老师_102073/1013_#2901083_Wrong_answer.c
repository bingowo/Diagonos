#include <stdio.h>
#include<stdlib.h>
#include <string.h>


int main(void)
{
    char s[40];
    scanf("%s",s);
    long long int integar=0,numerator=0,den=1;
    char *p=s;
    while (*p!='.'&&*p) {
        integar=integar*3;
        if(*p=='1'){
            integar+=1;
        }
        else if(*p=='2'){
            integar-=1;
        }
        p++;
    }
    if(*p){
        p++;
    }
    while (*p) {
        den*=3;
        numerator*=3;
        if(*p=='1'){
            numerator+=1;
        }
        else if(*p=='2'){
            numerator-=1;
        }
        p++;
    }
    if(numerator==0){
        printf("%lld",integar);
    }
    else if(numerator>0){
        if(integar<0){
            integar++;
            numerator = den-numerator;
        }
        else if(integar==0){
            printf("%lld %lld",numerator,den);
        }
        else{
            printf("%lld %lld %lld",integar,numerator,den);
        }
    }
    else if(numerator<0){
        if(integar>0){
            integar--;
            numerator=den+numerator;
        }
        if(integar==0){
            printf("%lld %lld",numerator,den);
        }
        else{
            printf("%lld %lld %lld",integar,numerator,den);
        }
    }
    return 0;
}