#include<stdio.h>
#include<string.h>
#include<ctype.h>
char t[41][41];//21

int readnum(char* s,int p){
    if(s[p]=='-')return -1;
    else if(s[p]=='+' || s[p]=='=')return 1;
    else{
        int ret=0;
        for(int i=0;p>=0 && isdigit(s[p]);p--,i++){
            ret+=(s[p]-'0')*(i==0?1:10);
        }
        if(s[p]=='-')ret*=-1;
       return ret;
    }
}
void get(char* s,int* num){
    int p=3,findtag=0;
    while(p<strlen(s)){
        for(;p<strlen(s) && s[p]!='x';p++);
        if(p<strlen(s) && s[p]=='x'){
            if(p+1<strlen(s) && s[p+1]=='^'){
                num[s[p+2]-'0']=readnum(s,p-1);
            }
            else if(p+1 >= strlen(s) || s[p+1]!='^'){
                num[1]=readnum(s,p-1);
            }
            p++;
        }

        for(int p=strlen(s)-1;;p--){
            if(s[p]=='x') break;
            else if(s[p]=='+' || s[p]=='-' || s[p]=='='){
                num[0]=readnum(s,strlen(s)-1);
                break;
            }
        }

    }
}
int main(){
    char s[100];
    while(scanf("%s",s)!=EOF){
        for(int i=0;i<41;i++){
            for(int j=0;j<41;j++){
                if(i==20 && j==20) t[i][j]='+';
                else if(i==20 &&j==40)t[i][j]='>';
                else if(i==0 && j==20)t[i][j]='^' ;
                else if(i==20) t[i][j]='-';
                else if(j==20)t[i][j]='|';
                else t[i][j]='.';
            }
        }

        int num[4]={0};
        get(s,num);

        for(int i=-20;i<=20;i++){
            int p=(num[3]*i*i*i+num[2]*i*i + num[1]*i + num[0]);
            if(p<=20 && p>=-20){
                t[20-p][20-i]='*';
            }
        }

        for(int i=0;i<41;i++){
            for(int j=0;j<41;j++){
                printf("%c",t[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
