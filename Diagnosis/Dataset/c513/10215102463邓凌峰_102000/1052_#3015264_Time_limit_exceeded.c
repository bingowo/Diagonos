#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 70000
#define BigNUm 10007
#define N 100000

char zero[6]="ZERO";
char one[6]="ONE";
char two[6]="TWO";
char three[6]="THREE";
char four[6]="FOUR";
char five[6]="FIVE";
char six[6]="SIX";
char seven[6]="SEVEN";
char eight[6]="EIGHT";
char nine[6]="NINE";

int haveIt(char *rest,char *num){
    int formal[strlen(rest)];
    memset(formal,0,sizeof(formal));
    int find=0;
    for(int cnt=0;cnt<strlen(num);cnt++){

        for(int k=0;k<strlen(rest);k++){
            if(num[cnt]==rest[k] && formal[k]==0){
                formal[k]=1;
                find++;
                break;
            }
        }
    }
    if(find!=strlen(num)) return 0;
    return 1;
}

void cutIt(char *rest,char *num){
    int formal[strlen(rest)];
    memset(formal,0,sizeof(formal));
    for(int cnt=0;cnt<strlen(num);cnt++){
        for(int k=0;k<strlen(rest);k++){
            if(num[cnt]==rest[k] && formal[k]==0){
                formal[k]=1;
                break;
            }
        }
    }
    char ans[strlen(rest)];
    memset(ans,0,sizeof(ans));
    int idx=0;
    int len=strlen(rest);
    for(int k=0;k<len;k++){
        if(formal[k]==0){
            ans[idx++]=rest[k];
        }
    }
    memset(rest,0,sizeof(rest));
    strcpy(rest,ans);
}


int findNext(int start,char *rest){
    int ans=-1;
    int have=0;
    switch(start)
    {
        case 0:{
            have=haveIt(rest,zero);
            if(have==1){
                cutIt(rest,zero);
                ans=0;
            }
            break;
        }
        case 1:{
            have=haveIt(rest,one);
            if(have==1){
                cutIt(rest,one);
                ans=1;
            }
            break;
        }
        case 2:{
            have=haveIt(rest,two);
            if(have==1){
                cutIt(rest,two);
                ans=2;
            }
            break;
        }
        case 3:{
            have=haveIt(rest,three);
            if(have==1){
                cutIt(rest,three);
                ans=3;
            }
            break;
        }
        case 4:{
            have=haveIt(rest,four);
            if(have==1){
                cutIt(rest,four);
                ans=4;
            }
            break;
        }
        case 5:{
            have=haveIt(rest,five);
            if(have==1){
                cutIt(rest,five);
                ans=5;
            }
            break;
        }
        case 6:{
            have=haveIt(rest,six);
            if(have==1){
                cutIt(rest,six);
                ans=6;
            }
            break;
        }
        case 7:{
            have=haveIt(rest,seven);
            if(have==1){
                cutIt(rest,seven);
                ans=7;
            }
            break;
        }
        case 8:{
            have=haveIt(rest,eight);
            if(have==1){
                cutIt(rest,eight);
                ans=8;
            }
            break;
        }
        case 9:{
            have=haveIt(rest,nine);
            if(have==1){
                cutIt(rest,nine);
                ans=9;
            }
            break;
        }
    }
    return ans;
}

int main() {
    int T;scanf("%d",&T);
    for(int I=0;I<T;I++){
        char password[21];scanf("%s",password);
        printf("case #%d:\n",I);
        int pass[10]={0};
        int start=0,cnt=0;
        while(strlen(password)!=0){
            int tmp=-1;
            do{
                tmp=findNext(start,password);
                if(tmp!=-1){
                    pass[cnt++]=tmp;
                }
            }while(tmp!=-1);
            start++;
        }
        for(int k=0;k<cnt;k++){
            printf("%d",pass[k]);
        }
        printf("\n");
    }





    return 0;
}
