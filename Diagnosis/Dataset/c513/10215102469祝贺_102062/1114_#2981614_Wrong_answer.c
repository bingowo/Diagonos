#include<stdio.h>
#include<string.h>
#include<ctype.h>
char t[41][41];//21

int readnum(char* s,int p){
    if(s[p]=='-')return -1;
    else if(p<0 || s[p]=='+' || s[p]=='=')return 1;
    else{
        int ret=0;
        for(int i=0;p>=0 && isdigit(s[p]);p--,i++){
            int tmp=(s[p]-'0')*(i==1?10:1);
            ret+=tmp*(i==2?100:1);
        }
        if(p>=0 && s[p]=='-')ret*=-1;
       return ret;
    }
}
void get(char* s,int* num){
    int p=0;
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
    }
    for(int p=strlen(s)-1;;p--){
        if(s[p]=='x') break;
        else if(s[p]=='+' || s[p]=='-' || s[p]=='='){
            num[0]=readnum(s,strlen(s)-1);
            break;
        }
    }
}
int main(){
    char s[100];scanf("%s",s);
    int num[3]={0};
    int a,b,c,d;
    get(s,num);
    int tag=0;
    if(num[0]==0 && num[1]==0);
    else if(num[0]==0){
        a=1;b=0;d=num[1];c=num[2];
        tag=1;
    }
    else{
        for(a=1;a<=100;a++){
            for(b=-200;b<=200;b++){
                if(b==0)continue;
                if(num[2]%a==0 && num[0]%b==0){
                    if(b*num[2]/a+a*num[0]/b==num[1]){
                        tag=1;
                        c=num[2]/a;d=num[0]/b;
                        if(a==c && b>d){
                            int tmp=d;d=b;b=tmp;
                        }
                        break;
                    }
                }
            }
            if(tag==1)break;
        }
    }


    if(tag==1)printf("%d %d %d %d",a,b,c,d);
    else printf("No Answer!");
    return 0;
}
