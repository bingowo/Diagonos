#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trans(int z){
char c[10]="0000000000";
for(int k=9;z;k--){
    c[k]=z%2;
    z=z/2;
}
for(int r=0;r<10;r++)
    printf("%c",c[r]);
}

void trans1(int z){
char c[4]="0000";
for(int k=3;z;k--){
    c[k]=z%2;
    z=z/2;
}
for(int r=0;r<4;r++)
    printf("%c",c[r]);
}

void trans2(int z){
char c[4]="0000000";
for(int k=6;z;k--){
    c[k]=z%2;
    z=z/2;
}
for(int r=0;r<7;r++)
    printf("%c",c[r]);
}


int main(){
    printf("0001");
    char a[500];
    int i=0;
    char b;
    while(scanf("%c",&b)!=EOF){
        a[i]=b;
        i++;
    }
    trans(i+1);
    int x=(i+1)/3;
    int y=(i+1)%3;
    int z;
    for(int j=0;j<x;j++){
        z=(a[3*j]-48)*1000+(a[3*j+1]-48)*100+(a[3*j+2]-48);
        trans(z);
    }
    if(y==1){
        z=a[i]-48;
        trans1(z);
    }
    if(y==2){
        z=a[i]-48+10*(a[i-1]-48);
        trans2(z);
    }
    printf("%c",a[0]);
    return 0;
}
