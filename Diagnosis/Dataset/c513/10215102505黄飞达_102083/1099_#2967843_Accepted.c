#include<stdio.h>
#include<string.h>

char morse[40][6]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
void table(char ch[]){
    for (int i=0; i<36; i++) {
        if (strcmp(ch, morse[i])==0){
            if (i<26) printf("%c",'A'+i);
            else printf("%d", i-26);
            break;
        }        
    }
    if (strcmp(ch, "///")==0) printf(" ");
    else if (strcmp(ch, "/////")==0) printf(".");
    return;
}
int main(){
    int T;
    scanf("%d ", &T);
    for (int t=0; t<T; t++){
        printf("case #%d:\n", t);
        char s[1005]={0};
        gets(s);
        char ch[6]={0};
        int slen=strlen(s);
        for (int i=0,j=0; i<slen; i++){
            ch[j++]=s[i];
            if (i+1>=slen) table(ch);
            else if (i+1<slen&&s[i+1]=='/'){
                table(ch);
                memset(ch, 0, 6);
                i++;j=0;
                while(s[i]=='/') ch[j++]=s[i++];
                table(ch);
                i--;
                memset(ch, 0, 6);
                j=0;
            }
        }
        printf("\n");
    }
    return 0;
}