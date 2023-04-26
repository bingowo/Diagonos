#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(){
    char base64[64];
    for(int b=0;b<62;b++){
        if(b<26)base64[b]='A'+b;
        else if(b<52)base64[b]='a'-26+b;
        else base64[b]='0'+b-52;
    }
    base64[62]='+';
    base64[63]='/';
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char str[101];
        scanf("%s",str);
        printf("case #%d:\n",t);
        char res[500];
        unsigned long int len=strlen(str);
        int p=0,i=0,bits=0;
        int ret=0;
        while(i<len){
            char ch=str[i++];
            int c=(ret<<(6-bits))+(ch>>(2+bits));
            res[p++]=base64[c];
            bits+=2;
            ret=ch%(1<<bits);
            if(bits==6){
                res[p++]=base64[ret];
                bits=0;
                ret=0;

            }
        }
        if(bits==4){
            res[p++]=base64[ret<<2];
            res[p++]='=';
        }
        else if(bits==2){
            res[p++]=base64[ret<<4];
            res[p++]='=';
            res[p++]='=';
        }
        res[p]='\0';
        for(int j=0;j<p;j++)printf("%c",res[j]);
        printf("\n");

    }
    return 0;
}
