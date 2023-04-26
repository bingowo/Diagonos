#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef long long ll;

int ma,mb,c,w,n;
int r[20];
char s[50];
char tc[]="0123456789ABCDEF";

int Ti(char c){
    if(c>='0'&&c<='9')
        return c-'0';
    else if(c>='A'&&c<='F')
        return 10+c-'A';
    else
        return10+c-'a';
}

void GetC(){
    w=1;
    n=strlen(s);
    for(int i=n-1;i>=0;i--){
        c+=w*Ti(s[i]);
        w*=ma;
    }
}

void GetR(){
    n=0;
    while(c){
        r[n]=c%mb;
        c/=mb;
        n++;
    }
}

void Print(){
    if(!n){
        printf("0\n");
        return;
    }
    for(int i=n-1;i>=0;i--){
        printf("%c",tc[r[i]]);
    }
    printf("\n");
}

int main(){
    scanf("%d%s%d",&ma,s,&mb);
    GetC();
    GetR();
    Print();

    return 0;
}

