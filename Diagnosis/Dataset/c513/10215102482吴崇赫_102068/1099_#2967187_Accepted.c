#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1005

char* Morse(char* s)
{
    char* ret=(char*)malloc(3);
    ret[0]=ret[1]=ret[2]=0;
    if(strcmp(s,".-")==0)strcpy(ret,"A");
    if(strcmp(s,"-...")==0)strcpy(ret,"B");
    if(strcmp(s,"-.-.")==0)strcpy(ret,"C");
    if(strcmp(s,"-..")==0)strcpy(ret,"D");
    if(strcmp(s,".")==0)strcpy(ret,"E");
    if(strcmp(s,"..-.")==0)strcpy(ret,"F");
    if(strcmp(s,"--.")==0)strcpy(ret,"G");
    if(strcmp(s,"....")==0)strcpy(ret,"H");
    if(strcmp(s,"..")==0)strcpy(ret,"I");
    if(strcmp(s,".---")==0)strcpy(ret,"J");
    if(strcmp(s,"-.-")==0)strcpy(ret,"K");
    if(strcmp(s,".-..")==0)strcpy(ret,"L");
    if(strcmp(s,"--")==0)strcpy(ret,"M");
    if(strcmp(s,"-.")==0)strcpy(ret,"N");
    if(strcmp(s,"---")==0)strcpy(ret,"O");
    if(strcmp(s,".--.")==0)strcpy(ret,"P");
    if(strcmp(s,"--.-")==0)strcpy(ret,"Q");
    if(strcmp(s,".-.")==0)strcpy(ret,"R");
    if(strcmp(s,"...")==0)strcpy(ret,"S");
    if(strcmp(s,"-")==0)strcpy(ret,"T");
    if(strcmp(s,"..-")==0)strcpy(ret,"U");
    if(strcmp(s,"...-")==0)strcpy(ret,"V");
    if(strcmp(s,".--")==0)strcpy(ret,"W");
    if(strcmp(s,"-..-")==0)strcpy(ret,"X");
    if(strcmp(s,"-.--")==0)strcpy(ret,"Y");
    if(strcmp(s,"--..")==0)strcpy(ret,"Z");
    if(strcmp(s,"-----")==0)strcpy(ret,"0");
    if(strcmp(s,".----")==0)strcpy(ret,"1");
    if(strcmp(s,"..---")==0)strcpy(ret,"2");
    if(strcmp(s,"...--")==0)strcpy(ret,"3");
    if(strcmp(s,"....-")==0)strcpy(ret,"4");
    if(strcmp(s,".....")==0)strcpy(ret,"5");
    if(strcmp(s,"-....")==0)strcpy(ret,"6");
    if(strcmp(s,"--...")==0)strcpy(ret,"7");
    if(strcmp(s,"---..")==0)strcpy(ret,"8");
    if(strcmp(s,"----.")==0)strcpy(ret,"9");
    if(strcmp(s,"/")==0)strcpy(ret," ");
    if(strcmp(s,"///")==0)strcpy(ret,".");
    return ret;
}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        char input[N]={0};
        scanf("%s",input);
        char temp[N][7];char ret[N][7];
        for(int i=0;i<N;++i){
            for(int j=0;j<7;++j)temp[i][j]=ret[i][j]=0;
        }
        int pti=0,ptj=0;
        for(int i=0;i<strlen(input);){
            //printf("%c\n",input[i]);
            if(input[i]!='/'){
                temp[pti][ptj++]=input[i++];
            }
            else{
                int sign=i,cnt=0;
                while(input[sign++]=='/')++cnt;
                //printf("%d\n",cnt);
                if(cnt==1){
                    ++pti;ptj=0;++i;
                }
                if(cnt==3){
                    strcpy(temp[++pti],"/");
                    ++pti;i+=3;ptj=0;
                }
                if(cnt==5){
                    strcpy(temp[++pti],"///");
                    ++pti;i+=5;ptj=0;
                }
            }
        }
        printf("case #%d:\n",x);
        for(int i=0;i<=pti;++i){
            printf("%s",Morse(temp[i]));
        }
        printf("\n");x++;
    }
    return 0;
}
