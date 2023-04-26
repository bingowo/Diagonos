#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmpword(int num,char* word){
    if(!strcmp(word,"the"))num--;
    else if(!strcmp(word,"a"))num--;
    else if(!strcmp(word,"an"))num--;
    else if(!strcmp(word,"of"))num--;
    else if(!strcmp(word,"for"))num--;
    else if(!strcmp(word,"and"))num--;
    return num;
}

int main(){
    int T;
    scanf("%d",&T);
    char c;
    while(c=getchar()!='\n');
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        int num=0,i=0;
        char word[101];
        int flag=0;
        while((c=getchar())!='\n'){
            if(isalpha(c)){
                if(!flag){
                    flag=1;
                    num++;
                }
                if(c>='A'&&c<='Z')c=c-'A'+'a';
                word[i++]=c;
            }else if(c==' '){
                flag=0;
                word[i]='\0';
                num=cmpword(num,word);
                i=0;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
