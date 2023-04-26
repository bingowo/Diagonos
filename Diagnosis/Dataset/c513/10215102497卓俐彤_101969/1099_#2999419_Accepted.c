#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
    int T;
    scanf("%d",&T);
    char c=getchar();
    char *moose[36]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        char str[1001];
        gets(str);
        char code[6],text[1001];
        char *p=str;
        int flag=0,i=0,n=0;
        while(*p){
            i=0;
            while(*p=='.'||*p=='-')code[i++]=*p++;
            code[i]='\0';
            for(int j=0;j<36;j++){
                if(!strcmp(code,moose[j])){
                    if(j<26)text[n++]=j+'A';
                    else text[n++]=j-26+'0';
                    break;
                }
            }
            while(*p=='/'){flag++;p++;}
            if(flag==3)text[n++]=' ';
            else if(flag==5)text[n++]='.';
            flag=0;
        }
        text[n]='\0';
        printf("%s\n",text);
    }
    return 0;
}
