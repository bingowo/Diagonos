#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void minus(char* a1,char* b1,int c){
int a[strlen(a1)+1],b[strlen(a1)+1];
a[0]=0;
for(int i=strlen(a1);i>=1;i--){
    a[i]=a1[i-1]-48;
}
b[0]=0;
for(int i=1;i<(strlen(a1)-strlen(b1)+1);i++){
    b[i]=0;
}

for(int i=strlen(a1)-strlen(b1)+1;i<strlen(a1)+1;i++){
    b[i]=b1[i-strlen(a1)+strlen(b1)-1]-48;
}

for(int i=strlen(a1);i>=0;i--){
a[i]=a[i]-b[i];
if(a[i]<0){
    a[i]=a[i]+10;
    a[i-1]=a[i-1]-1;
    }
}
int j=0;
for(;j<=strlen(a1);j++){
    if(a[j]!=0)break;
}
if(j==strlen(a1)+1)printf("0");
if(c==-1)printf("-");
for(;j<=strlen(a1);j++){
    printf("%d",a[j]);
}
printf("\n");
}


int main(){
    char A[1000];
    char B[1000];
    while(scanf("%s%s",A,B)!=EOF){
            if(strlen(A)>strlen(B)){minus(A,B,1);}
            if(strlen(A)<strlen(B)){minus(B,A,-1);}
            if(strlen(A)==strlen(B)){
            if(strcmp(A,B)==0)printf("0\n");
            if(strcmp(A,B)==1){minus(A,B,1);}
            if(strcmp(B,A)==1) {minus(B,A,-1);}

        }
    }
    return 0;
}
