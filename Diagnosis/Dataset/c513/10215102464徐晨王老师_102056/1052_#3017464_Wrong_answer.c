#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int flag=1;
int pd(char s[30],char p[10][6],int pp[10],int d){
    if(d==0){flag=0;return 1;}
    else if(d<0)return 0;
    else{
    for(int i=9;i>=0;i--){
        char ss[30];
        strcpy(ss,s);
        int flag1=1;
        for(int j=0;j<strlen(p[i]);j++){
            int flag2=0;
            for(int k=0;k<strlen(ss);k++){
                if(ss[k]==p[i][j])flag2=1;
            }
            if(flag2==0)flag1=0;
        }
        if(flag1==1&&flag==1){
            for(int j=0;j<strlen(p[i]);j++){
                for(int k=0;k<strlen(s);k++){
                    if(ss[k]==p[i][j]){ss[k]='-';break;}
                }
            }
            if(pd(ss,p,pp,d-strlen(p[i])))pp[i]=pp[i]+1;
            else pp[i]=pp[i];
        }
    }
    }
    //int len=3*(pp[1]+pp[2]+pp[6])+4*(pp[0]+pp[4]+pp[5]+pp[9])+5*(pp[3]+pp[7]+pp[8]);

//    else {
//            printf("%d %s\n",len,s);
//            pd(s,p,pp,len);}
}

int main(){
    char p[10][6]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        char s[30]={'\0'};
        scanf("%s",s);
        int pp[10]={0};
        //int m=pd(s,p,pp,strlen(s));
//        for(int i=0;i<10;i++){
//            printf("%d",pp[i]);
//        }
//        printf("%d",pp[4]);
        if(pd(s,p,pp,strlen(s))){
        for(int i=0;i<10;i++){
            for(int j=0;j<pp[i];j++){
                printf("%c",i+48);
            }
        }
        }
        printf("\n");
    }
}
