#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void Print(char ss[])
{
if(strcmp(ss, ".-") == 0){printf("A");}
else if(strcmp(ss, "-...") == 0){printf("B");}
else if(strcmp(ss, "-.-.") == 0){printf("C"); }
else if(strcmp(ss, "-..") == 0){printf("D"); }
else if(strcmp(ss, ".") == 0){printf("E");}
else if(strcmp(ss, "..-.") == 0){printf("F");}
else if(strcmp(ss, "--.") == 0){printf("G");}
else if(strcmp(ss, "....") == 0){printf("H");}
else if(strcmp(ss, "..") == 0){printf("I");}
else if(strcmp(ss, ".---") == 0){printf("J");}
else if(strcmp(ss, "-.-") == 0){printf("K");}
else if(strcmp(ss, ".-..") == 0){printf("L");}
else if(strcmp(ss, "--") == 0){printf("M");}
else if(strcmp(ss, "-.") == 0){printf("N");}
else if(strcmp(ss, "---") == 0){printf("O");}
else if(strcmp(ss, ".--.") == 0){printf("P");}
else if(strcmp(ss, "--.-") == 0){printf("Q");}
else if(strcmp(ss, ".-.") == 0){printf("R");}
else if(strcmp(ss, "...") == 0){printf("S");}
else if(strcmp(ss, "-") == 0){printf("T");}
else if(strcmp(ss, "..-") == 0){printf("U");}
else if(strcmp(ss, "...-") == 0){printf("V");}
else if(strcmp(ss, ".--") == 0){printf("W");}
else if(strcmp(ss, "-..-") == 0){printf("X");}
else if(strcmp(ss, "-.--") == 0){printf("Y");}
else if(strcmp(ss, "--..") == 0){printf("Z");}
else if(strcmp(ss, "-----") == 0){printf("0");}
else if(strcmp(ss, ".----") == 0){printf("1");}
else if(strcmp(ss, "..---") == 0){printf("2");}
else if(strcmp(ss, "...--") == 0){printf("3");}
else if(strcmp(ss, "....-") == 0){printf("4");}
else if(strcmp(ss, ".....") == 0){printf("5");}
else if(strcmp(ss, "-....") == 0){printf("6");}
else if(strcmp(ss, "--...") == 0){printf("7");}
else if(strcmp(ss, "---..") == 0){printf("8");}
else if(strcmp(ss, "----.") == 0){printf("9");}
else if(strcmp(ss, "/") == 0){printf(" ");}
else if(strcmp(ss, "///") == 0){printf(".");}
}
int main(){
    int T;
    scanf("%d",&T);
    char c=getchar();
    for(int t=0;t<T;t++){
        char s[1100]={'\0'};
        gets(s);
        for(int i=strlen(s)-1;i>=0;i--){
            s[i+1]=s[i];
        }
        s[0]='/';
        s[strlen(s)]='/';
        printf("case #%d:\n",t);
        int a=0,b=0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='/'){
                a=i;
                for(int j=i+1;j<strlen(s);j++){
                    if(s[j]=='/' && s[j+1]!='/')b=j;
                }
                char ss[1100]={'\0'};
                for(int k=a+1;k<=b-1;k++){
                    ss[k-a]=s[k];
                }
                Print(ss);
            }
            printf("\n");
        }
    }
}
