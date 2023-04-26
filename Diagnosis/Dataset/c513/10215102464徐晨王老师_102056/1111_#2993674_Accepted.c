#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int f(int x,int pp[4]){
    int num1=0;
    for(int i=0;i<4;i++){
        int num2=1;
        for(int j=0;j<i;j++){
            num2=num2*x;
        }
        num1=num1+pp[i]*num2;
    }
    return num1;
}


int main(){
    char s[20];
    while(scanf("%s",s)!=EOF){
    int p[4]={0};
    int x=0;
    char s1[20]={'\0'};
    while(s[x]!='=')x++;
    x++;
    if(s[x]=='-'||s[x]=='+'){
        int y=0;
        while(x<strlen(s)){
            s1[y]=s[x];
            y++;
            x++;
        }
    }
    else{
        s1[0]='+';
        int y=1;
        while(x<strlen(s)){
            s1[y]=s[x];
            y++;
            x++;
        }
    }
    for(int i=0;i<strlen(s1);i++){
        if(s1[i]=='+'||s1[i]=='-'){
            int flag=1;
            if(s1[i]=='+'){flag=1;}
            else if(s1[i]=='-'){flag=-1;}
            int sum=0;
            int j=i+1;
            while(isdigit(s1[j])){
                sum=sum*10+s1[j]-48;
                j++;
            }
            sum=sum*flag;
            if(sum==0&&s1[j-1]!='0')sum=flag;
            if(s1[j]=='x'){
                if(s1[j+2]=='3'){
                    p[3]=sum;
                }
                else if(s1[j+2]=='2'){
                    p[2]=sum;
                }
                else{
                    p[1]=sum;
                }
            }
            else{
                p[0]=sum;
            }
        }
    }
    //printf("%d %d %d %d\n",p[3],p[2],p[1],p[0]);

    char pic[41][42];
    for(int i=0;i<41;i++){
        for(int j=0;j<41;j++){
            pic[i][j]='.';
        }
        pic[i][41]='\0';
    }
    for(int i=0;i<41;i++){
        pic[i][20]='|';
    }
    for(int i=0;i<41;i++){
        pic[20][i]='-';
    }
    pic[0][20]='^';
    pic[20][40]='>';
    pic[20][20]='+';
    for(int i=0;i<41;i++){
        int j=f((i-20),p);
        if((20-j)>=0&&(20-j)<=40){
            pic[20-j][i]='*';
        }
    }
    for(int i=0;i<41;i++){
        printf("%s\n",pic[i]);
    }
    printf("\n");
    }
}
