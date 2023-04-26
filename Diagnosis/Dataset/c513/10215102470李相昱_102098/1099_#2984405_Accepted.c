#include <stdio.h>
#include <string.h>
typedef struct {
    char s[6];
    char c;
}str;
int main() {
    str a[36]={{"-----",'0'},{".----",'1'},{"..---",'2'},{"...--",'3'},
               {"....-",'4'},{".....",'5'},{"-....",'6'},{"--...",'7'},
               {"---..",'8'},{"----.",'9'},{".-",'A'},
               {"-...",'B'},{"-.-.",'C'},{"-..",'D'},
               {".",'E'},{"..-.",'F'},{"--.",'G'},
               {"....",'H'},{"..",'I'},{".---",'J'},
               {"-.-",'K'},{".-..",'L'},{"--",'M'},
               {"-.",'N'},{"---",'O'},{".--.",'P'},
               {"--.-",'Q'},{".-.",'R'},{"...",'S'},
               {"-",'T'},{"..-",'U'},{"...-",'V'},{".--",'W'},
               {"-..-",'X'},{"-.--",'Y'},{"--..",'Z'}};
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char b[1001];
        scanf("%s",b);
        printf("case #%d:\n",i);
        int len= strlen(b),start=0,len1,cnt=0;
        char str1[6]={0};
        int j=0;
        for(;j<len;j++){
            if(b[j]=='/'){
                if(cnt==0){
                    len1 = j-start;
                    strncpy(str1,b+start,len1);
                    str1[len1]=0;
                    for(int p=0;p<36;p++){
                        if(strcmp(str1,a[p].s)==0){
                            printf("%c",a[p].c);
                            break;
                        }
                    }
                }
                start=j+1;
                cnt++;
            }else{
                if(cnt==3){
                    printf(" ");
                }if(cnt==5){
                    printf(".");
                }if(cnt){
                    cnt=0;
                }
            }
        }
        if(cnt==3){
            printf(" ");
        }if(cnt==5){
            printf(".");
        }
        if(cnt==0){
            len1 = j-start;
            strncpy(str1,b+start,len1);
            str1[len1]=0;
            for(int p=0;p<36;p++){
                if(strcmp(str1,a[p].s)==0){
                    printf("%c",a[p].c);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
