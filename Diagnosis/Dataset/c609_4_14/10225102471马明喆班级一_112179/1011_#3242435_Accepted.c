#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int mypow(long long int a){
    long long int i=1;
    for(;a>0;a--)
        i*=3;
    return i;
}

int main(){
    char s[100];
    scanf("%s",&s);
    int i=0;
    long long int res=0;
    long long Inte=0,Frac=0;
    for(;s[i]!='\0'&&s[i]!='.';i++){
        Inte *=3;
        if(s[i]=='2') Inte -=1;
        else
            Inte +=(s[i]-'0');
    }
    if(s[i]=='.'){
        i++;
        for(;s[i]!='\0';i++){
            res++;
            Frac *=3;
            if(s[i]=='2') Frac -=1;
            else
                Frac +=(s[i]-'0');
        }
    }
    res=mypow(res);
    if(Inte!=0){
        if(Inte>0&&Frac<0){
            Inte--;
            Frac=res+Frac;
            printf("%lld %lld %lld",Inte,Frac,res);
        }
        else if(Inte<0&&Frac>0){
            Inte++;
            Frac=res-Frac;
            printf("%lld %lld %lld",Inte,Frac,res);
        }
        else if(Inte>0&&Frac>0){
            printf("%lld %lld %lld",Inte,Frac,res);

        }
        else if(Inte<0&&Frac<0){
            printf("%lld %lld %lld",Inte,-Frac,res);

        }
        else
            printf("%lld",Inte);
    }
    else if(Frac!=0)
        printf("%lld %lld",Frac,res);
    else
        printf("0");
    return 0;
}