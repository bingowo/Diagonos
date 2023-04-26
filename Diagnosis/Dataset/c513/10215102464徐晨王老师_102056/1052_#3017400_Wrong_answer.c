#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void pd(char s[30],char p[10][6],int pp[10],int d){
    for(int i=0;i<10;i++){
        int flag1=1;
        for(int j=0;j<strlen(p[i]);j++){
            int flag2=0;
            for(int k=0;k<strlen(s);k++){
                if(s[k]==p[i][j])flag2=1;
            }
            if(flag2==0)flag1=0;
        }
        if(flag1==1){
            pp[i]=pp[i]+1;
            for(int j=0;j<strlen(p[i]);j++){
                for(int k=0;k<strlen(s);k++){
                    if(s[k]==p[i][j]){s[k]='-';break;}
                }
            }
        }
    }
    int len=3*(pp[1]+pp[2]+pp[6])+4*(pp[0]+pp[4]+pp[5]+pp[9])+5*(pp[3]+pp[7]+pp[8]);
    if(len==d)return;
    else {pd(s,p,pp,len);
    //printf("%d %s\n",len,s);
    }
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
        pd(s,p,pp,0);
//        for(int i=0;i<10;i++){
//            printf("%d",pp[i]);
//        }
//        printf("%d",pp[4]);
        for(int i=0;i<10;i++){
            for(int j=0;j<pp[i];j++){
                printf("%c",i+48);
            }
        }
        printf("\n");
    }
}
