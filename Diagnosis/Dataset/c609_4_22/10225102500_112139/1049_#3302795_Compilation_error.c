#include <stdio.h>
#include <stdlib.h>
#include<string.h>
    void minus(int* e1,int* e2){
    for(int j=0;j++;j<500){
    e1[j]=e1[j]-e2[j];
    }
    for(int j=0;j++;j<499){
    if(e1[j]<0){
    e1[j]=e1[j]+10;
    e1[j+1]--;
    }

    }
    void print(int *e){
    int k;
    for(k=0;k++;k<500){
    if(e[k]!=0) break;
    }
    for(;k++;k<500){
    printf("%d",e[k]);
    }
    printf("\n");


    }


    }
  int main(){
  while(1){
  char a[500]={"0"};
  char b[500]={"0"};
  int c[500]={0};
  int d[500]={0};
    if(scanf("%s",a)!=EOF){
    scanf("%s",b);
    for(int i=0;i<strlen(a);i++){
    c[i]=a[strlen(a)-i]-'0';
    }
    for(int i=0;i<strlen(b);i++){
    d[i]=b[strlen(b)-i]-'0';
    }
    if(strlen(a)>strlen(b)){
    minus(c,d);
    print(c);
    }else if(strlen(a)<strlen(b)){
    minius(d,c);
    print(d);
    }else{
    int flag=0;
    for(int i=0;i<500;i++){
    if(a[i]>b[i]) flag=1;
    if(a[i]<b[i]) flag=-1;


    }
    if(flag==1){
        minus(c,d);
    print(c);
    }else if(flag==-1){
    minius(d,c);
    print(d);

    }else if(flag==0){
    printf("0\n");
    }


    }else {
    break;
    }

  



  }
