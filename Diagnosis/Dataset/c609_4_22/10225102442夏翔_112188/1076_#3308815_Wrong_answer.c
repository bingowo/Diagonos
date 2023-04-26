//1076
#include<stdio.h>
#include<string.h>
char character[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
char *codes[] = {".-","-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-."\
, "...", "-", "..-", "...--", ".--", "-..-", "-.--", "--..", "-----", ".----","..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
void print(char *s){ //Morse code To code
    for(int i=0; i<36; i ++){
        if(strcmp(s, codes[i]) == 0){
            printf("%c", character[i]);
            return;
        }
    }
}
int main(){
    int T, ret, len1, len2;
    char s[1010], code[5];
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        printf("case #%d:\n", t);
        scanf("%s", s);
        len1 = strlen(s);
        len2 = 0; ret = 0;
        for(int i=0; i<len1; i ++){
            if(ret == 5){
                printf(".");
                ret = 0;
            }
            if(s[i] != '/'){
                if(ret == 3) printf(" ");
                code[len2++] = s[i];
                ret = 0;
            }else{
                if(ret==0){
                    code[len2] = '\0';
                    print(code);
                    len2 = 0;
                }
                ret ++;
            }
        }
        if(len2 != 0){
            code[len2] = '\0';
            print(code);
        }
        if(ret == 3) printf(" ");
        if(ret == 5) printf(".");
        printf("\n");
    }
    return 0;
}