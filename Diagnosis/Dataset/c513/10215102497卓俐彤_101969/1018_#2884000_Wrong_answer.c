#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxstr 500

void Readnumber(char s[],int a[]){
    int j=0;
    for(int i=0;i<strlen(s);i++){
        int num=0;
        while(s[i]!=','&&i<strlen(s)){
            num*=10;
            num+=s[i++]-'0';
        }
        a[j++]=num;
    }
    a[j]=-1;
}

long long int prime[27]=
{1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};



int main(){
    char s[maxstr];
    long long int A=0;
    scanf("%s",s);
    int a[maxstr];
    Readnumber(s,a);
    int len=-1,i=0;
    while(a[++len]!=-1);
    for(int j=0;j<len;j++){
        A+=a[j];
        A*=prime[len-1-i];
        i++;
    }
    printf("%lld",A);
    return 0;
}
