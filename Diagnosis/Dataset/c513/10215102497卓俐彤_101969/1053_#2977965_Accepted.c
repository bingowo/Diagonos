#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(){
    int h=0,m=0,s=0;
    char str[3000];
    while(scanf("%s",str)&&strcmp(str,"END")){
        char sentence[50][50];
        char *p=str-1;
        int index=0,temp=0;
        while(*++p){
            if(*p==','){
                sentence[index++][temp]='\0';
                temp=0;
            }else{
                sentence[index][temp++]=*p;
            }
        }
        sentence[index][0]='\0';
        p=str+1;
        if(index==12&&!strcmp(sentence[2],"A")&&!strcmp(sentence[0],"$GPRMC")){
            int number=0,code=0;
            number=(int)*p++;
            while(*p!='*'){
                number=number^*p;
                p++;
            }
            p++;
            while(*p){
                code=code*16+((isalpha(*p)?(*p-'A'+10):(*p-'0')));
                p++;
            }
            if(number==(code%65535)){
                h=(sentence[1][0]-'0')*10+(sentence[1][1]-'0');
                h=(h+8)%24;
                m=(sentence[1][2]-'0')*10+(sentence[1][3]-'0');
                s=(sentence[1][4]-'0')*10+(sentence[1][5]-'0');
            }
        }
    }
    printf("%02d:%02d:%02d\n",h,m,s);
    return 0;
}
