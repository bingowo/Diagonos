#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void add(char* ret, int* p, char* str){
    if(strcmp(str,".-")==0){ret[(*p)++]='A';}
    else if(strcmp(str,"-...")==0){ret[(*p)++]='B';}
    else if(strcmp(str,"-.-.")==0){ret[(*p)++]='C';}
    else if(strcmp(str,"-..")==0){ret[(*p)++]='D';}
    else if(strcmp(str,".")==0){ret[(*p)++]='E';}
    else if(strcmp(str,"..-.")==0){ret[(*p)++]='F';}
    else if(strcmp(str,"--.")==0){ret[(*p)++]='G';}
    else if(strcmp(str,"....")==0){ret[(*p)++]='H';}
    else if(strcmp(str,"..")==0){ret[(*p)++]='I';}
    else if(strcmp(str,".---")==0){ret[(*p)++]='J';}
    else if(strcmp(str,"-.-")==0){ret[(*p)++]='K';}
    else if(strcmp(str,".-..")==0){ret[(*p)++]='L';}
    else if(strcmp(str,"--")==0){ret[(*p)++]='M';}
    else if(strcmp(str,"-.")==0){ret[(*p)++]='N';}
    else if(strcmp(str,"---")==0){ret[(*p)++]='O';}
    else if(strcmp(str,".--.")==0){ret[(*p)++]='P';}
    else if(strcmp(str,"--.-")==0){ret[(*p)++]='Q';}
    else if(strcmp(str,".-.")==0){ret[(*p)++]='R';}
    else if(strcmp(str,"...")==0){ret[(*p)++]='S';}
    else if(strcmp(str,"-")==0){ret[(*p)++]='T';}
    else if(strcmp(str,"..-")==0){ret[(*p)++]='U';}
    else if(strcmp(str,"...-")==0){ret[(*p)++]='V';}
    else if(strcmp(str,".--")==0){ret[(*p)++]='W';}
    else if(strcmp(str,"-..-")==0){ret[(*p)++]='X';}
    else if(strcmp(str,"-.--")==0){ret[(*p)++]='Y';}
    else if(strcmp(str,"--..")==0){ret[(*p)++]='Z';}
    else if(strcmp(str,"-----")==0){ret[(*p)++]='0';}
    else if(strcmp(str,".----")==0){ret[(*p)++]='1';}
    else if(strcmp(str,"..---")==0){ret[(*p)++]='2';}
    else if(strcmp(str,"...--")==0){ret[(*p)++]='3';}
    else if(strcmp(str,"....-")==0){ret[(*p)++]='4';}
    else if(strcmp(str,".....")==0){ret[(*p)++]='5';}
    else if(strcmp(str,"-....")==0){ret[(*p)++]='6';}
    else if(strcmp(str,"--...")==0){ret[(*p)++]='7';}
    else if(strcmp(str,"---..")==0){ret[(*p)++]='8';}
    else if(strcmp(str,"----.")==0){ret[(*p)++]='9';}
    else if(strcmp(str,"///")==0){ret[(*p)++]=' ';}
    else if(strcmp(str,"/////")==0){ret[(*p)++]='.';}
}
int main(){
   int pro;scanf("%d",&pro);
   for(int index=0;index<pro;index++){
        char s[1025];scanf("%s",s);
        char ret[1025]={0};int p=0;
        char sub[20];
        int begin=0,end=0;
        for(;end<=strlen(s);end++){
            if((end==strlen(s)) || (s[begin]=='/' && s[end]!='/') || (s[begin]!='/' && s[end]=='/')){
                strncpy(sub,s+begin,end-begin);
                sub[end-begin]=0;
                add(ret,&p,sub);
                begin=end;
            }
        }
        ret[p]=0;
        printf("case #%d:\n",index);
        printf("%s\n",ret);
   }
}
