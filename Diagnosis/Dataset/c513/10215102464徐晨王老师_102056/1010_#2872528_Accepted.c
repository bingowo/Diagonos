#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trans(int z){
char c[10]="0000000000";
int k;
for(k=9;z!=0;k--){
    c[k]=z%2;
    z=z/2;
}
for(int s=0;s<k+1;s++){
    printf("%c",c[s]);
}
for(int r=k+1;r<10;r++)
    printf("%c",c[r]+48);
}

void trans1(int z){
char c[4]="0000";
int k;
for(k=3;z;k--){
    c[k]=z%2;
    z=z/2;
}
for(int s=0;s<k+1;s++){
    printf("%c",c[s]);
}
for(int r=k+1;r<4;r++)
    printf("%c",c[r]+48);
}

void trans2(int z){
char c[8]="0000000";
int k;
for(k=6;z;k--){
    c[k]=z%2;
    z=z/2;
}
for(int s=0;s<k+1;s++){
    printf("%c",c[s]);
}
for(int r=k+1;r<7;r++)
    printf("%c",c[r]+48);
}


int main(){
    char a[500];
    int i=0;
    char b;
    while(scanf("%c",&b)!=EOF){
        a[i]=b;
        i++;
    }
    //printf("\n%d\n",i-1);
    printf("0001");
    trans(i-1);
    int x=(i-1)/3;
    int y=(i-1)%3;
    int z;
    for(int j=0;j<x;j++){
        z=(a[3*j]-48)*100+(a[3*j+1]-48)*10+(a[3*j+2]-48);
        //printf("\n%d\n",z);
        trans(z);
    }
    if(y==1){
        z=a[i-2]-48;
        //printf("\n%d\n",a[i-1]);
        trans1(z);
    }
    if(y==2){
        z=a[i-2]-48+10*(a[i-3]-48);
        //printf("%d\n",z);
        trans2(z);
    }
    //printf("%c",a[0]);
    return 0;
}
