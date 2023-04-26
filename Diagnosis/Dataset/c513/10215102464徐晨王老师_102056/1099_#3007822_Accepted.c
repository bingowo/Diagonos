#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void Print(char ss[1100])
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
        //printf("%s\n",s);
        printf("case #%d:\n",t);
        int a=0,b=0;
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='/'&&s[i+1]=='/'&&s[i+2]=='/'&&s[i+3]!='/'&&s[i-1]!='/'){
                printf(" ");
                continue;
            }
            else if(s[i]=='/'&&s[i+1]=='/'&&s[i+2]=='/'&&s[i+3]=='/'&&s[i+4]=='/'&&s[i-1]!='/'&&s[i+5]!='/'){
                printf(".");
                continue;
            }
            else if(s[i]=='/'&&s[i+1]=='/'&&s[i+2]=='/'&&s[i+3]=='/'&&s[i+4]=='/'&&s[i+5]=='/'){
                printf(".");
                continue;
            }
            else if(s[i]=='/'&&s[i+1]!='/'){
                a=i;
                for(int j=i+1;j<strlen(s);j++){
                    if(s[j]=='/'){b=j;break;}
                }
                char ss[1100]={'\0'};
                for(int k=a+1;k<=b-1;k++){
                    ss[k-a-1]=s[k];
                }
                //printf("%s %d %d\n",ss,a,b);
                Print(ss);
            }
        }
        printf("\n");
    }
}
