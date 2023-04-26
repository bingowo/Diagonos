#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char s[100];//
    while(scanf("f(x)=%s",s)==1){
        char pic[41][41];
        int data[4]={0};
        for(int i=0;i<41;i++){
            for(int j=0;j<41;j++){
                pic[i][j]='.';
            }
        }
        if(strstr(s,"^3")!=NULL){
            char *p=s;
            if(*p=='x')data[3]=1;
            else if(*p=='-'&&*(p+1)=='x')data[3]=-1;
            else{
                sscanf(s,"%d",&data[3]);
            }
        }
        if(strstr(s,"^2")!=NULL){
            char *p=strstr(s,"^2");
            while(*p!='-'&&*p!='+'&&(p-s)>0)p--;
            if(*p=='x')data[2]=1;
            else if(*p=='-'&&*(p+1)=='x')data[2]=-1;
            else{
                sscanf(p,"%d",&data[2]);
            }
        }
        char *p=s+strlen(s)-1;
        if(*p=='x'){
            while(*p!='-'&&*p!='+'&&(p-s)>0)p--;
            if(*p=='x')data[1]=1;
            else if(*p=='-'&&*(p+1)=='x')data[1]=-1;
            else{
                sscanf(p,"%d",&data[1]);
            }
        }
        else if(isdigit(*p)&&(p-s)>=0){
            if((p-s)>0&&*(p-1)=='^');
            else{
                while(*p!='-'&&*p!='+'&&(p-s)>0)p--;
                sscanf(p,"%d",&data[0]);}
            if((p-s)>0&&*(p-1)=='x'){
                p--;
                while(*p!='-'&&*p!='+'&&(p-s)>0)p--;
                if(*p=='x')data[1]=1;
                else if(*p=='-'&&*(p+1)=='x')data[1]=-1;
                else{
                    sscanf(p,"%d",&data[1]);
                }
            }
        }
        for(int i=0;i<41;i++){//x轴
            pic[i][20]='|';
            pic[20][i]='-';
        }
        pic[0][20]='^';pic[20][40]='>';
        pic[20][20]='+';
        int x=0;int y=0;int origin=20;
        while((y=(data[3]*(x*x*x)+data[2]*x*x+data[1]*x+data[0]))<=20&&y>=-20&&x<=20){
            pic[origin-y][x+origin]='*';
            x++;}
        x=0,y=0;
        while((y=(data[3]*(x*x*x)+data[2]*x*x+data[1]*x+data[0]))>=-20&&y<=20&&x>=-20){
            pic[origin-y][x+origin]='*';
            x--;}
        for(int i=0;i<41;i++){
            for(int j=0;j<41;j++){
                putchar(pic[i][j]);
            }
            putchar('\n');
        }
        getchar();
        putchar('\n');
    }
}