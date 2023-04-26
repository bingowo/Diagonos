#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int the(char s[]){
    if(strlen(s)==3){
        if(tolower(s[0])=='t'&&tolower(s[1])=='h'&&tolower(s[2])=='e')return 1;
    }
    return 0;
}
int a(char s[]){
    if(strlen(s)==1){
        if(tolower(s[0])=='a')return 1;
    }
    return 0;
}
int an(char s[]){
    if(strlen(s)==2){
        if(tolower(s[0])=='a'&&tolower(s[1])=='n')return 1;
    }
    return 0;
}
int of(char s[]){
    if(strlen(s)==2){
        if(tolower(s[0])=='o'&&tolower(s[1])=='f')return 1;
    }
    return 0;
}
int rof(char s[]){
    if(strlen(s)==3){
        if(tolower(s[0])=='f'&&tolower(s[1])=='o'&&tolower(s[2])=='r')return 1;
    }
    return 0;
}
int and(char s[]){
    if(strlen(s)==3){
        if(tolower(s[0])=='a'&&tolower(s[1])=='n'&&tolower(s[2])=='d')return 1;
    }
    return 0;
}
int myscm(char s[]){
    if(the(s)||a(s)||an(s)||of(s)||rof(s)||and(s))return 0;
    return 1;
}
int main(){
    int t;scanf("%d",&t);getchar();int cas;
    while(t--){
        int cnt=0;
        char tem[20];
        while(scanf("%s",tem)){
            if(myscm(tem))cnt++;
            if(getchar()=='\n')break;
        }
        printf("case #%d:\n%d\n",cas++,cnt);
    }
}