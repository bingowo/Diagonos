#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ch[36][6];
void make()
{
    strcpy(ch[0],".-");strcpy(ch[1],"-...");strcpy(ch[2],"-.-.");
    strcpy(ch[3],"-..");strcpy(ch[4],".");strcpy(ch[5],"..-.");
    strcpy(ch[6],"--.");strcpy(ch[7],"....");strcpy(ch[8],"..");
    strcpy(ch[9],".---");strcpy(ch[10],"-.-");strcpy(ch[11],".-..");
    strcpy(ch[12],"--");strcpy(ch[13],"-.");strcpy(ch[14],"---");
    strcpy(ch[15],".--.");strcpy(ch[16],"--.-");strcpy(ch[17],".-.");
    strcpy(ch[18],"...");strcpy(ch[19],"-");strcpy(ch[20],"..-");
    strcpy(ch[21],"...-");strcpy(ch[22],".--");strcpy(ch[23],"-..-");
    strcpy(ch[24],"-.--");strcpy(ch[25],"--..");

    strcpy(ch[26],"-----");strcpy(ch[27],".----");strcpy(ch[28],"..---");
    strcpy(ch[29],"...--");strcpy(ch[30],"....-");strcpy(ch[31],".....");
    strcpy(ch[32],"-....");strcpy(ch[33],"--...");strcpy(ch[34],"---..");
    strcpy(ch[35],"----.");
}

int main()
{
    make();
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        char str[1010];
        scanf("%s",str);
        int i=0;
        while(i<strlen(str)){
            char code[6]={0};
            int j=0;
            while(str[i]!='/'&&str[i]!='\0')code[j++]=str[i++];
            if(strlen(code)==5){
                for(int m=0;m<10;m++){
                    if(!strcmp(code,ch[26+m])){
                        printf("%c",'0'+m);
                    }
                }
            }
            else{
                for(int m=0;m<26;m++){
                    if(strlen(code)==strlen(ch[m])){
                        if(!strcmp(code,ch[m])){
                            printf("%c",'A'+m);
                            break;
                        }
                    }
                }
            }
            int copy=i;
            while(str[i]=='/')i++;
            if(i-copy==3)printf(" ");
            else if(i-copy==5)printf(".");
        }
        printf("\n");
    }
    return 0;
}
